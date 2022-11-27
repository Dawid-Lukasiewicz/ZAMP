#include "ProgramHandler.hh"

ProgramHandler::ProgramHandler()
{
    int Socket;
    OpenConnection(Socket);

    _GuardSocket = make_shared<GuardedSocket>(Socket);
}

ProgramHandler::~ProgramHandler()
{
    Send(_GuardSocket->GetSocket(),"Close\n");
    close(_GuardSocket->GetSocket());
}

void ProgramHandler::loadConfig()
{
    std::cout << "Reading XML file..." << std::endl;
    if (!ReadXMLFile("config/config.xml", _Config))
        exit(-1);
}

void ProgramHandler::printConfig()
{
    for (const ObjectData & obj : _Config.getObjs())
    {
        obj.printData();
    }
}

void ProgramHandler::loadScene()
{
    for(const ObjectData &obj : _Config.getObjs())
    {
        shared_ptr<MobileObj> mobObj = make_shared<MobileObj>();
        mobObj->SetName(obj.Name.c_str());
        mobObj->SetPosition_m(obj.Trans_m);
        mobObj->SetAng_Pitch_deg(obj.RotXYZ_deg[0]);
        mobObj->SetAng_Yaw_deg(obj.RotXYZ_deg[1]);
        mobObj->SetAng_Roll_deg(obj.RotXYZ_deg[2]);
        /* >>>>>>>>>>> Write more code [Probably in MobileObj class] <<<<<<<<<<<< */
        mobObj->Set_Shift(obj.Shift);
        mobObj->Set_RGB(obj.RGB);
        mobObj->Set_Scale(obj.Scale);

        _Scene.AddMobileObj(mobObj);
    }
}

void ProgramHandler::printScene()
{
    shared_ptr<MobileObj> pMobiles;
    for (const ObjectData &obj : _Config.getObjs())
    {
        pMobiles = _Scene.FindMobileObj(obj.Name);
        cout
        << "Mobile obj name: " << pMobiles->GetName() << "\n"
        << "Mobile obj position: " << pMobiles->GetPositoin_m() << "\n"
        << "Mobile obj shift: " << pMobiles->Get_Shift() << "\n"
        << "Mobile obj RGB: " << pMobiles->Get_RGB() << "\n"
        << "Mobile obj scale: " << pMobiles->Get_Scale() << "\n"

        << endl;
    }
}

void ProgramHandler::LoadLibs()
{
    std::cout << "Done...\nPrinting lib names...\n" << std::endl;
    for (const auto &libName : _Config.getLibs())
    {
        std::cout << libName << std::endl;
        _Libs.AddLib(libName);
    }
    
}

void ProgramHandler::avalaibleSyntax()
{
    for (const auto &lib : _Libs)
    {
        std::cout << lib.first  << std::endl;
        lib.second->getCmd()->PrintSyntax();
    }
}

void ProgramHandler::parseCmds(string cmdFile)
{
    std::stringstream cmdStream;
    ExecPreprocesor(cmdFile.c_str(), cmdStream);

    while (!cmdStream.eof())
    {
        std::string name;
        cmdStream >> name;
        if (name.length() > 1)
        {
            _Cmds.push_back(_Libs[name]->getCmd());
            _Cmds.back()->ReadParams(cmdStream);
        }

    }
}

void ProgramHandler::printCmds()
{
    for (Interp4Command *cmd : _Cmds )
    {
        cmd->PrintCmd();
    } 
}

int ProgramHandler::createOnServer()
{
    std::stringstream sConfigCmds;
    sConfigCmds << "Clear\n";
    for (auto it = _Scene.GetMobileObjs().begin(); it !=  _Scene.GetMobileObjs().end(); ++it)
    {
        sConfigCmds << "AddObj "
        << "Name=" << it->second->GetName()
        << " RGB=" << it->second->Get_RGB()
        << " Scale=" <<  it->second->Get_Scale()
        << " Shift=" << it->second->Get_Shift()
        << " RotXYZ_deg=" << "(" << it->second->GetAng_Pitch_deg() << "," << it->second->GetAng_Yaw_deg() << "," <<  it->second->GetAng_Roll_deg() << ")"
        << " Trans_m=" << it->second->GetPositoin_m()
        << "\n";

        // std::cout
    }
    
    std::cout << sConfigCmds.str();

    Send(_GuardSocket->GetSocket(), sConfigCmds.str().c_str());
}

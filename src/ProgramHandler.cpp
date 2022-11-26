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
        mobObj->SetPosition_m(obj.Shift);
        mobObj->SetAng_Pitch_deg(obj.RotXYZ_deg[0]);
        mobObj->SetAng_Yaw_deg(obj.RotXYZ_deg[1]);
        mobObj->SetAng_Roll_deg(obj.RotXYZ_deg[2]);
        /* >>>>>>>>>>> Write more code [Probably in MobileObj class] <<<<<<<<<<<< */
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
        << "Mobile obj name: " << pMobiles->GetName() << " "
        << "Mobile obj position: " << pMobiles->GetPositoin_m() << " "
        /* Write more code */
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

int ProgramHandler::sendToServer()
{
    const char *sConfigCmds =
    "Clear\n"
    "AddObj Name=Podstawa1 RGB=(20,200,200) Scale=(4,2,1) Shift=(0.5,0,0) RotXYZ_deg=(0,-45,20) Trans_m=(-1,3,0)\n"
    "AddObj Name=Podstawa1.Ramie1 RGB=(200,0,0) Scale=(3,3,1) Shift=(0.5,0,0) RotXYZ_deg=(0,-45,0) Trans_m=(4,0,0)\n"
    "AddObj Name=Podstawa1.Ramie1.Ramie2 RGB=(100,200,0) Scale=(2,2,1) Shift=(0.5,0,0) RotXYZ_deg=(0,-45,0) Trans_m=(3,0,0)\n"       
    "AddObj Name=Podstawa2 RGB=(20,200,200) Scale=(4,2,1) Shift=(0.5,0,0) RotXYZ_deg=(0,-45,0) Trans_m=(-1,-3,0)\n"
    "AddObj Name=Podstawa2.Ramie1 RGB=(200,0,0) Scale=(3,3,1) Shift=(0.5,0,0) RotXYZ_deg=(0,-45,0) Trans_m=(4,0,0)\n"
    "AddObj Name=Podstawa2.Ramie1.Ramie2 RGB=(100,200,0) Scale=(2,2,1) Shift=(0.5,0,0) RotXYZ_deg=(0,-45,0) Trans_m=(3,0,0)\n";

    Send(_GuardSocket->GetSocket(), sConfigCmds);
}

#include "ProgramHandler.hh"

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

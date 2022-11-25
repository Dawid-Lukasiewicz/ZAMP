#include "ProgramHandler.hh"

void ProgramHandler::loadConfig()
{
    std::cout << "Reading XML file..." << std::endl;
    if (!ReadXMLFile("config/config.xml", _Config))
        exit(-1);
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
        // std::cout << name << std::endl;
        if (name.length() > 1)
        {
            // Interp4Command *tmp = new Interp4Command
            _Cmds.push_back(_Libs[name]->getCmd());
            _Cmds.back()->ReadParams(cmdStream);
            // _Cmds.back()->PrintCmd();
            // std::cout << _Cmds.size() << std::endl;
        }

    }
}

void ProgramHandler::printCmds()
{
    for (Interp4Command *cmd : _Cmds )
    {
        cmd->PrintCmd();
    } 
    // for (auto it = _Cmds.begin(); it != _Cmds.end(); ++it)
    // {
    //     (*it)->PrintCmd();
    // }
    
}

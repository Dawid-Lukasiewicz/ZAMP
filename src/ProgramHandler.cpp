#include "ProgramHandler.hh"

void ProgramHandler::loadConfig()
{
    std::cout << "Reading XML file..." << std::endl;
    if (!ReadXMLFile("config/config.xml", _Config))
        exit(-1);
    std::cout << "Done...\n\n\n\n\n\n\n\n" << std::endl;
    std::cout.flush();
}

void ProgramHandler::LoadLibs()
{
    std::cout << "SDASDADA" << std::endl;
    for (const auto &libName : _Config.getLibs())
    {
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

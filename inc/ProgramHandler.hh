#ifndef PROGRAM_HANDLER
#define PROGRAM_HANDLER

#include "Scene.hh"
#include "Set4LibInterfaces.hh"
#include "Interp4Command.hh"
#include "FileHandler.hh"

#include <sstream>
#include <memory>

using namespace std;


class ProgramHandler
{
private:
    Scene  _Scene;
    Set4LibInterfaces _Libs;
    Configuration _Config;
    std::vector<Interp4Command *> _Cmds;

    
public:
    ProgramHandler()    {}
    ~ProgramHandler()   {}

    void loadConfig();
    void LoadLibs();
    void avalaibleSyntax();
    void parseCmds(string cmdFile);
};


#endif
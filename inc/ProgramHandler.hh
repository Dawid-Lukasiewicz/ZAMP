#ifndef PROGRAM_HANDLER
#define PROGRAM_HANDLER

#include "Scene.hh"
#include "Set4LibInterfaces.hh"
#include "Interp4Command.hh"
#include "FileHandler.hh"
#include "GuardedSocket.hh"
#include "Connection.hh"

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
    shared_ptr<GuardedSocket> _GuardSocket;

    
public:
    ProgramHandler();
    ~ProgramHandler();

    void loadConfig();
    void printConfig();
    void loadScene();
    void printScene();
    void LoadLibs();
    void avalaibleSyntax();
    void parseCmds(string cmdFile);
    void printCmds();
    int createOnServer();
};


#endif
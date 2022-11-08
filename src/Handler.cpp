#include "Handler.hh"

Handler::Handler(/* args */)
{
}

Handler::~Handler()
{
}

void Handler::CreateCmd(std::string Cmd)
{
    if (Cmd == "Move")
    {
        std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(LIB_Move, lazy);
        _LibHandlers[Cmd] = LibPlugin;
        _LibHandlers[Cmd]->CreateCmd();
        return;
    }
    if (Cmd == "Pause")
    {
        std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(LIB_Pause, lazy);
        _LibHandlers[Cmd] = LibPlugin;
        _LibHandlers[Cmd]->CreateCmd();
        return;
    }
    if (Cmd == "Rotate")
    {
        std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(LIB_Rotate, lazy);
        _LibHandlers[Cmd] = LibPlugin;
        _LibHandlers[Cmd]->CreateCmd();
        return;
    }
    if (Cmd == "Set")
    {
        std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(LIB_Set, lazy);
        _LibHandlers[Cmd] = LibPlugin;
        _LibHandlers[Cmd]->CreateCmd();
        return;
    }
    
}

std::shared_ptr<LibInterface> Handler::operator [] (std::string Cmd)
{
    return _LibHandlers[Cmd];
}

bool Handler::ReadCmdList(CommandsList &CmdList)
{
    std::string Keyword;

    int tmpCount = 0;
    while (!CmdList.empty())
    {
        std::cout << tmpCount++;
        Keyword = CmdList.front();
        CmdList.erase(CmdList.begin());
        IF_CMD_THEN_READ( Move )
        IF_CMD_THEN_READ( Rotate )
        IF_CMD_THEN_READ( Pause )
        IF_CMD_THEN_READ( Set )
    }
}

bool Handler::ReadCmd_Move(CommandsList &CmdList)
{
    _LibHandlers["Move"]->getCmd()->PrintSyntax();
}

bool Handler::ReadCmd_Rotate(CommandsList &CmdList)
{
    _LibHandlers["Rotate"]->getCmd()->PrintSyntax();
}

bool Handler::ReadCmd_Pause(CommandsList &CmdList)
{
    _LibHandlers["Pause"]->getCmd()->PrintSyntax();
}

bool Handler::ReadCmd_Set(CommandsList &CmdList)
{
    _LibHandlers["Set"]->getCmd()->PrintSyntax();
}

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
    while (CmdList.size() != 0)
    {
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
    #ifdef DEBUG
    std::cout << "Move ";
    for (int it = 0; it < 3; ++it)
    {
        std::cout << CmdList[it] + " ";
    }
    std::cout << "\n";
    #endif /* DEBUG */

    return true;
}

bool Handler::ReadCmd_Rotate(CommandsList &CmdList)
{
    #ifdef DEBUG
    std::cout << "Rotate ";
    for (int it = 0; it < 3; ++it)
    {
        std::cout << CmdList[it] + " ";
    }
    std::cout << "\n";
    #endif /* DEBUG */
    return true;
}

bool Handler::ReadCmd_Pause(CommandsList &CmdList)
{
    #ifdef DEBUG
    std::cout << "Pause ";
    for (int it = 0; it < 1; ++it)
    {
        std::cout << CmdList[it] + " ";
    }
    std::cout << "\n";
    #endif /* DEBUG */
    return true;
}

bool Handler::ReadCmd_Set(CommandsList &CmdList)
{
    #ifdef DEBUG
    std::cout << "Set ";
    for (int it = 0; it < 4; ++it)
    {
        std::cout << CmdList[it] + " ";
    }
    std::cout << "\n";
    #endif /* DEBUG */
    return true;
}

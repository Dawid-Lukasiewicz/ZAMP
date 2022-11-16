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

bool Handler::ReadCmdList(std::stringstream &CmdList)
{
    std::string Keyword;
    while (CmdList >> Keyword)
    {
        IF_CMD_THEN_READ( Move )
        IF_CMD_THEN_READ( Rotate )
        IF_CMD_THEN_READ( Pause )
        IF_CMD_THEN_READ( Set )
    }
}

bool Handler::ReadCmd_Move(std::stringstream &CmdList)
{
    std::string Word;
    #ifdef DEBUG
    std::cout << "Move";
    for (int it = 0; it < 3; ++it)
    {
        getline(CmdList, Word, ' ');
        std::cout << Word + " ";
    }
    std::cout << "\n";
    #endif /* DEBUG */
    _LibHandlers["Move"]->getCmd()->ReadParams(CmdList);
    _LibHandlers["Move"]->getCmd()->PrintCmd();

    return true;
}

bool Handler::ReadCmd_Rotate(std::stringstream &CmdList)
{
    std::string Word;
    #ifdef DEBUG
    std::cout << "Rotate";
    for (int it = 0; it < 3; ++it)
    {
        getline(CmdList, Word, ' ');
        std::cout << Word + " ";
    }
    std::cout << "\n";
    #endif /* DEBUG */
    _LibHandlers["Rotate"]->getCmd()->ReadParams(CmdList);
    _LibHandlers["Rotate"]->getCmd()->PrintCmd();

    return true;
}

bool Handler::ReadCmd_Pause(std::stringstream &CmdList)
{
    std::string Word;
    #ifdef DEBUG
    std::cout << "Pause";
    for (int it = 0; it < 1; ++it)
    {
        getline(CmdList, Word, ' ');
        std::cout << Word + " ";
    }
    std::cout << "\n";
    #endif /* DEBUG */
    _LibHandlers["Pause"]->getCmd()->ReadParams(CmdList);
    _LibHandlers["Pause"]->getCmd()->PrintCmd();

    return true;
}

bool Handler::ReadCmd_Set(std::stringstream &CmdList)
{
    std::string Word;
    #ifdef DEBUG
    std::cout << "Set";
    for (int it = 0; it < 4; ++it)
    {
        getline(CmdList, Word, ' ');
        std::cout << Word + " ";
    }
    std::cout << "\n";
    #endif /* DEBUG */
    _LibHandlers["Set"]->getCmd()->ReadParams(CmdList);
    _LibHandlers["Set"]->getCmd()->PrintCmd();
    return true;
}

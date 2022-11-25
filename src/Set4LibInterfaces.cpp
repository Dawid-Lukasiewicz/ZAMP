#include "Set4LibInterfaces.hh"

Set4LibInterfaces::Set4LibInterfaces(/* args */)
{
}

Set4LibInterfaces::~Set4LibInterfaces()
{
}

void Set4LibInterfaces::AddLib(std::string Cmd)
{
    std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(Cmd.c_str());
    insert(std::pair<std::string, std::shared_ptr<LibInterface>> (LibPlugin->getCmdName(), LibPlugin));
}

std::shared_ptr<LibInterface> Set4LibInterfaces::operator [] (std::string Cmd)
{
    return at(Cmd);
}

bool Set4LibInterfaces::ReadCmdList(std::stringstream &CmdList)
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

bool Set4LibInterfaces::ReadCmd_Move(std::stringstream &CmdList)
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
    // ["Move"]->getCmd()->ReadParams(CmdList);

    return true;
}

bool Set4LibInterfaces::ReadCmd_Rotate(std::stringstream &CmdList)
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
    // _LibHandlers["Rotate"]->getCmd()->ReadParams(CmdList);
    return true;
}

bool Set4LibInterfaces::ReadCmd_Pause(std::stringstream &CmdList)
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
    // _LibHandlers["Pause"]->getCmd()->ReadParams(CmdList);
    return true;
}

bool Set4LibInterfaces::ReadCmd_Set(std::stringstream &CmdList)
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
    // _LibHandlers["Set"]->getCmd()->ReadParams(CmdList);
    return true;
}

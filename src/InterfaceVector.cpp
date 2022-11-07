#include "InterfaceVector.hh"


InterfaceVector::InterfaceVector(/* args */)
{
}

InterfaceVector::~InterfaceVector()
{
}

void InterfaceVector::CreateCmd(std::string Cmd)
{
    if (Cmd == "Move")
    {
        std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(LIB_Move, lazy);
        _LibHandlers[Cmd] = LibPlugin;
        _LibHandlers[Cmd]->CreateCmd();
    }
    if (Cmd == "Pause")
    {
        std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(LIB_Pause, lazy);
        _LibHandlers[Cmd] = LibPlugin;
        _LibHandlers[Cmd]->CreateCmd();
    }
    if (Cmd == "Rotate")
    {
        std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(LIB_Rotate, lazy);
        _LibHandlers[Cmd] = LibPlugin;
        _LibHandlers[Cmd]->CreateCmd();
    }
    if (Cmd == "Set")
    {
        std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(LIB_Set, lazy);
        _LibHandlers[Cmd] = LibPlugin;
        _LibHandlers[Cmd]->CreateCmd();
    }
    
}

std::shared_ptr<LibInterface> InterfaceVector::operator [] (std::string Cmd)
{
    return _LibHandlers[Cmd];
}
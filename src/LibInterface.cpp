#include "LibInterface.hh"

LibInterface::LibInterface(const char *LibName, RTLD_mode mode)
{
    void *LibHandler = dlopen(LibName, mode);
    _LibHandler[LibName] = LibHandler;
    if (!_LibHandler[LibName])
    {
        std::cerr << "[ERROR] library not found: " << LibName << std::endl;
        exit(-1);
    }
    void *pFun = dlsym(_LibHandler[LibName], "CreateCmd");
    
}

LibInterface::~LibInterface()
{
    for (auto it = _LibHandler.begin(); it != _LibHandler.end(); ++it)
    {
        dlclose(it->second);
    }
    
}

void LibInterface::CreateCmd(const std::string &CmdName)
{
    std::cout << _LibHandler[CmdName] << "\n";
    void *pFun = dlsym(_LibHandler[CmdName], "CreateCmd");
    if (!pFun)
    {
        std::cerr << "[ERROR] function not found: CreateCmd" << std::endl;
        exit(-1);
    }
    _pCreateCmd = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);
    _pCmd = _pCreateCmd();
    _CmdName = _pCmd->GetCmdName();
}

std::string LibInterface::getCmdName()
{
    return _CmdName;
}

const Interp4Command* LibInterface::getCmd() const
{
    return _pCmd;
}
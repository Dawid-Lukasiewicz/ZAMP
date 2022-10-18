#include "LibInterface.hh"

LibInterface::LibInterface(const char *LibName, RTLD_mode mode)
{
    _LibHandler = dlopen(LibName, mode);
    if (!_LibHandler)
    {
        std::cerr << "[ERROR] library not found: " << LibName << std::endl;
        exit(-1);
    }
    void *pFun = dlsym(_LibHandler, "CreateCmd");
    
}

LibInterface::~LibInterface()
{
    dlclose(_LibHandler);
}

void LibInterface::CreateCmd()
{
    void *pFun = dlsym(_LibHandler, "CreateCmd");
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
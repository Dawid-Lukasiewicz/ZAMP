#ifndef LIBINTERFACE
#define LIBINTERFACE

#include <string>
#include <dlfcn.h>
#include <map>

#include "Interp4Command.hh"
#include "MobileObj.hh"

enum RTLD_mode {lazy=RTLD_LAZY,\
                now=RTLD_NOW,\
                binding_mask=RTLD_BINDING_MASK,\
                noload=RTLD_NOLOAD,\
                 deepbind=RTLD_DEEPBIND};

class LibInterface
{
private:
    std::map<std::string, void*> _LibHandler;
    std::string _CmdName;
    Interp4Command *(*_pCreateCmd)(void);
    Interp4Command *_pCmd;
public:
    LibInterface(const char *LibName, RTLD_mode mode);
    ~LibInterface();

    void CreateCmd(const std::string &CmdName);
    std::string getCmdName();

    const Interp4Command* getCmd() const;
};


#endif
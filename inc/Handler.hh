#ifndef INTERFACE_VECTOR
#define INTERFACE_VECTOR

#include <map>
#include <memory>
#include <vector>
#include "LibInterface.hh"

#define STR(x)      #x
#define LIB_Move    "libInterp4Move.so"
#define LIB_Pause   "libInterp4Pause.so"
#define LIB_Rotate  "libInterp4Rotate.so"
#define LIB_Set     "libInterp4Set.so"

#define GET_LIB(CmdName) STR(LIB_##CmdName)


#define IF_CMD_THEN_READ( CmdName )                             \
        if (Keyword == STR(CmdName) )                           \
        {                                                       \
            if (!ReadCmd_##CmdName(CmdList)) return false;      \
            continue;                                           \
        }

typedef std::vector<std::string> CommandsList;

class Handler
{
private:
    std::map<std::string, std::shared_ptr<LibInterface>> _LibHandlers;
public:
    Handler();
    ~Handler();
    void CreateCmd(std::string Cmd);
    std::shared_ptr<LibInterface> operator [] (std::string Cmd);
    bool ReadCmdList(CommandsList &CmdList);
    bool ReadCmd_Move(CommandsList &CmdList);
    bool ReadCmd_Rotate(CommandsList &CmdList);
    bool ReadCmd_Pause(CommandsList &CmdList);
    bool ReadCmd_Set(CommandsList &CmdList);
};

#endif
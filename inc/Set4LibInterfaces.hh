#ifndef INTERFACE_VECTOR
#define INTERFACE_VECTOR

#include <map>
#include <memory>
#include <vector>
#include <iostream>
#include <sstream>
#include "LibInterface.hh"

// #define DEBUG 1

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

class Set4LibInterfaces : public std::map<std::string, std::shared_ptr<LibInterface>>
{
private:
    
public:
    Set4LibInterfaces();
    ~Set4LibInterfaces();
    void AddLib(std::string Cmd);
    std::shared_ptr<LibInterface> operator [] (std::string Cmd);
    bool ReadCmdList(std::stringstream &CmdList);
    bool ReadCmd_Move(std::stringstream &CmdList);
    bool ReadCmd_Rotate(std::stringstream &CmdList);
    bool ReadCmd_Pause(std::stringstream &CmdList);
    bool ReadCmd_Set(std::stringstream &CmdList);
};

#endif
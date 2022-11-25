#ifndef INTERFACE_VECTOR
#define INTERFACE_VECTOR

#include <map>
#include <memory>
#include <vector>
#include <iostream>
#include <sstream>
#include "LibInterface.hh"

#define STR(x)      #x
#define LIB_Move    "libInterp4Move.so"
#define LIB_Pause   "libInterp4Pause.so"
#define LIB_Rotate  "libInterp4Rotate.so"
#define LIB_Set     "libInterp4Set.so"

class Set4LibInterfaces : public std::map<std::string, std::shared_ptr<LibInterface>>
{
private:
    
public:
    Set4LibInterfaces();
    ~Set4LibInterfaces();
    void AddLib(std::string Cmd);
    std::shared_ptr<LibInterface> operator [] (std::string Cmd);
};

#endif
#include <iostream>
#include <sstream>
#include <vector>
#include <dlfcn.h>
#include <cassert>
#include "LibInterface.hh"
#include "Handler.hh"

using namespace std;


#define BUFF 1024
static inline bool ExecPreprocesor(const char *fileName, stringstream &StrmCmds)
{
  std::string CmdPreproc = "cpp -P ";  
  std::ostringstream TmpStrCmds;
  char Line[BUFF];

  CmdPreproc += fileName;
  FILE *pCmdFile;
  pCmdFile = popen(CmdPreproc.c_str(), "r");

  if (!pCmdFile) return false;
  while (!feof(pCmdFile))
  {
    while (fgets(Line, BUFF, pCmdFile))
    {
      TmpStrCmds << Line;
    }
  }

  StrmCmds.str(TmpStrCmds.str());
  return pclose(pCmdFile) == 0;
}

static inline void ReadCmd()
{

}

int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    cerr << "No arguments given\n";
    exit(-1);
  }

  Handler Libs;
  Libs.CreateCmd("Move");
  Libs.CreateCmd("Rotate");
  Libs.CreateCmd("Pause");
  Libs.CreateCmd("Set");

  std::stringstream CmdList;
  if ( !ExecPreprocesor(argv[1], CmdList) )
  {
    cout << "Failed to read from file\n";
    exit(-1);
  }
  cout << CmdList.str();

  Libs.ReadCmdList(CmdList);

  // cout << Libs["Move"]->getCmdName() + "\n";
  // cout << Libs["Rotate"]->getCmdName() + "\n";
  // cout << Libs["Pause"]->getCmdName() + "\n";
  // cout << Libs["Set"]->getCmdName() + "\n";
}

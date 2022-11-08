#include <iostream>
#include <sstream>
#include <list>
#include <dlfcn.h>
#include <cassert>
#include "LibInterface.hh"
#include "Handler.hh"

using namespace std;

static inline bool ExecPreprocesor(const char *fileName, std::list<std::string> &StrmCmds)
{
  std::string CmdPreproc = "cpp -P ";  
  std::string Word;
  std::stringstream Line;
  char buff[50];

  CmdPreproc += fileName;
  FILE *pCmdFile;
  pCmdFile = popen(CmdPreproc.c_str(), "r");

  if (!pCmdFile) return false;
  while (!feof(pCmdFile))
  {
    while (fgets(buff, 50, pCmdFile))
    {
      Line << buff;
    }
    while (getline(Line, Word, ' '))
    {
      StrmCmds.push_back(Word);
    }
  }
  return pclose(pCmdFile) == 0;
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

  std::list<std::string> CmdList;
  if ( !ExecPreprocesor(argv[1], CmdList) )
  {
    cout << "Failed to read from file\n";
    exit(-1);
  }
  cout << Libs["Move"]->getCmdName() + "\n";
  cout << Libs["Rotate"]->getCmdName() + "\n";
  cout << Libs["Pause"]->getCmdName() + "\n";
  cout << Libs["Set"]->getCmdName() + "\n";
}

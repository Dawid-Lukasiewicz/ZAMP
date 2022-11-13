#include <iostream>
#include <sstream>
#include <vector>
#include <dlfcn.h>
#include <cassert>
#include "LibInterface.hh"
#include "Handler.hh"
#include "FileHandler.hh"

using namespace std;

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

  Libs.ReadCmdList(CmdList);
  Libs["Move"]->getCmd()->PrintCmd();
  Libs["Rotate"]->getCmd()->PrintCmd();
  Libs["Pause"]->getCmd()->PrintCmd();
  Libs["Set"]->getCmd()->PrintCmd();

  // cout << Libs["Move"]->getCmdName() + "\n";
  // cout << Libs["Rotate"]->getCmdName() + "\n";
  // cout << Libs["Pause"]->getCmdName() + "\n";
  // cout << Libs["Set"]->getCmdName() + "\n";
}

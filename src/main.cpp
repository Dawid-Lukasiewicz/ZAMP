#include <iostream>
#include <sstream>
#include <vector>
#include <dlfcn.h>
#include <cassert>
#include "LibInterface.hh"
#include "Handler.hh"
#include "FileHandler.hh"
#include "Scene.hh"

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
  // Libs["Move"]->getCmd()->PrintCmd();
  // Libs["Rotate"]->getCmd()->PrintCmd();
  // Libs["Pause"]->getCmd()->PrintCmd();
  // Libs["Set"]->getCmd()->PrintCmd();

  shared_ptr<MobileObj> mobile1 = make_shared<MobileObj>();
  mobile1->SetName("nazwa1");

  Scene scene1;
  scene1.AddMobileObj(mobile1);

  if (scene1.FindMobileObj("nazwa1") == mobile1)
    cout << "Te same\n";
  else
    cout << "Nie te same\n";

  // Configuration   Config;
  // if (!ReadFile("config/config.xml",Config)) return 1;

}

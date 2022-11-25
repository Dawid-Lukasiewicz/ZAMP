#include <iostream>
#include <sstream>
#include <vector>
#include <dlfcn.h>
#include <cassert>
#include "LibInterface.hh"
#include "Set4LibInterfaces.hh"
#include "FileHandler.hh"
#include "Scene.hh"
#include "ProgramHandler.hh"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    cerr << "No arguments given\n";
    exit(-1);
  }

  ProgramHandler hdl;

  hdl.loadConfig();
  hdl.LoadLibs();
  hdl.avalaibleSyntax();
  // hdl.parseCmds(argv[1]);
  // std::cout << "Dupa4\n";

  // Set4LibInterfaces Libs;
  // Libs.AddLib(LIB_Move);
  // Libs.AddLib(LIB_Pause);
  // Libs.AddLib(LIB_Rotate);
  // Libs.AddLib(LIB_Set);

  // std::stringstream CmdList;
  // if ( !ExecPreprocesor(argv[1], CmdList) )
  // {
  //   cout << "Failed to read from file\n";
  //   exit(-1);
  // }

  // Libs.ReadCmdList(CmdList);
  // Libs["Move"]->getCmd()->PrintCmd();
  // Libs["Rotate"]->getCmd()->PrintCmd();
  // Libs["Pause"]->getCmd()->PrintCmd();
  // Libs["Set"]->getCmd()->PrintCmd();

  // shared_ptr<MobileObj> mobile1 = make_shared<MobileObj>();
  // mobile1->SetName("nazwa1");

  // Scene scene1;
  // scene1.AddMobileObj(mobile1);

  // if (scene1.FindMobileObj("nazwa1") == mobile1)
  //   cout << "Te same\n";
  // else
  //   cout << "Nie te same\n";

  // Configuration   Config;
  // if (!ReadXMLFile("config/config.xml",Config)) return 1;

}

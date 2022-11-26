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
  hdl.printConfig();
  hdl.loadScene();
  hdl.printScene();
  hdl.LoadLibs();
  hdl.avalaibleSyntax();
  hdl.parseCmds(argv[1]);
  hdl.printCmds();
  hdl.createOnServer();
}

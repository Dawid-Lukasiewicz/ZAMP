#include <iostream>
#include <fstream>
#include <dlfcn.h>
#include <cassert>
#include "LibInterface.hh"
#include "InterfaceVector.hh"

using namespace std;


int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    cerr << "No arguments given\n";
    exit(-1);
  }

  ifstream file;
  file.open(argv[1]);
  std::string line;
  while (getline(file, line))
  {
    cout << line << std::endl;
  }

  InterfaceVector Libs;
  Libs.CreateCmd("Move");
  Libs.CreateCmd("Rotate");
  Libs.CreateCmd("Pause");
  Libs.CreateCmd("Set");

  cout << Libs["Move"]->getCmdName() + "\n";
  cout << Libs["Rotate"]->getCmdName() + "\n";
  cout << Libs["Pause"]->getCmdName() + "\n";
  cout << Libs["Set"]->getCmdName() + "\n";

  
  file.close();
}

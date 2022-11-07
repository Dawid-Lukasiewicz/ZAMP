#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "LibInterface.hh"
#include "InterfaceVector.hh"

using namespace std;


int main()
{
  InterfaceVector Libs;
  Libs.CreateCmd("Move");
  Libs.CreateCmd("Rotate");
  Libs.CreateCmd("Pause");
  Libs.CreateCmd("Set");

  cout << Libs["Move"]->getCmdName() + "\n";
  cout << Libs["Rotate"]->getCmdName() + "\n";
  cout << Libs["Pause"]->getCmdName() + "\n";
  cout << Libs["Set"]->getCmdName() + "\n";
}

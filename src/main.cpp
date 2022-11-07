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
  cout << Libs.GetCmdName("Move") + "\n";
  cout << Libs.GetCmdName("Rotate") + "\n";
  cout << Libs.GetCmdName("Pause") + "\n";
  cout << Libs.GetCmdName("Set") + "\n";

  
}

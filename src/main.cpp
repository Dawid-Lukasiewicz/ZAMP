#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "LibInterface.hh"

using namespace std;


int main()
{
  LibInterface face("libInterp4Move.so", lazy);
  face.CreateCmd("libInterp4Move.so");

  cout << face.getCmdName() << endl;

  cout << endl;
  cout << face.getCmd()->GetCmdName() << endl;
  cout << endl;
  face.getCmd()->PrintSyntax();
  cout << endl;
  face.getCmd()->PrintCmd();
  cout << endl;

  // delete pCmd;
}

#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "LibInterface.hh"

using namespace std;


int main()
{
  LibInterface face("libInterp4Move.so", lazy);
  face.CreateCmd();

  LibInterface face2("libInterp4Rotate.so", lazy);
  face2.CreateCmd();
  cout << face2.getCmdName() << endl;

  LibInterface face3("libInterp4Set.so", lazy);
  face3.CreateCmd();
  cout << face3.getCmdName() << endl;

  LibInterface face4("libInterp4Pause.so", lazy);
  face4.CreateCmd();
  cout << face4.getCmdName() << endl;

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

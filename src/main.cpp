#include <iostream>
#include <list>
#include <fstream>
#include <dlfcn.h>
#include <cassert>
#include "LibInterface.hh"
#include "Handler.hh"


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

  ifstream file;
  file.open(argv[1]);
  std::list<std::string> CmdList;
  std::string word;
  while (getline(file, word, ' '))
  {
    cout << word << std::endl;
    if (word != " ")
      CmdList.push_back(word);
  }
  cout << "-----------------CHECK--------------------\n";
  for (auto const &tmp : CmdList)
  {
    cout << tmp + "\n";
  }


  cout << Libs["Move"]->getCmdName() + "\n";
  cout << Libs["Rotate"]->getCmdName() + "\n";
  cout << Libs["Pause"]->getCmdName() + "\n";
  cout << Libs["Set"]->getCmdName() + "\n";

  
  file.close();
}

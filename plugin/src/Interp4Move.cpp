#include <iostream>
#include "Interp4Move.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Move"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Move::CreateCmd();
}


/*!
 *
 */
Interp4Move::Interp4Move():
  _Object_name(""), _Speed_mmS(0), _Distance_m(0)
{}


/*!
 *
 */
void Interp4Move::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() 
        << " " << _Object_name
        << " " << _Speed_mmS
        << " " << _Distance_m
        << endl;
}


/*!
 *
 */
const char* Interp4Move::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Move::ExecCmd( Scene &pScene, shared_ptr<GuardedSocket> gSocket ) const
{
  std::stringstream cmd;
  float transition = pScene.FindMobileObj(_Object_name)->GetPositoin_m()[0];
  int iterations = STATES_NUMBER;
  while (iterations >= 1)
  {
    cmd.clear();
    cmd << "UpdadeObj Name=" <<_Object_name;
    transition += _Distance_m/STATES_NUMBER;
    cmd << transition;
    --iterations;
  }
  // pScene.FindMobileObj(_Object_name)->SetPosition_m()
  
  
  return true;
}


/*!
 *
 */
bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList
    >> _Object_name
    >> _Speed_mmS
    >> _Distance_m;
  return true;
}


/*!
 *
 */
Interp4Command* Interp4Move::CreateCmd()
{
  return new Interp4Move();
}


/*!
 *
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}

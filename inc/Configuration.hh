#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH

#include <vector>
#include "Vector3D.hh"

class ObjectData
{
public:
  std::string Name;
  Vector3D Shift;
  Vector3D Scale;
  Vector3D RotXYZ_deg;
  Vector3D Trans_m;
  Vector3D RGB;

  ObjectData()
  {
    Name = "Obj";

    for(int i = 0; i<3; i++)
    {
      Shift[i] = 0;
      Scale[i] = 1;
      RotXYZ_deg[i] = 0;
      Trans_m[i] = 0;
      RGB[i] = 128;
    }
  }
  ~ObjectData() {}
};

class Configuration {
  std::vector<std::string> _LibName;
  std::vector<ObjectData> _ObjectData;
public:

  const std::vector<std::string>& getLibs() const {return _LibName; };
  const std::vector<ObjectData>& getObjs() const {return _ObjectData; };

  std::vector<std::string>& modLibs() {return _LibName; }
  std::vector<ObjectData>& modObjs() { return _ObjectData; } 
};


#endif

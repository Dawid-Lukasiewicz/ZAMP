#ifndef SCENE
#define SCENE

#include <map>
#include <memory>
#include <string>
#include "MobileObj.hh"

using namespace std;

class Scene
{
private:
    map<string, shared_ptr<MobileObj>> _MobileObj;

public:
    Scene();
    ~Scene();

    shared_ptr<MobileObj> FindMobileObj(string sName);
    void AddMobileObj(shared_ptr<MobileObj> pMobileObj);
};


#endif /* SCENE */
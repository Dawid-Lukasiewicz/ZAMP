#include "Scene.hh"

Scene::Scene()
{}

Scene::~Scene()
{}

shared_ptr<MobileObj> Scene::FindMobileObj(string sName)
{
    return _MobileObj[sName];
}

bool Scene::AddMobileObj(shared_ptr<MobileObj> pMobileObj)
{
    string ObjName = pMobileObj->GetName();
    if (_MobileObj.find(ObjName) == _MobileObj.end())
    {
        _MobileObj[ObjName] = pMobileObj;
        return true;
    }
    return false;
}
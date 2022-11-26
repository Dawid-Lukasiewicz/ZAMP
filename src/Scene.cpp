#include "Scene.hh"

Scene::Scene()
{}

Scene::~Scene()
{}

shared_ptr<MobileObj> Scene::FindMobileObj(string sName)
{
    return _MobileObj.at(sName);
}

void Scene::AddMobileObj(shared_ptr<MobileObj> pMobileObj)
{
    _MobileObj.insert(pair<string, shared_ptr<MobileObj>>(pMobileObj->GetName(), pMobileObj));
}

const map<string, shared_ptr<MobileObj>> & Scene::GetMobileObjs() const
{
    return _MobileObj;
}
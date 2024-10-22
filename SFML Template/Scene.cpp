#include "stdafx.h"
#include "Scene.h"

Scene::Scene(SceneIds id)
    : id(id)
{
}

void Scene::Init()
{
    //초기에 가지고있어야 하는 Go들을 add
    for (auto obj : gameObject)
    {
        obj->Init();
    }
}

void Scene::Release()
{
    for (auto obj : gameObject)
    {
        obj->Release();
    }
}


/// <summary>
/// 씬을 바꿀 때, Go의 Reset()을 함
/// </summary>
void Scene::Enter()
{
    for (auto obj : gameObject)
    {
        obj->Reset();
    }
}

void Scene::Exit()
{
}

void Scene::Update(float dt)
{
    for (auto obj : gameObject)
    {
        if (!obj->IsActive())
            continue;

        obj->Update(dt);
    }
}

void Scene::Draw(sf::RenderWindow& window)
{
    for (auto obj : gameObject)
    {
        if (!obj->IsActive())
            continue;

        obj->Draw(window);
    }
}

GameObject* Scene::AddGo(GameObject* obj)
{
    if (std::find(gameObject.begin(), gameObject.end(), obj) == gameObject.end())
    {
        gameObject.push_back(obj);
    }

    return obj;
}

void Scene::RemoveGo(GameObject* obj)
{
    gameObject.remove(obj);
}

GameObject* Scene::FindGo(const std::string& name)
{
    for (auto obj : gameObject)
    {
        if (obj->GetName() == name)
        {
            return obj;
        }
    }

    return nullptr;
}

int Scene::FindGoAll(const std::string& name, std::list<GameObject*>& list)
{
    int cnt = 0;
    list.clear();
    for (auto obj : gameObject)
    {
        if (obj->GetName() == name)
        {
            list.push_back(obj);
            cnt++;
        }
    }
    return cnt;
}
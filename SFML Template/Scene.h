#pragma once
#include "SpriteGo.h"
/// <summary>
/// GameObject들의 집합
/// </summary>
class Scene
{
protected:
	const SceneIds id;
	std::list<GameObject*> gameObject;

public:
	Scene(SceneIds id);
	virtual ~Scene() = default;

	virtual void Init();
	virtual void Release();

	virtual void Enter();
	virtual void Exit();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

	template<typename T>
	inline T* AddGo(T* obj);
	virtual void RemoveGo(GameObject* obj);


	GameObject* FindGo(const std::string& name);
	virtual int FindGoAll(const std::string& name, std::list<GameObject*>& list);
};

template<typename T>
inline T* Scene::AddGo(T* obj)
{
	if (std::find(gameObject.begin(), gameObject.end(), obj) == gameObject.end())
	{
		gameObject.push_back(obj);
	}

	return obj;
}

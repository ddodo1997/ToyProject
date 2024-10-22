#pragma once
#include "stdafx.h"
/// <summary>
/// �������� Scene�� �����ϴ� ������
/// </summary>

class Scene;
class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;
protected:
	std::vector<Scene*> scenes;

	//���� ��
	SceneIds startScene = SceneIds::Dev1;

	//���� ��
	SceneIds currentScene;

	SceneMgr() = default;
	virtual ~SceneMgr() = default;

	SceneMgr(const SceneMgr& other) = delete;
	SceneMgr& operator=(const SceneMgr& other) = delete;

public:
	void Init();
	void Release();

	SceneIds GetCurrentScene() const { return currentScene; }

	void ChangeScene(SceneIds id);

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

#define SCENE_MANAGER (SceneMgr::Instance())
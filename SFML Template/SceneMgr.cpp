#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneDev1.h"
#include "SceneDev2.h"
void SceneMgr::Init()
{
	//Scene 벡터를 new
	scenes.push_back(new SceneDev1());
	scenes.push_back(new SceneDev2());

	for (auto scene : scenes)
	{
		scene->Init();
	}
	currentScene = startScene;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
	//Scene 벡터를 delete
	for (auto scene : scenes)
	{
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	//새로 바꿀 씬의 id를 받아 지금 씬을 종료시켜주고, 새로운씬으로 업데이트
	scenes[(int)currentScene]->Exit();
	currentScene = id;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Update(float dt)
{
	scenes[(int)currentScene]->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes[(int)currentScene]->Draw(window);

}

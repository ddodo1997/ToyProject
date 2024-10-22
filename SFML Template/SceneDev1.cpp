#include "stdafx.h"
#include "SceneDev1.h"
#include "SpriteGo.h"
#include "TextGo.h"
SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{
	std::cout << "SceneDev1::Init()" << std::endl;
	GameObject* obj = AddGo(new SpriteGo("graphics/background.png"));
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });

	GameObject* text = AddGo(new TextGo("fonts/KOMIKAP_.ttf"));
	text->SetOrigin(Origins::TL);
	text->SetPosition({ 0.f,0.f });
	text->SetString("Dev1");
	Scene::Init();
}

void SceneDev1::Enter()
{
	std::cout << "SceneDev1::Enter()" << std::endl;
	TEXTURE_MANAGER.Load("graphics/background.png");
	FONT_MANAGER.Load("fonts/KOMIKAP_.ttf");
	Scene::Enter();
}

void SceneDev1::Exit()
{
	std::cout << "SceneDev1::Exit()" << std::endl;
	TEXTURE_MANAGER.UnLoad("graphics/background.png");
	FONT_MANAGER.UnLoad("fonts/KOMIKAP_.ttf");
	Scene::Exit();
}

void SceneDev1::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown())
	{
		SCENE_MANAGER.Instance().ChangeScene(SceneIds::Dev2);
	}
}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

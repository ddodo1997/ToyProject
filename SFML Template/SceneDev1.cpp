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
	SpriteGo* backGround = AddGo(new SpriteGo("graphics/bg_night.png"));
	backGround->SetOrigin(Origins::MC);
	backGround->SetPosition({ 600 / 2, 800 / 2 });
	//backGround->SetScale({ 3.f, 1.2f });

	SpriteGo* tile = AddGo(new SpriteGo("graphics/tile.png"));
	tile->SetOrigin(Origins::BC);
	tile->SetPosition({ 600 / 2,800 });
	TextGo* title = AddGo(new TextGo("fonts/Cafe24Decobox.ttf"));
	title->SetOrigin(Origins::BC);
	title->SetPosition({ 600 / 2, 800 / 3});
	title->SetString("FlappyBird");
	title->SetCharacterSize(130);
	//s = vt
	//이동거리 = 속도 * 시간
	//속도 = 가속도 * 시간
	Scene::Init();
}

void SceneDev1::Enter()
{
	std::cout << "SceneDev1::Enter()" << std::endl;
	TEXTURE_MANAGER.Load("graphics/bg_night.png");
	TEXTURE_MANAGER.Load("graphics/tile.png");
	FONT_MANAGER.Load("fonts/Cafe24Decobox.ttf");
	Scene::Enter();
}

void SceneDev1::Exit()
{
	std::cout << "SceneDev1::Exit()" << std::endl;
	TEXTURE_MANAGER.UnLoad("graphics/bg_night.png");
	TEXTURE_MANAGER.UnLoad("graphics/tile.png");
	FONT_MANAGER.UnLoad("fonts/Cafe24Decobox.ttf");
	Scene::Exit();
}

void SceneDev1::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown())
	{
		SCENE_MANAGER.ChangeScene(SceneIds::Dev2);
	}
}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

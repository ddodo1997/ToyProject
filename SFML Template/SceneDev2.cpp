#include "stdafx.h"
#include "SceneDev2.h"
#include "SpriteGo.h"
#include "TextGo.h"
SceneDev2::SceneDev2()
	:Scene(SceneIds::Dev2)
{
}

void SceneDev2::Init()
{
	std::cout << "SceneDev2::Init()" << std::endl;
	GameObject* player = AddGo(new SpriteGo("graphics/player.png"));
	player->SetOrigin(Origins::MC);
	player->SetPosition({ 1920 / 2,1080 / 2 });

	GameObject* text = AddGo(new TextGo("fonts/KOMIKAP_.ttf"));
	text->SetOrigin(Origins::TL);
	text->SetPosition({ 0.f,0.f });
	text->SetString("Dev2");
	Scene::Init();
}

void SceneDev2::Enter()
{
	std::cout << "SceneDev2::Enter()" << std::endl;
	TEXTURE_MANAGER.Load("graphics/player.png");
	FONT_MANAGER.Load("fonts/KOMIKAP_.ttf");
	Scene::Enter();
}

void SceneDev2::Exit()
{
	std::cout << "SceneDev2::Exit()" << std::endl;
	TEXTURE_MANAGER.UnLoad("graphics/player.png");
	FONT_MANAGER.UnLoad("fonts/KOMIKAP_.ttf");
	Scene::Exit();

}

void SceneDev2::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown())
	{
		SCENE_MANAGER.Instance().ChangeScene(SceneIds::Dev1);
	}

}

void SceneDev2::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

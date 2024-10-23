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
	std::vector<SpriteGo*>toppipe;

	const int pipetex = 6;
	toppipe.push_back(AddGo(new SpriteGo("graphics/pipe.png")));
	for (int i = 0; i < pipetex; ++i)
	{
		toppipe[i]->SetOrigin(Origins::TL);
		toppipe[i]->SetPosition({ i * 384.f,1080 });
	}
	


	
	

	TextGo* text = AddGo(new TextGo("fonts/Cafe24Decobox.ttf"));
	text->SetOrigin(Origins::TL);
	text->SetPosition({ 0.f,0.f });
	text->SetString("SCORE = 0");
	Scene::Init();
}

void SceneDev2::Enter()
{
	std::cout << "SceneDev2::Enter()" << std::endl;
	TEXTURE_MANAGER.Load("graphics/bg_noon.png");
	FONT_MANAGER.Load("fonts/Cafe24Decobox.ttf");
	Scene::Enter();
}

void SceneDev2::Exit()
{
	std::cout << "SceneDev2::Exit()" << std::endl;
	TEXTURE_MANAGER.UnLoad("graphics/bg_noon.png");
	FONT_MANAGER.UnLoad("fonts/Cafe24Decobox.ttf");
	Scene::Exit();

}

void SceneDev2::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown())
	{
		SCENE_MANAGER.ChangeScene(SceneIds::Dev1);
	}

}

void SceneDev2::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

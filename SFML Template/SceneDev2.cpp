#include "stdafx.h"
#include "SceneDev2.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "Pipe.h"
#include "Bird.h"
#include "BackGround.h"
#include "Tile.h"
#include <time.h>
SceneDev2::SceneDev2()
	:Scene(SceneIds::Dev2)
{
}

void SceneDev2::Init()
{
	std::cout << "SceneDev2::Init()" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		AddGo(new BackGround(i * 640.f, 1080, "graphics/bg_noon.png"));
	}
#pragma region Backup
	// srand(time(NULL));
	
	////위파이프 위치
	//float randhole[6];

	//for (int i = 0; i < 6; i++)
	//{
	//	randhole[i] = rand() % 750;
	//}
	////위쪽파이프
	//std::vector<SpriteGo*>toppipe;
	//const int Toppipetex = 6;
	//const float pipedistance = 500;
	//for (int i = 0; i < Toppipetex; ++i)
	//{
	//	toppipe.push_back(AddGo(new SpriteGo("graphics/toppipe.png")));
	//	toppipe[i]->SetOrigin(Origins::TC);
	//	toppipe[i]->SetPosition({ i * pipedistance + 1000,-720+ randhole[i]});
	//	toppipe[i]->SetScale({ 1.0f,2.0f });
	//	
	//}
	
	////아래쪽파이프
	//std::vector<SpriteGo*>underpipe;
	//const int underpipetex = 6;
	////아래파이프 위치
	//for (int i = 0; i < underpipetex; ++i)
	//{
	//	underpipe.push_back(AddGo(new SpriteGo("graphics/underpipe.png")));
	//	underpipe[i]->SetOrigin(Origins::BC);

	//	underpipe[i]->SetPosition({ i * pipedistance+1000, 1080+ randhole[i]});
	//	underpipe[i]->SetScale({ 1.0f,2.0f });
	//}
	//속도 
	//스코어 폰트
#pragma endregion
	int numOfPipes = 100;
	std::vector<Pipe*> pipes;
	for (int i = 1; i <= numOfPipes; ++i)
	{
		Pipe* p = new Pipe(1000.0f + (200.0f * i), 0);
		pipes.push_back(p);
		p->SetScale(Utils::GetRandom(1, 10) * 0.15f);
	}
	(*pipes.begin())->SetSpeed(300.f);
	for (auto pipe : pipes)
	{
		Scene::AddGo(pipe);
	}
	
	TextGo* text = AddGo(new TextGo("fonts/Cafe24Decobox.ttf"));
	text->SetOrigin(Origins::TL);
	text->SetPosition({ 0.f,0.f });
	text->SetString("SCORE = 0");

	AddGo(new Bird(1920 / 4, 1080 / 2 , "Bird"));
	for (int i = 0; i < 10; i++)
	{
		AddGo(new Tile(i * 215.f, 1080, "graphics/tile.png"));
	}

	Scene::Init();
}

void SceneDev2::Enter()
{
	std::cout << "SceneDev2::Enter()" << std::endl;
	TEXTURE_MANAGER.Load("graphics/bg_noon.png");
	TEXTURE_MANAGER.Load("graphics/toppipe.png");
	TEXTURE_MANAGER.Load("graphics/underpipe.png");
	FONT_MANAGER.Load("fonts/Cafe24Decobox.ttf");
	Scene::Enter();
}

void SceneDev2::Exit()
{
	std::cout << "SceneDev2::Exit()" << std::endl;
	TEXTURE_MANAGER.UnLoad("graphics/bg_noon.png");
	TEXTURE_MANAGER.UnLoad("graphics/toppipe.png");
	TEXTURE_MANAGER.UnLoad("graphics/underpipe.png");
	FONT_MANAGER.UnLoad("fonts/Cafe24Decobox.ttf");
	Scene::Exit();

}

void SceneDev2::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		SCENE_MANAGER.ChangeScene(SceneIds::Dev1);
	}
	//파이프 속도
	
	


	

}

void SceneDev2::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

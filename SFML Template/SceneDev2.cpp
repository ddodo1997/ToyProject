#include "stdafx.h"
#include "SceneDev2.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "Bird.h"
#include "BackGround.h"
#include "Tile.h"
#include "GameOverText.h"
#include "Score.h"
#include <time.h>

bool SceneDev2::isGameOver = false;

SceneDev2::SceneDev2()
	:Scene(SceneIds::Dev2)
{
}

void SceneDev2::Init()
{
	for (int i = 0; i < 4; i++)
	{
		AddGo(new BackGround(i * 640.f, 1080, "graphics/bg_noon.png"));
	}

	srand(time(NULL));

	//�������� ��ġ

	for (int i = 0; i < 6; i++)
	{
		randhole[i] = (float)(rand() % 750);
	}
	//����������
	const int Toppipetex = 6;
	const float pipedistance = 500;

	for (int i = 0; i < Toppipetex; ++i)
	{
		toppipe.push_back(AddGo(new SpriteGo("graphics/toppipe.png")));
		toppipe[i]->SetOrigin(Origins::TC);
		toppipe[i]->SetPosition({ i * pipedistance + 1000,-720 + randhole[i] });
		toppipe[i]->SetScale({ 1.0f,2.0f });

	}

	//�Ʒ���������

	const int underpipetex = 6;
	//�Ʒ������� ��ġ
	for (int i = 0; i < underpipetex; ++i)
	{
		underpipe.push_back(AddGo(new SpriteGo("graphics/underpipe.png")));
		underpipe[i]->SetOrigin(Origins::BC);

		underpipe[i]->SetPosition({ i * pipedistance + 1000, 1080 + randhole[i] });
		underpipe[i]->SetScale({ 1.0f,2.0f });
	}


	TextGo* text = AddGo(new TextGo("fonts/Cafe24Decobox.ttf"));
	text->SetOrigin(Origins::TL);
	text->SetPosition({ 0.f,0.f });
	text->SetString("SCORE = 0");

	AddGo(new Bird(1920 / 4, 1080 / 2, "Bird"));
	AddGo(new Tile(215.f, 1080, "graphics/tile.png"));
	AddGo(new GameOverText("fonts/FlappyFont.ttf","GameOver"));
	AddGo(new Score("fonts/FlappyFont.ttf", "Score"));
	Scene::Init();
}

void SceneDev2::Enter()
{
	std::cout << "SceneDev2::Enter()" << std::endl;
	TEXTURE_MANAGER.Load("graphics/bg_noon.png");
	TEXTURE_MANAGER.Load("graphics/toppipe.png");
	TEXTURE_MANAGER.Load("graphics/underpipe.png");
	FONT_MANAGER.Load("fonts/Cafe24Decobox.ttf");
	isGameOver = false;
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
	const float pipespeed = 300.f * dt; //�������̵��ӵ�
	if (isGameOver)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
			SCENE_MANAGER.ChangeScene(SceneIds::Dev1);
		return;
	}

	for (int i = 0; i < 6; i++)
	{
		randhole[i] = (float)(rand() % 750);
		toppipe[i]->Move(-pipespeed, 0.f);
		underpipe[i]->Move(-pipespeed, 0.f);

		if (toppipe[i]->GetPosition().x <= -60.f)
		{

			toppipe[i]->SetPosition(sf::Vector2f(3000, randhole[i] - 720.f));

		}
		if (underpipe[i]->GetPosition().x <= -60.f)
		{
			underpipe[i]->SetPosition(sf::Vector2f(3000, randhole[i] + 1080.f));

		}
	}
	//������ �ӵ�



	Scene::Update(dt);
}

void SceneDev2::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

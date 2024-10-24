#include "stdafx.h"
#include "SceneDev2.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "Bird.h"
#include "BackGround.h"
#include "Tile.h"
#include "GameOverText.h"
#include "Score.h"
#include "Pipe.h"
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

	AddGo(new Pipe("graphics/Toppipe.png", "graphics/underpipe.png"));
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
	if (isGameOver)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
			SCENE_MANAGER.ChangeScene(SceneIds::Dev1);
		return;
	}

	Scene::Update(dt);
}

void SceneDev2::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"
#include "BackGround.h"
#include "Bird.h"
#include "Tile.h"
#include "Title.h"
#include "ChooseBirds.h"
#include "TextGS.h"
#include "TextArrow.h"
#include "TextChoose.h"
bool SceneDev1::isTitle = true;
SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{

	for (int i = 0; i < numOfBackGrounds; i++)
	{
		AddGo(new BackGround(i * 640.f, 1080, "graphics/bg_night.png"));
	}


	AddGo(new Tile(215.f, 1080, "graphics/tile.png"));


	std::string filename = "config/sprites.txt";
	std::ifstream infile(filename);
	if (!infile.is_open()) {
		std::cerr << "������ �� �� �����ϴ�." << std::endl;
		return;
	}
	std::vector<std::string> pathOfBirds;
	pathOfBirds.resize(numOfBirds + 1);
	for (int i = 0; std::getline(infile, pathOfBirds[i]); i++);
	infile.close();
	for (int i = 0; i < numOfBirds; i++)
	{
		AddGo(new ChooseBirds(1920 / 2, (i % 3 + 5) * 100.f, pathOfBirds[i], "Bird" + std::to_string(i)));
	}
	AddGo(new Title(1920 / 2, 1080 / 3, "fonts/FlappyFont.ttf", "Title", "FlappyBird", 120));
	AddGo(new Title(1920 / 2, 1080 / 1.5f, "fonts/FlappyFont.ttf", "GameStart", "Press Space To Start!", 80));


	AddGo(new TextArrow(1920 / 2.4, 470, "fonts/FlappyFont.ttf", "Arrow"));

	AddGo(new TextChoose(1920 / 2, 300, "fonts/FlappyFont.ttf", "ChooseChar", "Choose Your Character!", 80));


	Scene::Init();
}


void SceneDev1::Enter()
{
	arrowIndex = 0;
	Scene::Enter();
}

void SceneDev1::Exit()
{
	Scene::Exit();
}

void SceneDev1::Update(float dt)
{
	if (!isTitle)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			SCENE_MANAGER.ChangeScene(SceneIds::Dev2);
		}
		else if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
		{
			isTitle = true;
		}
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		isTitle = false;

	Scene::Update(dt);
}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

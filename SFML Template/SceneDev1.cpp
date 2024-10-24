#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"
#include "BackGround.h"
#include "Bird.h"
#include "Tile.h"
#include "Title.h"
#include "ChooseBirds.h"
#include "TextGS.h"
SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{
	std::vector<BackGround*> backgrounds;
	std::vector<Tile*> tiles;
	std::vector<ChooseBirds*> birds;

	for (int i = 0; i < numOfBackGrounds; i++)
	{
		backgrounds.push_back(AddGo(new BackGround(i * 640.f, 1080, "graphics/bg_night.png")));
	}

	for (int i = 0; i < numOfTiles; i++)
	{
		tiles.push_back(AddGo(new Tile(i * 215.f, 1080, "graphics/tile.png")));
	}

	std::string filename = "config/sprites.txt";
	std::ifstream infile(filename);
	if (!infile.is_open()) {
		std::cerr << "파일을 열 수 없습니다." << std::endl;
		return;
	}
	std::vector<std::string> pathOfBirds;
	pathOfBirds.resize(numOfBirds + 1);
	for (int i = 0; std::getline(infile, pathOfBirds[i]); i++);
	infile.close();

	for (int i = 0; i < numOfBirds; i++)
	{
		birds.push_back(AddGo(new ChooseBirds(1920 / 2, (i % 3 + 5) * 100.f, pathOfBirds[i], "Bird" + std::to_string(i))));
	}
	Title* title = AddGo(new Title(1920 / 2, 1080 / 3, "fonts/FlappyFont.ttf", "Title"));
	TextGS* gameStart = AddGo(new TextGS(1920 / 2, 1080 / 1.5f, "fonts/FlappyFont.ttf", "GameStart"));


	std::vector<Title*> arrow;
	for (int i = 0; i < numOfBirds; i++)
	{
		arrow.push_back(AddGo(new Title(1920 / 2.3, (i % 3 + 5) * 100.f, "fonts/FlappyFont.ttf", "Arrow" + std::to_string(i))));
		arrow[i]->SetOrigin(Origins::MC);
		arrow[i]->SetString("->");
		arrow[i]->SetActive(false);
	}

	Title* choose = AddGo(new Title(1920 / 2, 300, "fonts/FlappyFont.ttf", "ChooseChar"));
	choose->SetOrigin(Origins::BC);
	choose->SetString("Choose Your Character!!");
	choose->SetCharacterSize(100);
	choose->SetActive(false);

	Scene::Init();
}


void SceneDev1::Enter()
{
	std::cout << "SceneDev1::Enter()" << std::endl;
	TEXTURE_MANAGER.Load("graphics/bg_night.png");
	TEXTURE_MANAGER.Load("graphics/tile.png");
	//TEXTURE_MANAGER.FLoad("config/sprites.txt");
	FONT_MANAGER.Load("fonts/FlappyFont.ttf");
	arrowIndex = 0;
	isTitle = true;
	Scene::Enter();
}

void SceneDev1::Exit()
{
	std::cout << "SceneDev1::Exit()" << std::endl;
	TEXTURE_MANAGER.UnLoad("graphics/bg_night.png");
	TEXTURE_MANAGER.UnLoad("graphics/tile.png");
	//TEXTURE_MANAGER.FUnLoad("config/sprites.txt");
	FONT_MANAGER.UnLoad("fonts/FlappyFont.ttf");
	Scene::Exit();
}

void SceneDev1::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		if (isTitle)
		{
			isTitle = false;
		}
		else
		{
			SCENE_MANAGER.ChangeScene(SceneIds::Dev2);
		}
	}
	Scene::Update(dt);
}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

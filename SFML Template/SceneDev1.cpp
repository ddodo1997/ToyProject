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
	std::vector<SpriteGo*> backgrounds;
	std::vector<SpriteGo*> tiles;
	std::vector<SpriteGo*> birds;
	std::vector<std::string> pathOfBirds;
	

	TextGo* title;
	TextGo* gameStart;
	TextGo* choose;
	std::vector<TextGo*> arrow;

	for (int i = 0; i < numOfBackGrounds; i++)
	{
		backgrounds.push_back(AddGo(new SpriteGo("graphics/bg_night.png", "BackGround" + std::to_string(i))));
		backgrounds[i]->SetOrigin(Origins::BC);
		backgrounds[i]->SetPosition({ i * 640.f, 1080 });
		backgrounds[i]->SetScale({ 1.f,1.2f });
	}

	for (int i = 0; i < numOfTiles; i++)
	{
		tiles.push_back(AddGo(new SpriteGo("graphics/tile.png", "Tile" + std::to_string(i))));
		tiles[i]->SetOrigin(Origins::BC);
		tiles[i]->SetPosition({ i * 215.f, 1080 });
		tiles[i]->SetScale({ 1.f,1.5f });
	}
	std::string filename = "config/sprites.txt";
	std::ifstream infile(filename);
	if (!infile.is_open()) {
		std::cerr << "파일을 열 수 없습니다." << std::endl;
		return;
	}
	pathOfBirds.resize(numOfBirds + 1);
	for (int i = 0; std::getline(infile, pathOfBirds[i]); i++);
	infile.close();

	for (int i = 0; i < numOfBirds; i++)
	{
		birds.push_back(AddGo(new SpriteGo(pathOfBirds[i], "Bird" + std::to_string(i))));
		birds[i]->SetOrigin(Origins::MC);
		birds[i]->SetPosition({ 1920 / 2, (i % 3 + 5) * 100.f });
		birds[i]->SetScale({ 3.f,3.f });
		birds[i]->SetActive(false);
	}


	title = AddGo(new TextGo("fonts/FlappyFont.ttf", "Title"));
	title->SetOrigin(Origins::BC);
	title->SetPosition({ 1920 / 2, 1080 / 3 });
	title->SetString("FlappyBird");
	title->SetCharacterSize(130);

	gameStart = AddGo(new TextGo("fonts/FlappyFont.ttf", "GameStart"));
	gameStart->SetOrigin(Origins::BC);
	gameStart->SetPosition({ 1920 / 2, 1080 / 1.5f });
	gameStart->SetString("Press Enter To Start!");
	gameStart->SetCharacterSize(80);

	//TODO : 게임종료, 각 메뉴를 보는 커서, 캐릭터 선택창..등등
	for (int i = 0; i < numOfBirds; i++)
	{
		arrow.push_back(AddGo(new TextGo("fonts/FlappyFont.ttf", "Arrow" + std::to_string(i))));
		arrow[i]->SetOrigin(Origins::MC);
		arrow[i]->SetPosition({ 1920 / 2.3, (i % 3 + 5) * 100.f });
		arrow[i]->SetString("->");
		arrow[i]->SetActive(false);
	}

	choose = AddGo(new TextGo("fonts/FlappyFont.ttf", "ChooseChar"));
	choose->SetOrigin(Origins::BC);
	choose->SetPosition({ 1920 / 2, 300 });
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
	TEXTURE_MANAGER.FLoad("config/sprites.txt");
	FONT_MANAGER.Load("fonts/FlappyFont.ttf");
	arrowIndex = 0;
	FindGo<TextGo>("Title")->SetActive(true);
	FindGo<TextGo>("GameStart")->SetActive(true);

	FindGo<TextGo>("ChooseChar")->SetActive(false);
	for (int i = 0; i < numOfBirds; i++)
	{
		FindGo<SpriteGo>("Bird" + std::to_string(i))->SetActive(false);
		FindGo<TextGo>("Arrow" + std::to_string(i))->SetActive(false);
		isTitle = true;
	}


	Scene::Enter();
}

void SceneDev1::Exit()
{
	std::cout << "SceneDev1::Exit()" << std::endl;
	TEXTURE_MANAGER.UnLoad("graphics/bg_night.png");
	TEXTURE_MANAGER.UnLoad("graphics/tile.png");
	TEXTURE_MANAGER.FUnLoad("config/sprites.txt");
	FONT_MANAGER.UnLoad("fonts/FlappyFont.ttf");
	Scene::Exit();
}

void SceneDev1::Update(float dt)
{
	Scene::Update(dt);
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		if (isTitle)
		{
			title->SetActive(false);
			gameStart->SetActive(false);

			choose->SetActive(true);
			for (int i = 0; i < birds.size(); i++)
				birds[i]->SetActive(true);
			arrow[0]->SetActive(true);
			isTitle = false;
		}
		else
		{
			SCENE_MANAGER.ChangeScene(SceneIds::Dev2);
		}
	}
	if (!isTitle)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Down))
		{
			if (arrowIndex < 2)
			{
				arrowIndex++;
				arrow[arrowIndex - 1]->SetActive(false);
				arrow[arrowIndex]->SetActive(true);
			}
		}
		if (InputMgr::GetKeyDown(sf::Keyboard::Up))
		{
			if (arrowIndex > 0)
			{
				arrowIndex--;
				arrow[arrowIndex + 1]->SetActive(false);
				arrow[arrowIndex]->SetActive(true);
			}
		}
	}
}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

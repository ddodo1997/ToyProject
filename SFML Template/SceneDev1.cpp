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
	const int backNum = 4;
	for (int i = 0; i < backNum; i++)
	{
		backgrounds.push_back(AddGo(new SpriteGo("graphics/bg_night.png")));
		backgrounds[i]->SetOrigin(Origins::BC);
		backgrounds[i]->SetPosition({ i * 640.f, 1080 });
		backgrounds[i]->SetScale({ 1.f,1.2f });
	}

	std::vector<SpriteGo*> tiles;
	const int tileNum = 10;
	for (int i = 0; i < tileNum; i++)
	{
		tiles.push_back(AddGo(new SpriteGo("graphics/tile.png")));
		tiles[i]->SetOrigin(Origins::BC);
		tiles[i]->SetPosition({ i * 215.f, 1080 });
		tiles[i]->SetScale({ 1.f,1.5f });
	}

	std::vector<SpriteGo*> birds;
	std::string filename = "config/sprites.txt";
	std::ifstream infile(filename);
	if (!infile.is_open()) {
		std::cerr << "파일을 열 수 없습니다." << std::endl;
		return;
	}
	nameOfBirds.resize(tileNum);
	for (int i = 0; std::getline(infile, nameOfBirds[i]); i++);
	infile.close();

	for (int i = 0; i < tileNum; i++)
	{
		birds.push_back(AddGo(new SpriteGo(nameOfBirds[i])));
		birds[i]->SetOrigin(Origins::MC);
		birds[i]->SetPosition({ 1920 / 2, (i % 3 + 5) * 100.f });
		birds[i]->SetScale({ 3.f,3.f });
		birds[i]->SetActive(false);
	}

	TextGo* title = AddGo(new TextGo("fonts/FlappyFont.ttf"));
	title->SetOrigin(Origins::BC);
	title->SetPosition({ 1920 / 2, 1080 / 3 });
	title->SetString("FlappyBird");
	title->SetCharacterSize(130);

	TextGo* gameStart = AddGo(new TextGo("fonts/FlappyFont.ttf"));
	gameStart->SetOrigin(Origins::BC);
	gameStart->SetPosition({ 1920 / 2, 1080 / 1.5f });
	gameStart->SetString("Press Enter To Start!");
	gameStart->SetCharacterSize(80);

	//TODO : 게임종료, 각 메뉴를 보는 커서, 캐릭터 선택창..등등


	Scene::Init();
}


void SceneDev1::Enter()
{
	std::cout << "SceneDev1::Enter()" << std::endl;
	TEXTURE_MANAGER.Load("graphics/bg_night.png");
	TEXTURE_MANAGER.Load("graphics/tile.png");
	TEXTURE_MANAGER.FLoad("config/sprites.txt");
	FONT_MANAGER.Load("fonts/FlappyFont.ttf");
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
		SCENE_MANAGER.ChangeScene(SceneIds::Dev2);

	}
}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

#include "stdafx.h"
#include "SpriteGo.h"
#include "SceneDev2.h"
void Framework::Init(int width, int height, const std::string& title)
{
	//세이브로드 데이터, 데이터 테이블, 끝날때까지 사용할 리소스.. 등등
	window.create(sf::VideoMode(width, height), title);
	SCENE_MANAGER.Init();
}

void Framework::Do()
{
	while (window.isOpen())
	{
		//시간을 관리하는 클래스를 따로 만들어봄직 하다.
		sf::Time dt = clock.restart();
		realDeltaTime = deltaTime = dt.asSeconds();
		deltaTime *= timeScale;
		realTime += realDeltaTime;
		time += deltaTime;

		InputMgr::Clear();

		//이벤트
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			InputMgr::UpdateEvent(event);
		}

		//업데이트
		SCENE_MANAGER.Update(deltaTime);

		//드로우
		window.clear();
		SCENE_MANAGER.Draw(window);
		window.display();
	}
}

void Framework::Release()
{
	SCENE_MANAGER.Release();
}

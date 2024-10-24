#include "stdafx.h"
#include "SpriteGo.h"
#include "SceneDev2.h"
void Framework::Init(int width, int height, const std::string& title)
{
	//���̺�ε� ������, ������ ���̺�, ���������� ����� ���ҽ�.. ���
	window.create(sf::VideoMode(width, height), title);
	SCENE_MANAGER.Init();
}

void Framework::Do()
{
	while (window.isOpen())
	{
		//�ð��� �����ϴ� Ŭ������ ���� ������ �ϴ�.
		sf::Time dt = clock.restart();
		realDeltaTime = deltaTime = dt.asSeconds();
		deltaTime *= timeScale;
		realTime += realDeltaTime;
		time += deltaTime;

		InputMgr::Clear();

		//�̺�Ʈ
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			InputMgr::UpdateEvent(event);
		}

		//������Ʈ
		SCENE_MANAGER.Update(deltaTime);

		//��ο�
		window.clear();
		SCENE_MANAGER.Draw(window);
		window.display();
	}
}

void Framework::Release()
{
	SCENE_MANAGER.Release();
}

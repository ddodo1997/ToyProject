#include "stdafx.h"
#include "Pipe.h"


Pipe::Pipe(const std::string& texIdUpper,const std::string& texIdUnder, const std::string& name)
	:textIdUpper(texIdUpper), textIdUnder(texIdUnder)
{
}



void Pipe::Init()
{
	TEXTURE_MANAGER.Load(textIdUpper);
	TEXTURE_MANAGER.Load(textIdUnder);
	srand(time(NULL));
}

void Pipe::Release()
{
}

void Pipe::Reset()
{
	auto& texPipeUpper = TEXTURE_MANAGER.Get(textIdUpper);
	auto& texPipeUnder = TEXTURE_MANAGER.Get(textIdUnder);
	//뉴게임 시 설정
	for (int i = 0; i < 6; i++)
	{
		random[i] = rand() % 750;
		sprite[i].setTexture(texPipeUpper);
		sprite[i].setPosition(sf::Vector2f(1000 + (500 * i),-720+ random[i]));
		sprite[i].setScale(1.f, 2.f);

		sprite2[i].setTexture(texPipeUnder);
		sprite2[i].setPosition(sf::Vector2f(1000 + (500 * i), 1080 + random[i]));
		sprite2[i].setScale(1.f, 2.f);
	}
	SetOrigin(sprite, Origins::TC);
	SetOrigin(sprite2, Origins::BC);
}

void Pipe::Update(float dt)
{
	const float toppipespeed = 300.f * dt;
	for (int i = 0; i < 6; ++i)
	{
		sprite[i].move(-toppipespeed, 0.f);
		sprite2[i].move(-toppipespeed, 0.f);
		if (sprite[i].getPosition().x <= -60.f)
		{
			sprite[i].setPosition(sf::Vector2f(3000, random[i] - 720.f));
		}
		if (sprite2[i].getPosition().x <= -60.f)
		{
			sprite2[i].setPosition(sf::Vector2f(3000, random[i] + 1080.f));
		}
	}
	
	
}

void Pipe::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	for (int i = 0; i < 6; ++i)
	{
		window.draw(sprite[i]);
		window.draw(sprite2[i]);
	}
	
}

void Pipe::SetPosition(const sf::Vector2f& position)
{

}

void Pipe::SetOrigin(const sf::Vector2f& origin)
{
}

void Pipe::SetOrigin(sf::Sprite sprite[], Origins preset)
{
	originPreset = preset;
	for (int i = 0; i < 6; i++)
	{
		Utils::SetOrigin(sprite[i], preset);
	}
}


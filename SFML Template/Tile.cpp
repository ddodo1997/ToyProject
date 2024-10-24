#include "stdafx.h"
#include "Tile.h"
#include "SceneDev2.h"
float Tile::speed = 300.0f;
std::vector<sf::Sprite*> Tile::sprite;
Tile::Tile(float x, float y, const std::string& id)
	:textureId(id), x(x), y(y)
{
	
}

Tile::~Tile()
{
}

void Tile::Init()
{
	TEXTURE_MANAGER.Load(textureId);
	auto& tempTex = TEXTURE_MANAGER.Get(textureId);
	for (int i = 0; i < 10; i++)
	{
		sprite.push_back(new sf::Sprite());
		sprite[i]->setTexture(tempTex);
		sprite[i]->setPosition({ x * i,y });
	}
	SetOrigin(Origins::BL);
	SetScale(1.f, 1.5f);
}

void Tile::Release()
{
	for (int i = 0; i < 10; i++)
	{
		delete sprite[i];
	}
}

void Tile::Reset()
{
	auto& tempTex = TEXTURE_MANAGER.Get(textureId);
	for (int i = 0; i < 10; i++)
	{
		sprite[i]->setTexture(tempTex);
		sprite[i]->setPosition({ x * i,y });
		SetOrigin(originPreset);
	}
}

void Tile::Update(float dt)
{
	if (SceneDev2::isGameOver)
		return;
	float newSpeed = speed * -1.0f * dt;

	for (int i = 0; i < 10; i++)
	{
		sprite[i]->move({ newSpeed, 0.0f });

		if (sprite[i]->getPosition().x < -sprite[i]->getGlobalBounds().width)
		{
			float newX = sprite[i]->getPosition().x + (10 * sprite[i]->getGlobalBounds().width);
			sprite[i]->setPosition({ newX, sprite[i]->getPosition().y });
		}
	}
}

void Tile::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	for(auto& spr:sprite)
		window.draw(*spr);
}

void Tile::SetPosition(const sf::Vector2f& position)
{
	GameObject::SetPosition(position);
	for(int i = 0; i < 10; i++)
		sprite[i]->setPosition(position);
}

void Tile::SetOrigin(const sf::Vector2f& origin)
{
	originPreset = Origins::Custom;
	this->origin = origin;
	for(int i = 0; i < 10; i++)
		sprite[i]->setOrigin(this->origin);
}

void Tile::SetOrigin(Origins preset)
{
	originPreset = preset;
	for(int i = 0; i < 10; i++)
		origin = Utils::SetOrigin(*sprite[i], preset);
}


void Tile::SetScale(float x, float y)
{
	for(int i = 0; i < 10; i++)
		sprite[i]->setScale(x, y);
}
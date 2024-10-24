#include "stdafx.h"
#include "Bird.h"
#include "TextArrow.h"
#include "SceneDev2.h"
#include "Tile.h"
#include "Pipe.h"
Bird::Bird(float x, float y, const std::string& name)
	:GameObject(name), x(x), y(y)
{
}

Bird::~Bird()
{
}

void Bird::Init()
{
	sprite.setScale(2.f, 2.f);
	originPreset = Origins::MC;
}

void Bird::Release()
{
}

void Bird::Reset()
{
	velocity.y = 0;
	SetOrigin(originPreset);
	SetPosition({ x,y });
	if (TextArrow::Location == Arrow::First)
	{
		auto& tempTex = TEXTURE_MANAGER.Get("graphics/birds/bluebird-upflap.png");
		sprite.setTexture(tempTex);
	}
	else if (TextArrow::Location == Arrow::Second)
	{
		auto& tempTex = TEXTURE_MANAGER.Get("graphics/birds/redbird-upflap.png");
		sprite.setTexture(tempTex);
	}
	else if (TextArrow::Location == Arrow::Third)
	{
		auto& tempTex = TEXTURE_MANAGER.Get("graphics/birds/yellowbird-upflap.png");
		sprite.setTexture(tempTex);
	}

}

void Bird::Update(float dt)
{
	if (SceneDev2::isGameOver)
	{
		sprite.setColor(sf::Color::Red);
		return;
	}

	std::vector<sf::FloatRect> tiles;
	for (int i = 0; i < 10; i++)
	{
		tiles.push_back(Tile::sprite[i]->getGlobalBounds());
		if (tiles[i].intersects(sprite.getGlobalBounds()))
			SceneDev2::isGameOver = true;
	}

	std::vector<sf::FloatRect> upperPipes;
	for (int i = 0; i < 10; i++)
	{
		upperPipes.push_back(Pipe::sprite[i].getGlobalBounds());
		if (upperPipes[i].intersects(sprite.getGlobalBounds()))
			SceneDev2::isGameOver = true;
	}

	std::vector<sf::FloatRect> underPipes;
	for (int i = 0; i < 10; i++)
	{
		underPipes.push_back(Pipe::sprite2[i].getGlobalBounds());
		if (underPipes[i].intersects(sprite.getGlobalBounds()))
			SceneDev2::isGameOver = true;
	}

	sf::Vector2f position = sprite.getPosition();
	velocity.y += gravity + dt;
	position += velocity * dt;
	sprite.setPosition(position);

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		Jump();
	}

	if (position.y < 24)
	{
		position.y = 24;
		velocity.y = 0;
	}
}

void Bird::Jump()
{
	velocity.y = -jumpSpeed;
}

void Bird::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);
}


void Bird::SetPosition(const sf::Vector2f& position)
{
	GameObject::SetPosition(position);
	sprite.setPosition(position);
}

void Bird::SetOrigin(const sf::Vector2f& origin)
{
	originPreset = Origins::Custom;
	this->origin = origin;
	sprite.setOrigin(this->origin);
}

void Bird::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, preset);
}

void Bird::SetScale(float x, float y)
{
	sprite.setScale(x, y);
}

#include "stdafx.h"
#include "Bird.h"
#include "TextArrow.h"
Bird::Bird(float x, float y, const std::string& name)
	:GameObject(name)
{
	sprite.setPosition(x, y);
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
	if (TextArrow::Location == Arrow::First)
	{
		auto& tempTex = TEXTURE_MANAGER.Get("graphics/birds/bluebird-upflap.png");
		sprite.setTexture(tempTex);
		SetOrigin(originPreset);
	}
	else if (TextArrow::Location == Arrow::Second)
	{
		auto& tempTex = TEXTURE_MANAGER.Get("graphics/birds/redbird-upflap.png");
		sprite.setTexture(tempTex);
		SetOrigin(originPreset);
	}
	else if (TextArrow::Location == Arrow::Third)
	{
		auto& tempTex = TEXTURE_MANAGER.Get("graphics/birds/yellowbird-upflap.png");
		sprite.setTexture(tempTex);
		SetOrigin(originPreset);
	}
	
}

void Bird::Update(float dt)
{
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

#include "stdafx.h"
#include "Bird.h"
Bird::Bird(float x, float y, const std::string& id, const std::string& name, BirdColor color)
	:textureId(id), GameObject(name), color(color)
{
	sprite.setPosition(x, y);
}

Bird::~Bird()
{
}

void Bird::Init()
{
	TEXTURE_MANAGER.Load(textureId);
	auto& tempTex = TEXTURE_MANAGER.Get(textureId);
	sprite.setTexture(tempTex);
}

void Bird::Release()
{
}

void Bird::Reset()
{
	auto& tempTex = TEXTURE_MANAGER.Get(textureId);
	sprite.setTexture(tempTex);
	SetOrigin(originPreset);
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
}

void Bird::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);
}

void Bird::Jump()
{
	velocity.y = -jumpSpeed;
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

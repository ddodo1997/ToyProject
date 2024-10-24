#include "stdafx.h"
#include "Tile.h"
float Tile::speed = 300.0f;
Tile::Tile(float x, float y, const std::string& id)
	:textureId(id)
{
	sprite.setPosition(x, y);
}

Tile::~Tile()
{
}

void Tile::Init()
{
	TEXTURE_MANAGER.Load(textureId);
	auto& tempTex = TEXTURE_MANAGER.Get(textureId);
	sprite.setTexture(tempTex);
	SetOrigin(Origins::BC);
	SetScale(1.f, 1.5f);
}

void Tile::Release()
{
}

void Tile::Reset()
{
	auto& tempTex = TEXTURE_MANAGER.Get(textureId);
	sprite.setTexture(tempTex);
	SetOrigin(originPreset);
}

void Tile::Update(float dt)
{
	if (IsActive())
	{
		float newSpeed = speed * -1.0f * dt;
		sprite.move({ newSpeed, 0.0f });
	}
}

void Tile::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);
}

void Tile::SetPosition(const sf::Vector2f& position)
{
	GameObject::SetPosition(position);
	sprite.setPosition(position);
}

void Tile::SetOrigin(const sf::Vector2f& origin)
{
	originPreset = Origins::Custom;
	this->origin = origin;
	sprite.setOrigin(this->origin);
}

void Tile::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, preset);
}


void Tile::SetScale(float x, float y)
{
	sprite.setScale(x, y);
}
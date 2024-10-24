#include "stdafx.h"
#include "BackGround.h"
BackGround::BackGround(float x, float y, const std::string& id)
	:textureId(id)
{
	sprite.setPosition(x, y);
}

BackGround::~BackGround()
{
}

void BackGround::Init()
{
	TEXTURE_MANAGER.Load(textureId);
	auto& tempTex = TEXTURE_MANAGER.Get(textureId);
	sprite.setTexture(tempTex);
	SetOrigin(Origins::BC);
	SetScale(1.f, 1.2f);
	SetActive(true);
}

void BackGround::Release()
{
}

void BackGround::Reset()
{
	auto& tempTex = TEXTURE_MANAGER.Get(textureId);
	sprite.setTexture(tempTex);
	SetOrigin(originPreset);
}

void BackGround::Update(float dt)
{

}

void BackGround::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);

}

void BackGround::SetPosition(const sf::Vector2f& position)
{
	GameObject::SetPosition(position);
	sprite.setPosition(position);

}

void BackGround::SetOrigin(const sf::Vector2f& origin)
{
	originPreset = Origins::Custom;
	this->origin = origin;
	sprite.setOrigin(this->origin);

}

void BackGround::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, preset);

}

void BackGround::SetScale(float x, float y)
{
	sprite.setScale(x, y);
}
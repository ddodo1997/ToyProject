#include "stdafx.h"
#include "SpriteGo.h"

SpriteGo::SpriteGo(const std::string& texId, const std::string& name)
	: GameObject(name), textureId(texId)
{
}

void SpriteGo::Reset()
{
	sprite.setTexture(TEXTURE_MANAGER.Get(textureId));

	SetOrigin(originPreset);
}

void SpriteGo::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	sprite.setPosition(pos);
}

void SpriteGo::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);
}

sf::Vector2f SpriteGo::GetPosition() const
{
	return sprite.getPosition();
}

void SpriteGo::SetOrigin(const sf::Vector2f& origin)
{
	originPreset = Origins::Custom;
	this->origin = origin;
	sprite.setOrigin(this->origin);
}

void SpriteGo::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, preset);
}

void SpriteGo::SetScale(const sf::Vector2f& scale)
{
	sprite.setScale(scale);
}

void SpriteGo::Move(float a,float b)
{
	sprite.move(a,b);
}

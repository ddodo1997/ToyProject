#include "stdafx.h"
#include "ChooseBirds.h"
#include "SceneDev1.h"
ChooseBirds::ChooseBirds(float x, float y, const std::string& id, const std::string& name)
	:textureId(id), GameObject(name)
{
	sprite.setPosition(x, y);
}

ChooseBirds::~ChooseBirds()
{
}

void ChooseBirds::Init()
{

}

void ChooseBirds::Release()
{
}

void ChooseBirds::Reset()
{

}

void ChooseBirds::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		if (!SceneDev1::isTitle)
		{
			TEXTURE_MANAGER.Load(textureId);
			auto& tempTex = TEXTURE_MANAGER.Get(textureId);
			sprite.setTexture(tempTex);
			SetOrigin(Origins::MC);
			SetScale(3.f, 3.f);
		}
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		if (SceneDev1::isTitle)
		{
			SetScale(0.f, 0.f);
		}
	}
}

void ChooseBirds::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);
}

void ChooseBirds::SetPosition(const sf::Vector2f& position)
{
	GameObject::SetPosition(position);
	sprite.setPosition(position);
}

void ChooseBirds::SetOrigin(const sf::Vector2f& origin)
{
	originPreset = Origins::Custom;
	this->origin = origin;
	sprite.setOrigin(this->origin);
}

void ChooseBirds::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, preset);
}

void ChooseBirds::SetScale(float x, float y)
{
	sprite.setScale(x, y);
}

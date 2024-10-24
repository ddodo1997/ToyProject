#include "stdafx.h"
#include "TextChoose.h"
#include "SceneDev1.h"

TextChoose::TextChoose(float x, float y, std::string id, std::string name, std::string str, int size)
	: GameObject(name), fontId(id)
{
	text.setPosition(x, y);
	SetOrigin(Origins::BC);
	SetString(str);
	SetCharacterSize(size);
}

TextChoose::~TextChoose()
{
}

void TextChoose::Init()
{
	FONT_MANAGER.Load(fontId);
	auto& tempFont = FONT_MANAGER.Get(fontId);
	text.setFont(tempFont);
	SetOrigin(Origins::BC);
	SetCharacterSize(0);
}

void TextChoose::Release()
{
}

void TextChoose::Reset()
{
	text.setFont(FONT_MANAGER.Get(fontId));
	SetOrigin(originPreset);
}

void TextChoose::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	text.setPosition(pos);
}

void TextChoose::SetString(const std::string str)
{
	text.setString(str);
}

void TextChoose::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(text);
}

void TextChoose::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		if (!SceneDev1::isTitle)
		{
			SetCharacterSize(80);
			SetOrigin(Origins::BC);
		}
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		if (SceneDev1::isTitle)
		{
			SetCharacterSize(0);
		}
	}
}

void TextChoose::SetOrigin(const sf::Vector2f& origin)
{
	originPreset = Origins::Custom;
	this->origin = origin;
	text.setOrigin(this->origin);
}

void TextChoose::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(text, preset);
}

void TextChoose::SetCharacterSize(int size)
{
	text.setCharacterSize(size);
}

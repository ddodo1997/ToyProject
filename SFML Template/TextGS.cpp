#include "stdafx.h"
#include "TextGS.h"

TextGS::TextGS(float x, float y, std::string id, std::string name)
	: GameObject(name), fontId(id)
{
	text.setPosition(x, y);
}

TextGS::~TextGS()
{
}

void TextGS::Init()
{
	FONT_MANAGER.Load(fontId);
	auto& tempFont = FONT_MANAGER.Get(fontId);
	text.setFont(tempFont);
	SetOrigin(Origins::BC);
	SetString("Press Enter To Start!");
	SetCharacterSize(80);
}

void TextGS::Release()
{
}

void TextGS::Reset()
{
	text.setFont(FONT_MANAGER.Get(fontId));
	SetOrigin(originPreset);
}

void TextGS::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	text.setPosition(pos);
}

void TextGS::SetString(const std::string str)
{
	text.setString(str);
}

void TextGS::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(text);
}

void TextGS::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		if (isTitle)
		{
			SetCharacterSize(0);
			isTitle = false;
		}
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		if (!isTitle)
		{
			SetCharacterSize(80);
			isTitle = true;
		}
	}
}

void TextGS::SetOrigin(const sf::Vector2f& origin)
{
	originPreset = Origins::Custom;
	this->origin = origin;
	text.setOrigin(this->origin);
}

void TextGS::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(text, preset);
}

void TextGS::SetCharacterSize(int size)
{
	text.setCharacterSize(size);
}

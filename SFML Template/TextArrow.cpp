#include "stdafx.h"
#include "TextArrow.h"
#include "SceneDev1.h"
Arrow TextArrow::Location = Arrow::None;
TextArrow::TextArrow(float x, float y, std::string id, std::string name)
	: GameObject(name), fontId(id)
{
	text.setPosition(x, y);
}

TextArrow::~TextArrow()
{
}

void TextArrow::Init()
{
	FONT_MANAGER.Load(fontId);
	auto& tempFont = FONT_MANAGER.Get(fontId);
	text.setFont(tempFont);
	SetOrigin(Origins::MC);
	SetString("->");
	SetCharacterSize(0);
}

void TextArrow::Release()
{
}

void TextArrow::Reset()
{
	text.setFont(FONT_MANAGER.Get(fontId));
	SetOrigin(originPreset);
}

void TextArrow::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	text.setPosition(pos);
}

void TextArrow::SetString(const std::string str)
{
	text.setString(str);
}

void TextArrow::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(text);
}

void TextArrow::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		if (!SceneDev1::isTitle)
		{
			SetCharacterSize(50);
			Location = Arrow::First;
			SetPosition({ 1920 / 2.4, 475 });
			isChoose = true;
		}
	}
	if (isChoose)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
		{
			SetCharacterSize(0);
			Location = Arrow::None;
		}

		if(InputMgr::GetKeyDown(sf::Keyboard::Up))
		{
			switch (Location)
			{
			case Arrow::Second:
				Location = Arrow::First;
				text.move(0.f, -100);
				break;
			case Arrow::Third:
				Location = Arrow::Second;
				text.move(0.f, -100);
				break;
			}
		}
		else if (InputMgr::GetKeyDown(sf::Keyboard::Down))
		{
			switch (Location)
			{
			case Arrow::First:
				Location = Arrow::Second;
				text.move(0.f, 100);
				break;
			case Arrow::Second:
				Location = Arrow::Third;
				text.move(0.f, 100);
				break;
			}
		}

	}
}

void TextArrow::SetOrigin(const sf::Vector2f& origin)
{
	originPreset = Origins::Custom;
	this->origin = origin;
	text.setOrigin(this->origin);
}

void TextArrow::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(text, preset);
}

void TextArrow::SetCharacterSize(int size)
{
	text.setCharacterSize(size);
}
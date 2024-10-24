#include "stdafx.h"
#include "Title.h"

Title::Title(float x, float y, std::string id, std::string name)
	: GameObject(name), fontId(id)
{
	text.setPosition(x, y);
}

Title::~Title()
{
}

void Title::Init()
{
	FONT_MANAGER.Load(fontId);
	auto& tempFont = FONT_MANAGER.Get(fontId);
	text.setFont(tempFont);
	SetOrigin(Origins::BC);
	SetString("FlappyBird");
	SetCharacterSize(130);
}

void Title::Release()
{
}

void Title::Reset()
{
	text.setFont(FONT_MANAGER.Get(fontId));
	SetOrigin(originPreset);
}

void Title::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	text.setPosition(pos);
}

void Title::SetString(const std::string str)
{
	text.setString(str);
}

void Title::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(text);
}

void Title::Update(float dt)
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
			SetCharacterSize(120);
			isTitle = true;
		}
	}
}

void Title::SetOrigin(const sf::Vector2f& origin)
{
	originPreset = Origins::Custom;
	this->origin = origin;
	text.setOrigin(this->origin);
}

void Title::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(text, preset);
}

void Title::SetCharacterSize(int size)
{
	text.setCharacterSize(size);
}

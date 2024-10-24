#include "stdafx.h"
#include "Title.h"
#include "SceneDev1.h"

Title::Title(float x, float y, std::string id, std::string name, std::string str, int size)
	: GameObject(name), fontId(id)
{
	text.setPosition(x, y);
	SetString(str);
	SetCharacterSize(size);
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
	SetCharacterSize(130);
	isTitle = true;
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
		if (!SceneDev1::isTitle)
		{
			SetCharacterSize(0);
			SetOrigin(Origins::BC);
		}
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		if (SceneDev1::isTitle)
		{
			SetCharacterSize(120);
			SetOrigin(Origins::BC);
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

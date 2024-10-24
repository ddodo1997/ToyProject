#include "stdafx.h"
#include "GameOverText.h"
#include "SceneDev2.h"

GameOverText::GameOverText(std::string id, std::string name)
	:fontId(id),GameObject(name)
{
}

GameOverText::~GameOverText()
{
}

void GameOverText::Init()
{
	FONT_MANAGER.Load(fontId);
	text.setFont(FONT_MANAGER.Get(fontId));
}

void GameOverText::Release()
{

}

void GameOverText::Reset()
{
	SetString("\t\tGame Over!!\nPress Enter to New Game");
	text.setFillColor(sf::Color::Transparent);
	text.setOutlineColor(sf::Color::Transparent);
	text.setOutlineThickness(0);
	SetCharacterSize(0);
	SetOrigin(Origins::MC);
	SetPosition({ 1920 / 8, 1080 / 3 });
}

void GameOverText::SetPosition(const sf::Vector2f& pos)
{
	text.setPosition(pos);
}

void GameOverText::SetString(const std::string& str)
{
	text.setString(str);
}

void GameOverText::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(text);
}

void GameOverText::Update(float dt)
{
	if (SceneDev2::isGameOver)
	{
		SetCharacterSize(120);
		text.setOutlineThickness(3);
		text.setFillColor(sf::Color::Red);
		text.setOutlineColor(sf::Color::Black);
	}
}

void GameOverText::SetOrigin(const sf::Vector2f& origin)
{
	this->origin = origin;
	text.setOrigin(this->origin);
}

void GameOverText::SetOrigin(Origins preset)
{
	originPreset = preset;
	Utils::SetOrigin(text, preset);
}

void GameOverText::SetCharacterSize(int size)
{
	text.setCharacterSize(size);
}

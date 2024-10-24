#include "stdafx.h"
#include "Score.h"

Score::Score(std::string id, std::string name)
	:fontId(id),GameObject(name)
{
}

Score::~Score()
{
}

void Score::Init()
{
	FONT_MANAGER.Load(fontId);
	score = 0;
	time = 0;
}

void Score::Release()
{
}

void Score::Reset()
{
	auto& temp = FONT_MANAGER.Get(fontId);
	text.setFont(temp);
	SetString("Score : " + std::to_string(score));
	SetOrigin(Origins::TC);
	SetPosition({1920 / 2, 0.f});
	SetCharacterSize(50);
	text.setFillColor(sf::Color::Magenta);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(3);
	time = 0;
	score = 0;
}

void Score::SetPosition(const sf::Vector2f& pos)
{
	text.setPosition(pos);
}

void Score::SetString(const std::string& str)
{
	text.setString(str);
}

void Score::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(text);
}

void Score::Update(float dt)
{
	time += dt;
	if (time >= 1)
	{
		score++;
		time = 0;
	}

	SetString("Score : " + std::to_string(score));
}

void Score::SetOrigin(const sf::Vector2f& origin)
{
	this->origin = origin;
	text.setOrigin(origin);
}

void Score::SetOrigin(Origins preset)
{
	originPreset = preset;
	Utils::SetOrigin(text, preset);
}

void Score::SetCharacterSize(int size)
{
	text.setCharacterSize(size);
}

#pragma once
#include "stdafx.h"
class TextGo :
    public GameObject
{
protected:
	sf::Text text;
	std::string fontId;

public:
	TextGo(const std::string& fontId, const std::string& name = "");
	~TextGo() = default;


	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void SetString(const std::string str)override;
	void Draw(sf::RenderWindow& window) override;

	void SetOrigin(const sf::Vector2f& origin)override;
	void SetOrigin(Origins preset)override;
};


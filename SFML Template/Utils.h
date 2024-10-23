#pragma once
class Utils
{
public:

	// Origin
	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Text& text, Origins preset);
	static int GetRandom(int start, int end);
};


#pragma once
#include <bitset>
#include <SFML/Graphics.hpp>
class InputMgr
{
private:
	static std::bitset<sf::Keyboard::KeyCount> keyDownBit;
	static std::bitset<sf::Keyboard::KeyCount> keyHeldBit;
	static std::bitset<sf::Keyboard::KeyCount> keyUpBit;

	static std::bitset<sf::Mouse::ButtonCount>  mouseDownBit;
	static std::bitset<sf::Mouse::ButtonCount>  mouseHeldBit;
	static std::bitset<sf::Mouse::ButtonCount>  mouseUpBit;

	static sf::Vector2i mousePoint;
public:
	static void Clear();
	static void UpdateEvent(const sf::Event& ev);
	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetMouseDown(sf::Mouse::Button);
	static bool GetMouse(sf::Mouse::Button);
	static bool GetMouseUp(sf::Mouse::Button);
	static sf::Vector2i GetMousePoint();

};


#pragma once
#include <list>
#include <SFML/Graphics.hpp>
class InputMgr
{
private:
	static std::list<sf::Keyboard::Key> keyDownList;
	static std::list<sf::Keyboard::Key> keyHeldList;
	static std::list<sf::Keyboard::Key> keyUpList;

	static std::list<sf::Mouse::Button>  mouseDownList;
	static std::list<sf::Mouse::Button>  mouseHeldList;
	static std::list<sf::Mouse::Button>  mouseUpList;
	static sf::Vector2i mousePoint;
public:
	static void Clear();
	static void UpdateEvent(const sf::Event& ev);
	static bool GetKeyDown();
	static bool GetKey();
	static bool GetKeyUp();
	static bool GetMouseDown();
	static bool GetMouse();
	static bool GetMouseUp();
	static sf::Vector2i GetMousePoint();

};


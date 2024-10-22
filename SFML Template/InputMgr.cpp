#include "stdafx.h"
std::list<sf::Keyboard::Key> InputMgr::keyDownList;
std::list<sf::Keyboard::Key> InputMgr::keyHeldList;
std::list<sf::Keyboard::Key> InputMgr::keyUpList;

std::list<sf::Mouse::Button>  InputMgr::mouseDownList;
std::list<sf::Mouse::Button>  InputMgr::mouseHeldList;
std::list<sf::Mouse::Button>  InputMgr::mouseUpList;
sf::Vector2i InputMgr::mousePoint;

void InputMgr::Clear()
{
	keyUpList.clear();
	keyDownList.clear();
	mouseDownList.clear();
	mouseUpList.clear();
}

void InputMgr::UpdateEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		if (std::find(keyHeldList.begin(), keyHeldList.end(), sf::Keyboard::Enter) == keyHeldList.end())
		{
			keyHeldList.push_back(ev.key.code);
			keyDownList.push_back(ev.key.code);
		}
		break;
	case sf::Event::KeyReleased:
		keyHeldList.remove(ev.key.code);
		keyUpList.push_back(ev.key.code);
		break;

	case sf::Event::MouseButtonPressed:
		if (std::find(mouseHeldList.begin(), mouseHeldList.end(), sf::Mouse::Left) == mouseHeldList.end())
		{
			mouseHeldList.push_back(ev.mouseButton.button);
			mouseDownList.push_back(ev.mouseButton.button);
			mousePoint.x = ev.mouseButton.x;
			mousePoint.y = ev.mouseButton.y;
		}
		break;

	case sf::Event::MouseButtonReleased:
		mouseHeldList.remove(ev.mouseButton.button);
		mouseUpList.push_back(ev.mouseButton.button);
		break;

	default:
		break;
	}
}

bool InputMgr::GetKeyDown()
{
	return std::find(keyDownList.begin(), keyDownList.end(), sf::Keyboard::Enter) != keyDownList.end();
}

bool InputMgr::GetKey()
{
	return std::find(keyHeldList.begin(), keyHeldList.end(), sf::Keyboard::Enter) != keyHeldList.end();
}

bool InputMgr::GetKeyUp()
{
	return std::find(keyUpList.begin(), keyUpList.end(), sf::Keyboard::Enter) != keyUpList.end();
}

bool InputMgr::GetMouseDown()
{
	return std::find(mouseDownList.begin(), mouseDownList.end(), sf::Mouse::Left) != mouseDownList.end();
}

bool InputMgr::GetMouse()
{
	return std::find(mouseHeldList.begin(), mouseHeldList.end(), sf::Mouse::Left) != mouseHeldList.end();
}

bool InputMgr::GetMouseUp()
{
	return std::find(mouseUpList.begin(), mouseUpList.end(), sf::Mouse::Left) != mouseUpList.end();
}

sf::Vector2i InputMgr::GetMousePoint()
{
	return sf::Vector2i(mousePoint.x, mousePoint.y);
}
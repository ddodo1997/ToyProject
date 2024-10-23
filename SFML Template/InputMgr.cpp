#include "stdafx.h"
std::bitset<sf::Keyboard::KeyCount> InputMgr::keyDownBit;
std::bitset<sf::Keyboard::KeyCount> InputMgr::keyHeldBit;
std::bitset<sf::Keyboard::KeyCount> InputMgr::keyUpBit;

std::bitset<sf::Mouse::ButtonCount>  InputMgr::mouseDownBit;
std::bitset<sf::Mouse::ButtonCount>  InputMgr::mouseHeldBit;
std::bitset<sf::Mouse::ButtonCount>  InputMgr::mouseUpBit;

sf::Vector2i InputMgr::mousePoint;

void InputMgr::Clear()
{
	keyUpBit.reset();
	keyDownBit.reset();
	mouseDownBit.reset();
	mouseUpBit.reset();
}

void InputMgr::UpdateEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		if (!keyHeldBit.test(ev.key.code))
		{
			keyHeldBit.set(ev.key.code);
			keyDownBit.set(ev.key.code);
		}
		break;
	case sf::Event::KeyReleased:
		keyHeldBit.reset(ev.key.code);
		keyUpBit.set(ev.key.code);
		break;

	case sf::Event::MouseButtonPressed:
		if (!mouseHeldBit.test(ev.mouseButton.button))
		{
			mouseHeldBit.set(ev.mouseButton.button);
			mouseDownBit.set(ev.mouseButton.button);
			mousePoint.x = ev.mouseButton.x;
			mousePoint.y = ev.mouseButton.y;
		}
		break;

	case sf::Event::MouseButtonReleased:
		mouseHeldBit.reset(ev.mouseButton.button);
		mouseUpBit.set(ev.mouseButton.button);
		break;

	default:
		break;
	}
}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	return keyDownBit.test(key);
}

bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return keyHeldBit.test(key);
}

bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return keyUpBit.test(key);
}

bool InputMgr::GetMouseDown(sf::Mouse::Button button)
{
	return mouseDownBit.test(button);
}

bool InputMgr::GetMouse(sf::Mouse::Button button)
{
	return mouseHeldBit.test(button);
}

bool InputMgr::GetMouseUp(sf::Mouse::Button button)
{
	return mouseUpBit.test(button);
}

sf::Vector2i InputMgr::GetMousePoint()
{
	return sf::Vector2i(mousePoint.x, mousePoint.y);
}
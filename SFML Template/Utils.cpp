#include "stdafx.h"
#include "Utils.h"
#include <random>

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
    sf::FloatRect rect = obj.getLocalBounds();

    sf::Vector2f newOrigin(rect.width, rect.height);

    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    obj.setOrigin(newOrigin);

    return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::Text& text, Origins preset)
{
    sf::FloatRect rect = text.getLocalBounds();

    sf::Vector2f newOrigin(rect.width, rect.height);

    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    text.setOrigin(newOrigin);

    return newOrigin;
}

int Utils::GetRandom(int start, int end)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(start, end);
    return dis(gen);
}

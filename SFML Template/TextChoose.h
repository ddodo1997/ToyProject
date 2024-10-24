#pragma once
#include "GameObject.h"
class TextChoose :
    public GameObject
{
protected:
	sf::Text text;
	std::string fontId;
	bool isTitle = false;
public:
	TextChoose(float x, float y, std::string id, std::string name, std::string str, int size);
	~TextChoose();

	void Init() override;
	void Release() override;
	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void SetString(const std::string str);
	void Draw(sf::RenderWindow& window) override;
	void Update(float dt)override;
	void SetOrigin(const sf::Vector2f& origin)override;
	void SetOrigin(Origins preset)override;
	void SetCharacterSize(int size);
};


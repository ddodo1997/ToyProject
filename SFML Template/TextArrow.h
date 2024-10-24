#pragma once
#include "GameObject.h"
class TextArrow :
    public GameObject
{
protected:
	sf::Text text;
	std::string fontId;
	bool isChoose = false;

public:
	static Arrow Location;
	TextArrow(float x, float y, std::string id, std::string name);
	~TextArrow();

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


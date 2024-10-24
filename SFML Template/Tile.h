#pragma once
#include "GameObject.h"
class Tile :
    public GameObject
{
private:
	sf::Sprite sprite;
	std::string textureId;
	static float speed;
public:
	Tile(float x, float y, const std::string& id);
	~Tile();
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetPosition(const sf::Vector2f& position) override;
	void SetOrigin(const sf::Vector2f& origin) override;
	void SetOrigin(Origins preset) override;
	void SetScale(float x, float y);
};


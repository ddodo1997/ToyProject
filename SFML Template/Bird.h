#pragma once
#include "GameObject.h"
class Bird :
    public GameObject
{
private:
	float speed;
	float accel;
	sf::Sprite sprite;
	std::string textureId;
public:
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetPosition(const sf::Vector2f& position) override;
	void SetOrigin(const sf::Vector2f& origin) override;
	void SetOrigin(Origins preset) override;
	void SetName(const std::string& name) override;
};


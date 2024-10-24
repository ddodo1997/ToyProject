#pragma once
#include "GameObject.h"

class Bird :
	public GameObject
{
private:
	sf::Sprite sprite;

	sf::Vector2f velocity;
	float gravity = 2.f;
	float jumpSpeed = 500.0f;
public:
	Bird(float x, float y, const std::string& name);
	virtual ~Bird();

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	void Jump();
	void SetPosition(const sf::Vector2f& position) override;
	void SetOrigin(const sf::Vector2f& origin) override;
	void SetOrigin(Origins preset) override;
	void SetScale(float x, float y);
};


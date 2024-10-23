#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Pipe : public GameObject
{
public:
	Pipe(float x, float y);
	virtual ~Pipe();

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetPosition(const sf::Vector2f& pos);
	void SetSpeed(float speed);
	void SetScale(float y);

private:
	sf::Sprite Body;
	static float Speed;
};
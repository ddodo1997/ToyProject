#pragma once
#include "stdafx.h"
#include "Scene.h"
class SpriteGo;
class SceneDev2 :  public Scene
{
private:
	std::vector<SpriteGo*> toppipe;
	std::vector<SpriteGo*> underpipe;
	float randhole[6];

public:
	SceneDev2();
	~SceneDev2() = default;

	virtual void Init() override;
	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

};


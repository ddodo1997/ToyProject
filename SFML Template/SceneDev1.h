#pragma once
#include "stdafx.h"
#include "Scene.h"
#include "SpriteGo.h"
#include "TextGo.h"

class SceneDev1 : public Scene
{
protected:
	const int numOfBackGrounds = 4;
	const int numOfTiles = 100;
	const int numOfBirds = 3;
	int arrowIndex = 0;
	bool isTitle = true;
public:
	SceneDev1();
	~SceneDev1() = default;
	virtual void Init() override;
	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

};


#pragma once
#include "GameObject.h"
class ChooseBirds :
    public GameObject
{
	sf::Sprite sprite;
	std::string textureId;
	bool isTitle = true;
public:
	ChooseBirds(float x, float y, const std::string& id, const std::string& name);
	virtual ~ChooseBirds();

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


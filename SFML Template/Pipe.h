#pragma once
#include "GameObject.h"
class Pipe :
    public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;

public:
	Pipe(const std::string& texId, const std::string& name = "");
	~Pipe() = default;


	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	void SetPosition(const sf::Vector2f& position) override;
	void SetOrigin(const sf::Vector2f& origin) override;
	void SetOrigin(Origins preset) override;
};


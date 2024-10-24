#pragma once
#include "GameObject.h"
class Pipe :
    public GameObject
{
protected:
	sf::Sprite sprite[6];
	sf::Sprite sprite2[6];

	std::string textIdUpper, textIdUnder;

	float random[6];
public:
	
	Pipe(const std::string& textIdUpper, const std::string& textIdUnder,  const std::string& name = "");
	~Pipe() = default;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	void SetPosition(const sf::Vector2f& position) override;
	void SetOrigin(const sf::Vector2f& origin) override;
	void SetOrigin(sf::Sprite sprite[], Origins preset);
	
};


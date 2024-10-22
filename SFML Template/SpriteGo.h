#pragma once

class SpriteGo : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;

public:
	SpriteGo(const std::string& texId, const std::string& name = "");
	~SpriteGo() = default;


	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Draw(sf::RenderWindow& window) override;

	void SetOrigin(const sf::Vector2f& origin)override;
	void SetOrigin(Origins preset)override;
};

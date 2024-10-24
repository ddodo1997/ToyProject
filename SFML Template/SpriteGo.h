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
	sf::Vector2f GetPosition() const;

	void SetOrigin(const sf::Vector2f& origin)override;
	void SetOrigin(Origins preset)override;

	void SetScale(const sf::Vector2f& scale);
	void Move(float a, float b);
};

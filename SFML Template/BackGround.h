#pragma once
class BackGround :
    public GameObject
{
private:
	sf::Sprite sprite;
	std::string textureId;
public:
	BackGround(float x, float y, const std::string& id);
	~BackGround();
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

#pragma once
#include "stdafx.h"
class GameObject
{
protected:
	std::string name;
	bool active = true;
	sf::Vector2f position;
	Origins originPreset;
	sf::Vector2f origin;

public:
	GameObject(const std::string& name = "");
	~GameObject() = default;

	bool IsActive() const { return active; }
	void SetActive(bool active) { this->active = active; }

	sf::Vector2f GetPosition() const { return position; }
	virtual void SetPosition(const sf::Vector2f& position) { this->position = position; }

	sf::Vector2f GetOrigin() const { return origin; }
	virtual void SetOrigin(const sf::Vector2f& origin) 
	{ 
		this->origin = origin; 
		originPreset = Origins::Custom;
	}
	virtual void SetOrigin(Origins preset);

	const std::string& GetName() const { return name; }
	virtual void SetName(const std::string& name) {this->name = name;}
	//ó�� ������ ��, �ʱ�ȭ ��
	virtual void Init();
	//�����Ҵ��� �ϰ��ִٸ�, �޸� ����
	virtual void Release();
	
	virtual void Reset();

	//Ȱ��ȭ �� ��ü�� �� ������ ������Ʈ�ϰ� ȭ�鿡 �׸�
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
};
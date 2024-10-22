#pragma once
#include "stdafx.h"

class Framework :public Singleton<Framework>
{
	friend Singleton<Framework>;
private:
	Framework() = default;
	~Framework() = default;
	Framework(const Framework& other) = delete;
	Framework& operator=(const Framework& other) = delete;

	sf::RenderWindow window;
	sf::Clock clock;

	float timeScale = 1.f;
	//timeScale�� ������ �޴� ���
	float time = 0.f;
	float deltaTime = 0.f;

	//timeScale�� ������ ���� �ʴ� ���
	float realTime = 0.f;
	float realDeltaTime = 0.f;
public:
	float GetTime()const { return time; }
	float GetDeltaTime()const { return deltaTime; }
	float GetRealTime()const { return realTime; }
	float GetRealDeltaTime()const { return realDeltaTime; }

	void SetTimeScale(float timeScale) { this->timeScale = timeScale; }
	float GetTimeScale() { return timeScale; }

	//���� �ʱ�ȭ
	virtual void Init(int width, int height, const std::string& title);
	//���� ����
	virtual void Do();
	//�޸� ����
	virtual void Release();
};


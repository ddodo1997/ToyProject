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
	//timeScale의 영향을 받는 멤버
	float time = 0.f;
	float deltaTime = 0.f;

	//timeScale의 영향을 받지 않는 멤버
	float realTime = 0.f;
	float realDeltaTime = 0.f;
public:
	float GetTime()const { return time; }
	float GetDeltaTime()const { return deltaTime; }
	float GetRealTime()const { return realTime; }
	float GetRealDeltaTime()const { return realDeltaTime; }

	void SetTimeScale(float timeScale) { this->timeScale = timeScale; }
	float GetTimeScale() { return timeScale; }

	//최초 초기화
	virtual void Init(int width, int height, const std::string& title);
	//메인 루프
	virtual void Do();
	//메모리 정리
	virtual void Release();
};


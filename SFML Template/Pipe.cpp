#include "stdafx.h"
#include "Pipe.h"

#define PIPE_PATH "graphics/toppipe.png"
float Pipe::Speed = 5.0f;

Pipe::Pipe(float x, float y)
{
	Body.setPosition(x, y);
}

Pipe::~Pipe()
{
}

void Pipe::Init()
{
	TEXTURE_MANAGER.Load(PIPE_PATH);
	auto& tex = TEXTURE_MANAGER.Get(PIPE_PATH);
	Body.setTexture(tex);
}

void Pipe::Release()
{
}

void Pipe::Reset()
{
}

void Pipe::Update(float dt)
{
	float newSpeed = Speed * -1.0f * dt;
	Body.move({ newSpeed, 0.0f });
}

void Pipe::Draw(sf::RenderWindow& window)
{
	window.draw(Body);
}

void Pipe::SetPosition(const sf::Vector2f& pos)
{
	Body.setPosition(pos);
}

void Pipe::SetSpeed(float speed)
{
	Speed = speed;
}

void Pipe::SetScale(float y)
{
	Body.scale(1.0f, y);
}

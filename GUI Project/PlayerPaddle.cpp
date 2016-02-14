#include "stdafx.h"
#include "PlayerPaddle.hpp"
#include "Game.hpp"

PlayerPaddle::PlayerPaddle() : _velocity(0), _maxVelocity(600.0f)
{
	Load("images/paddle.png");
	assert(IsLoaded());

	//GetSprite().setOrigin(GetSprite().)
}

PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::Update(float elapsedTime)
{
	if (Game::GetKeyboard().isKeyPressed(sf::Keyboard::Left))
	{
		_velocity -= 3.0f;
	}
	if (Game::GetKeyboard().isKeyPressed(sf::Keyboard::Right))
	{
		_velocity += 3.0f;
	}
	if (Game::GetKeyboard().isKeyPressed(sf::Keyboard::Down))
	{
		_velocity = 0.0f;
	}

	if (_velocity > _maxVelocity)
		_velocity = _maxVelocity;
	
	if (_velocity < -(_maxVelocity))
		_velocity = -(_maxVelocity);

	sf::Vector2f pos = this->GetPosition();

	//if(pos.x < GetSprite().Get)
}

void PlayerPaddle::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}

float PlayerPaddle::GetVelocity() const
{
	return _velocity;
}
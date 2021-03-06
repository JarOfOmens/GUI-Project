#include "stdafx.h"
#include "PlayerPaddle.hpp"
#include "Game.hpp"

PlayerPaddle::PlayerPaddle() : _velocity(0), _maxVelocity(1200.0f)
{
	Load("images/paddle.png");
	assert(IsLoaded());

	//Changed from original due to SFML v2.3
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
}

PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::Update(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_velocity -= 3.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_velocity += 3.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_velocity = 0.0f;
	}

	if (_velocity > _maxVelocity)
		_velocity = _maxVelocity;
	
	if (_velocity < -(_maxVelocity))
		_velocity = -(_maxVelocity);

	sf::Vector2f pos = this->GetPosition();

	if(pos.x < GetSprite().getLocalBounds().width / 2
		|| pos.x >(Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width / 2))
	{
		_velocity = -(_velocity);  //Bounce by current velocity in opposite direction
	}

	GetSprite().move(_velocity * elapsedTime, 0);
}

void PlayerPaddle::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}

float PlayerPaddle::GetVelocity() const
{
	return _velocity;
}

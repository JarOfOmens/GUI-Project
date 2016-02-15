#include "stdafx.h"
#include "GameBall.hpp"

GameBall::GameBall()
{
	Load("images/ball.png");
	assert(IsLoaded());

	GetSprite().setOrigin(15, 15);
}

GameBall::~GameBall()
{
}

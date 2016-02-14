#pragma once
#include "stdafx.h"
#include "VisibleGameObject.hpp"

class PlayerPaddle : public VisibleGameObject
{
public:
	PlayerPaddle();
	~PlayerPaddle();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

	float GetVelocity() const;

private:
	float _velocity; // -- left ++ right
	float _maxVelocity;
};
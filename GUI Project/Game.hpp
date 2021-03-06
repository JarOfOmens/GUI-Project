#pragma once
#include "stdafx.h"
#include "PlayerPaddle.hpp"
#include "GameObjectManager.hpp"
#include "GameBall.hpp"

class Game
{

public:
	static void Start();
	static sf::RenderWindow& GetWindow();
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

private:
	static bool IsExiting();
	static void GameLoop();

	static void ShowSplashScreen();
	static void ShowMenu();

	enum GameState {Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	
	static GameObjectManager _gameObjectManager;
};

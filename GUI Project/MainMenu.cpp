#include "stdafx.h"
#include "MainMenu.hpp"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	//Load menu image from file
	//sf::Image image;
	//image.loadFromFile("images/mainmenu.png");
	sf::Texture texture;
	texture.loadFromFile("images/mainmenu.png");
	sf::Sprite sprite(texture);

	//Setup clickable regions

	//Play menu item coordinates
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.left = 0;
	playButton.rect.height = 380 - playButton.rect.top;
	playButton.rect.width = 1023 - playButton.rect.left;
	playButton.action = Play;

	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.top = 383;
	exitButton.rect.left = 0;
	exitButton.rect.height = 560 - exitButton.rect.top;
	exitButton.rect.width = 1023 - exitButton.rect.left;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if ((menuItemRect.height + menuItemRect.top) > y
			&& menuItemRect.top < y
			&& menuItemRect.left < x
			&& (menuItemRect.width + menuItemRect.left) > x)
		{
			return(*it).action;
		}
	}
	
	return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while (true)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}
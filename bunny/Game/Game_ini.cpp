#include "Game_ini.hpp"

Game_ini::Game_ini(sf::RenderWindow& window)
{
	//go_to_option = *
	this->sky_texture.loadFromFile("Game/Textures/sky_back.jpg");
	this->forest_dark_texture.loadFromFile("Game/Textures/forest_back_dark.png");
	this->forest_mid_texture.loadFromFile("Game/Textures/forest_back_mid.png");
	this->forest_light_texture.loadFromFile("Game/Textures/forest_back_light.png");

	objects_ini(window);

	//usunac kursor
	//dodac sterowanie
}

uint8_t Game_ini::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	// ======================================================================================Backgroung====================================================================
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (uint8_t i = 0; i < skys.size(); i++)
		{
			skys[i].move_background(window, -1);
		}	
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (uint8_t i = 0; i < skys.size(); i++)
		{
			skys[i].move_background(window, 1);
		};
	}
	for (uint8_t i = 0; i < skys.size(); i++)
	{
		skys[i].system(window, mouse);
	}
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Backgroung:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::








	return 1;
}

void Game_ini::objects_ini(sf::RenderWindow& window)
{
	this->skys.push_back(Background(window, &sky_texture, 0, 0, 1));
	this->skys.push_back(Background(window, &sky_texture, 0, 1, 1));
	this->skys.push_back(Background(window, &forest_dark_texture, 1, 0, 2));
	this->skys.push_back(Background(window, &forest_dark_texture, 1, 1, 2));
	this->skys.push_back(Background(window, &forest_mid_texture, 1, 0, 3));
	this->skys.push_back(Background(window, &forest_mid_texture, 1, 1, 3));
	this->skys.push_back(Background(window, &forest_light_texture, 1, 0, 4));
	this->skys.push_back(Background(window, &forest_light_texture, 1, 1, 4));
}

void Game_ini::settings(uint8_t volume)
{
}

void Game_ini::draw(sf::RenderWindow& window)
{
	for (uint8_t i = 0; i < skys.size(); i++)
	{
		skys[i].draw(window);
	}
}

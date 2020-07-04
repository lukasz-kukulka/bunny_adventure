#include "Game_ini.hpp"

Game_ini::Game_ini(sf::RenderWindow& window)
{
	//go_to_option = *
	this->sky_texture.loadFromFile("Game/Textures/sky_back.jpg");
	this->skys.push_back(Background(window, &sky_texture, 0));
	this->skys.push_back(Background(window, &sky_texture, 1));
	//usunac kursor
	//dodac sterowanie
}

uint8_t Game_ini::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	for (uint8_t i = 0; i < skys.size(); i++)
	{
		skys[i].system(window, mouse);
	}
	return 1;
}

void Game_ini::objects_ini(sf::RenderWindow& window)
{
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

#include "Game_ini.hpp"

Game_ini::Game_ini(sf::RenderWindow& window)
{
	this->time_animation = 0;
	// ======================================================================================Textures====================================================================
	this->sky_texture.loadFromFile("Game/Textures/sky_back.jpg");
	this->forest_dark_texture.loadFromFile("Game/Textures/forest_back_dark.png");
	this->forest_mid_texture.loadFromFile("Game/Textures/forest_back_mid.png");
	this->forest_light_texture.loadFromFile("Game/Textures/forest_back_light.png");
	this->bunnys.loadFromFile("Game/Textures/player.png");
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Backgroung::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	this->objects_ini(window);
	this->time_animation = {0};
	//usunac kursor
	//dodac sterowanie
}

uint8_t Game_ini::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (uint8_t i = 0; i < skys.size(); i++)
		{
			skys[i].move_background(window, -1);
		}	
		for (uint8_t i = 0; i < player_bunny.size(); i++)
		{
			player_bunny[i].animation_play_method(true);
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

	time_animation = clock_animation.restart().asSeconds();
	for (uint8_t i = 0; i < player_bunny.size(); i++)
	{
		player_bunny[i].animations(time_animation);
	}
	return 1;
}

void Game_ini::objects_ini(sf::RenderWindow& window)
{
	// ======================================================================================Backgroung====================================================================
	this->skys.push_back(Background(window, &sky_texture, 0, 0, 1));
	this->skys.push_back(Background(window, &sky_texture, 0, 1, 1));
	this->skys.push_back(Background(window, &forest_dark_texture, 1, 0, 2));
	this->skys.push_back(Background(window, &forest_dark_texture, 1, 1, 2));
	this->skys.push_back(Background(window, &forest_mid_texture, 1, 0, 3));
	this->skys.push_back(Background(window, &forest_mid_texture, 1, 1, 3));
	this->skys.push_back(Background(window, &forest_light_texture, 1, 0, 4));
	this->skys.push_back(Background(window, &forest_light_texture, 1, 1, 4));
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Backgroung::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


	// ======================================================================================Player====================================================================
	this->player_bunny.push_back(Player(window, &bunnys, 0.1f));
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Player::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
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
	for (uint8_t i = 0; i < player_bunny.size(); i++)
	{
		player_bunny[i].draw(window);
	}
}

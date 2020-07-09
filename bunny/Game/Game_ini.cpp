#include "Game_ini.hpp"

Game_ini::Game_ini(sf::RenderWindow& window) :level_ini(window, game_level), background_ini(window, game_level)
{
	this->bunny_tex.loadFromFile("Game/Textures/player.png");

	this->time_animation = 0;
	this->objects_ini(window);
	this->time_animation = {0};
	this->game_level = 0;
	//usunac kursor
}

uint8_t Game_ini::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{	
		player_bunny[0].animation_play_method_left(false);
		player_bunny[0].animation_play_method_right(true);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player_bunny[0].animation_play_method_left(true);
		player_bunny[0].animation_play_method_right(false);
	}
	background_ini.system(window);
	
	time_animation = clock_animation.restart().asSeconds(); // ==============Player====================================================================
	for (uint8_t i = 0; i < player_bunny.size(); i++)
	{
		player_bunny[i].animations(time_animation);
	} // ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Player::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	return 1;
}

void Game_ini::objects_ini(sf::RenderWindow& window)
{
	// ======================================================================================Player====================================================================
	this->player_bunny.push_back(Player(window, &bunny_tex, 0.1f));
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Player::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
}

void Game_ini::settings(uint8_t volume)
{

}


void Game_ini::draw(sf::RenderWindow& window)
{
	level_ini.draw(window);
	background_ini.draw(window);
	for (auto i : player_bunny)
		i.draw(window);
}

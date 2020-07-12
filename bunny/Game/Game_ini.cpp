#include "Game_ini.hpp"

Game_ini::Game_ini(sf::RenderWindow& window) :level_ini(window), background_ini(window)
{
	this->bunny_tex.loadFromFile("Game/Textures/player.png");
	
	this->time_animation = 0;
	this->objects_ini(window);
	this->game_level = 0;
	this->view_game.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	this->view_game.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	window.setView(view_game);
}

uint8_t Game_ini::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{	
		player_bunny[0].animation_play_method_left(false);
		player_bunny[0].animation_play_method_right(true);
		view_game.move(1.0, 0.0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player_bunny[0].animation_play_method_left(true);
		player_bunny[0].animation_play_method_right(false);
		view_game.move(-1.0, 0.0);
	}

	background_ini.system(window, view_game, game_level);
	level_ini.system(window, game_level);

	time_animation = clock_animation.restart().asSeconds(); 
	for (uint8_t i = 0; i < player_bunny.size(); i++)
	{
		player_bunny[i].animations(time_animation);
	} 

	//this->view_game.setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));
	this->view_game.setCenter(player_bunny[0].get_position().x + player_bunny[0].get_global().x, view_game.getCenter().y);
	window.setView(view_game);
	return 1;
}

void Game_ini::objects_ini(sf::RenderWindow& window)
{
	this->player_bunny.push_back(Player(window, &bunny_tex, 0.1f));
}

void Game_ini::settings(uint8_t volume)
{

}


void Game_ini::draw(sf::RenderWindow& window)
{
	background_ini.draw(window);
	level_ini.draw(window);
	for (auto i : player_bunny)
		i.draw(window);
}

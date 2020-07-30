#include "Game_ini.hpp"

Game_ini::Game_ini(sf::RenderWindow& window) :level_ini(window), background_ini(window), colision()
{
	this->bunny_tex.loadFromFile("Game/Textures/player.png");
	
	this->time_animation = 0;
	this->time_directions = 0;
	this->objects_ini(window);
	this->game_level = 0;
	this->view_game.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	this->view_game.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	this->direction_enabled = true;
	window.setView(view_game);
}

uint8_t Game_ini::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	//std::cout << direction_enabled << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player_bunny[0].direction_player_out() == 100)
	{
		if (direction_enabled == true)
		{
			player_bunny[0].change_direction(1);
			direction_enabled = false;
		}
		else if (time_directions >= 50)
		{
			player_bunny[0].animation_directon(1);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player_bunny[0].direction_player_out() == 100)
	{
		if (direction_enabled == true)
		{
			player_bunny[0].change_direction(2);
			direction_enabled = false;
		}
		if (time_directions >= 100)
		{
			player_bunny[0].animation_directon(2);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player_bunny[0].direction_player_out() == 100)
	{
		if (time_directions >= 100)
		{

			player_bunny[0].jump_reset(10);
			player_bunny[0].animation_directon(0);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player_bunny[0].direction_player_out() == 100)
	{
		//std::cout << player_bunny[0].direction_animation_begin() << std::endl;
		if (time_directions >= 20)
		{
			player_bunny[0].animation_directon(3);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player_bunny[0].direction_player_out() == 100)
	{
		if (time_directions >= 20)
		{
			player_bunny[0].animation_directon(6);
		}
	}
	else
	{
		time_directions = clock_directions.restart().asMilliseconds();
		direction_enabled = true;
	}
	time_directions = clock_directions.getElapsedTime().asMilliseconds();
	//std::cout << colision.jump_player_available() << std::endl;
	if (view_game.getCenter().x - view_game.getSize().x / 2 >= 0 || player_bunny[0].get_position().x + player_bunny[0].get_global().x / 2 - view_game.getSize().x / 2 >= 0 &&
		view_game.getCenter().x + view_game.getSize().x / 2 <= level_ini.level_size().x)
	{
		this->view_game.setCenter(player_bunny[0].get_position().x + player_bunny[0].get_global().x / 2, view_game.getCenter().y);

	}

	background_ini.system(window, view_game, game_level);
	level_ini.system(window, game_level);

	time_animation = clock_animation.restart().asSeconds();
	for (uint8_t j = 0; j < player_bunny.size(); j++)
	{
		player_bunny[j].animations(time_animation);
		for (int i = 0; i < level_ini.no_tiles(); i++)
		{

			colision.colision(window, player_bunny[j].shape_player(), level_ini.tiles(i));

		}
	}
	colision.gravity(window, player_bunny[0].shape_player());
	//std::cout << " gravity " << std::endl;
	//this->view_game.setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));
	player_bunny[0].system();
	player_bunny[0].gravity_insert(colision.gravityY_out());
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

#include "Game_ini.hpp"

Game_ini::Game_ini(sf::RenderWindow& window) :level_ini(window), background_ini(window), colision()
{
	this->bunny_tex.loadFromFile("Game/Textures/player.png");
	this->time_animation = 0;
	this->time_directions = 0;
	this->objects_ini(window);
	this->game_level = 0;
	//this->level_size_map = level_ini.level_size();
	this->view_game.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2)); 
	this->view_game.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	this->direction_enabled = true;
	window.setView(view_game);
}

//Game_ini::~Game_ini()
//{
//}

uint8_t Game_ini::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	//std::cout << static_cast<int>(level_ini.level_size().x);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player_bunny[0].movement_enabled_changing(true);
		if (direction_enabled == true)
		{
			player_bunny[0].change_direction(1);
			direction_enabled = false;
		}

		if (player_bunny[0].direction_player_out() != 4 && time_directions >= 100)
		{
			player_bunny[0].animation_directon(1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && colision.player_stay_in_ground() == true)
		{
			player_bunny[0].animation_directon(4);
			player_bunny[0].jump_reset(10);
			player_bunny[0].animation_reset(1);
			colision.player_stay_in_ground_change(false);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player_bunny[0].movement_enabled_changing(true);
		if (direction_enabled == true)
		{
			player_bunny[0].change_direction(2);
			direction_enabled = false;
		}
		if (player_bunny[0].direction_player_out() != 5 && time_directions >= 100)
		{
			player_bunny[0].animation_directon(2);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && colision.player_stay_in_ground() == true)
		{
			player_bunny[0].animation_directon(5);
			player_bunny[0].jump_reset(10);
			player_bunny[0].animation_reset(1);
			colision.player_stay_in_ground_change(false);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player_bunny[0].direction_player_out() == 100)
	{
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && colision.player_stay_in_ground() == true)
	{
		//player_bunny[0].animation_directon(0);
		player_bunny[0].jump_reset(10);
		player_bunny[0].animation_reset(1);
		colision.player_stay_in_ground_change(false);
	}
	else
	{
		time_directions = clock_directions.restart().asMilliseconds();
		direction_enabled = true;
		player_bunny[0].movement_enabled_changing(false);
	}
	time_directions = clock_directions.getElapsedTime().asMilliseconds();
	if ((view_game.getCenter().x - view_game.getSize().x / 2 >= 0 || player_bunny[0].get_position().x + player_bunny[0].get_global().x / 2 - view_game.getSize().x / 2 >= 0) &&
		view_game.getCenter().x + view_game.getSize().x / 2 <= level_ini.level_size().x)
	{
		//std::cout << static_cast<int>(level_ini.level_size().x) << " ------ " << view_game.getCenter().x + view_game.getSize().x / 2 << std::endl;
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
	player_bunny[0].system();
	player_bunny[0].gravity_insert(colision.gravityY_out());
	window.setView(view_game); 
	this->colision.level_size_input(level_ini.level_size());
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

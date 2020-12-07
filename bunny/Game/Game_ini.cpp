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
	this->bonus_index = 0;
	window.setView(view_game);
}

//Game_ini::~Game_ini()
//{
//}

uint8_t Game_ini::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	window.setView(view_game);
	//colision.player_sprite_in(player_bunny[0].shape_player());
	//this->bonus_index++;
	//std::cout << static_cast<int>(bonus_index) << std::endl;
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

	player_bunny[0].animations(time_animation);
	//for (int i = 0; i < level_ini.no_tiles(); i++)
	//{
	//	//player_bunny[0].get_position().y
	//	//std::cout << "-----------------------" << level_ini.no_tiles() <<"   -----------     " << i << std::endl;
	//	colision.colision(window, level_ini.tiles(i));
	//	colision.tile_sprite_in(level_ini.tiles(i));
	//}
	
	player_bunny[0].system();
	player_bunny[0].gravity_insert(colision.gravityY_out());
	//window.setView(view_game); 
	colision.level_size_input(level_ini.level_size());
	//std::cout << level_ini.level_size().x << std::endl;
	colision.no_of_bonus_in(level_ini.no_of_bonus_out());    
	colision.player_sprite_in(player_bunny[0].shape_player());
	if (level_ini.no_tiles() > 0)
	{
		//std::cout << level_ini.no_tiles() << std::endl;
		for (int i = 0; i < level_ini.no_tiles(); i++)
		{
			colision.tile_sprite_in(level_ini.tiles(i));
			//std::cout << level_ini.tiles_type(i) << std::endl;
			colision.tiles_type_in(level_ini.tiles_type(i));
			
			if (level_ini.tiles_type(i) == 111)
			{
				//std::cout << i << " = i    tak :" << level_ini.tiles_type(i) << "  1tak :" << level_ini.tiles_type(i - level_ini.level_size().x / 100) << std::endl;
				for (int j = 0; j < level_ini.no_tiles(); j++)
				{
					if (level_ini.tiles(i)->getPosition().x == level_ini.tiles(j)->getPosition().x &&
						level_ini.tiles(i)->getPosition().y != level_ini.tiles(j)->getPosition().y - 100)
					{
						std::cout << "tak" << std::endl;
						colision.ledder_gravity_ground(true);
					}
					else
					{
						colision.ledder_gravity_ground(false);
					}
				}
			}
			colision.colision(window);
		}
	}


	if (level_ini.no_of_bonus_out() > 0)
	{
		for (bonus_index = 0; bonus_index < level_ini.no_of_bonus_out(); bonus_index++)
		{
			//std::cout << "-----------------------------------------" << bonus_index << std::endl;
			colision.bonus_sprite_in(level_ini.bonus_sprite_out(bonus_index));
			colision.colision_bonus();
			if (colision.catch_bonus() == true && colision.catch_bonus_one_time() == true)
			{
				level_ini.delete_bonus_yes(true, player_bunny[0].shape_player());
				level_ini.delete_bonus_ini(bonus_index);
				break;
			}
		}
	}
	colision.gravity();
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

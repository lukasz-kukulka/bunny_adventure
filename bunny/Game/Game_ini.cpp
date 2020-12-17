#include "Game_ini.hpp"

Game_ini::Game_ini(sf::RenderWindow& window) :level_ini(window), background_ini(window), interface_texts(window), colision()
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
	
	//std::cout << player_bunny[0].player_point_out() << std::endl;
	window.setView(view_game);
	interface_texts.system(view_game);
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player_bunny[0].direction_player_out() == 100 && ladder_movement_enable == true)
	{
		player_bunny[0].movement_enabled_changing(true);
		if (time_directions >= 20)
		{
			player_bunny[0].animation_directon(3);
			colision.player_stay_in_ground_change(false);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player_bunny[0].direction_player_out() == 100 && ladder_movement_enable == true)
	{
		if (time_directions >= 20)
		{
			player_bunny[0].animation_directon(6);
			colision.player_stay_in_ground_change(false);
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
		this->view_game.setCenter(player_bunny[0].get_position().x + player_bunny[0].get_global().x / 2, view_game.getCenter().y);
	}

	background_ini.system(window, view_game, game_level);
	level_ini.system(window, game_level);

	time_animation = clock_animation.restart().asSeconds();

	player_bunny[0].animations(time_animation);
	player_bunny[0].system();
	player_bunny[0].gravity_insert(colision.gravityY_out());
	//window.setView(view_game); 
	colision.level_size_input(level_ini.level_size());
	//std::cout << level_ini.level_size().x << std::endl;
	colision.no_of_bonus_in(level_ini.no_of_bonus_out());    
	colision.player_sprite_in(player_bunny[0].shape_player());
	colision.gravity_change(10);
	this->ladder_movement_enable = false;
	//this->ladder_movement_enable_animation = false;
	//std::cout << level_ini.no_tiles() << std::endl;
	for (int i = 0; i < level_ini.no_tiles(); i++)
	{
		colision.tile_sprite_in(level_ini.tiles(i));
		colision.tiles_type_in(level_ini.tiles_type(i));

		colision.colision(window);
		if (colision.ladder_colision(window) == 1)
		{
			//std::cout << "----------" << std::endl;
			colision.gravity_change(0);
			this->ladder_movement_enable = true;
		}
		//if (colision.ladder_colision(window) == 2)
		//{
		//	
		//	//colision.gravity_change(0);
		//	this->ladder_movement_enable_animation = true;
		//}
		//std::cout << "----------" << colision.ladder_colision(window) << std::endl;
	}
	if (ladder_movement_enable == false)
	{
		player_bunny[0].animation_finish(true);
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
				this->index_delete_bonus = level_ini.type_item_bonus_out(bonus_index);
				//std::cout << "-----------------------------------------" << static_cast<int>( index_delete_bonus) << std::endl;
				break;
			}
		}
	}
	if (level_ini.confirm_bonus_delete() == true && level_ini.no_of_bonus_out() > 0)
	{
		
		//std::cout << level_ini.no_of_bonus_out() << "        ----------------------------------------- >>>>>>>>>>>>>>>>>>>     " << static_cast<int>(index_delete_bonus) << std::endl;
		points_initialize(index_delete_bonus);
		std::cout << player_bunny[0].player_point_out() << std::endl;
	}
	interface_texts.score_points_in(player_bunny[0].player_point_out());
	interface_texts.no_of_level_in(level_ini.no_of_level_out());
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

void Game_ini::points_initialize(uint16_t index)
{
	//std::cout << index << std::endl;
			if (index == 1)
			{
				player_bunny[0].add_player_points(1);
			}
			else if (index == 2)
			{
				player_bunny[0].add_player_points(2);
			}
			else if (index == 3)
			{
				player_bunny[0].add_player_points(3);
			}
			else if (index == 4)
			{
				player_bunny[0].add_player_points(1);
			}
			else if (index == 5)
			{
				player_bunny[0].add_player_points(5);
			}
			else if (index == 6)
			{
				player_bunny[0].add_player_points(6);
			}
			else if (index == 7)
			{
				player_bunny[0].add_player_points(8);
			}
			else if (index == 8)
			{
				player_bunny[0].add_player_points(8);
			}
			else if (index == 9)
			{
				player_bunny[0].add_player_points(9);
			}
			else if (index == 10)
			{
				player_bunny[0].add_player_points(10);
			}
			else if (index == 11)
			{
				player_bunny[0].add_player_points(11);
			}
			else if (index == 12)
			{
				player_bunny[0].add_player_points(12);
			}
			//std::cout << "-----------------------------------------" << bonus_index << std::endl;

		

	
}


void Game_ini::draw(sf::RenderWindow& window)
{
	background_ini.draw(window);
	level_ini.draw(window);
	for (auto i : player_bunny)
		i.draw(window);
	interface_texts.draw(window);
}

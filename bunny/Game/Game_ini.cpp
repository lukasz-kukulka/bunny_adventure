#include "Game_ini.hpp"

Game_ini::Game_ini(sf::RenderWindow& window) 
		: level_ini(window)
		, background_ini(window)
		, interface_texts(window)
		, colision()
		, file_operations()
{
	this->bunny_tex.loadFromFile("Game/Textures/player.png");
	this->font_menu.loadFromFile("Game/Fonts/butler.ttf");
	this->time_animation = 0;
	this->time_directions = 0;
	this->objects_ini(window);
	this->game_level = 0;
	this->view_game.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2)); 
	this->view_game.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	this->direction_enabled = true;
	this->bonus_index = 0;
	window.setView(view_game);
	this->best_score_from_file = file_operations.load_best_score();
	interface_texts.best_score_in(&best_score_from_file);
	
}

uint8_t Game_ini::system(sf::RenderWindow& window, sf::Vector2i mouse)
{

	time_menu = menu_clock.getElapsedTime().asMilliseconds();
	window.setView(view_game);
	interface_texts.system(view_game);
	if (esc_stop_move == false && level_ini.turn_off_all_function_check() == false)
	{
		background_ini.system(window, view_game, game_level);
	}
	if (esc_stop_move == true)
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && time_menu >= 300)
		{
			this->position_esc_menu--;
			if (position_esc_menu < 0)
			{
				position_esc_menu = menu_esc[0].no_of_option_menu_out() - 1;
			}
			time_menu = menu_clock.restart().asMilliseconds();
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && time_menu >= 300)
		{
			this->position_esc_menu++;
			if (position_esc_menu > menu_esc[0].no_of_option_menu_out() - 1)
			{
				position_esc_menu = 0;
			}
			time_menu = menu_clock.restart().asMilliseconds();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && level_ini.turn_off_all_function_check() == false)
		{
			if (menu_esc[0].system(view_game, position_esc_menu) == 0)
			{
				menu_esc.erase(menu_esc.begin());
				time_menu = menu_clock.restart().asMilliseconds();
				this->esc_stop_move = false;
			}
			else if (menu_esc[0].system(view_game, position_esc_menu) == 1)
			{
				return 0;
			}
			else if (menu_esc[0].system(view_game, position_esc_menu) == 2)
			{
				return 5;
			}
		}
	}
	if (level_ini.turn_off_all_function_check() == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			if (menu_esc.size() == 0 && time_menu >= 300)
			{
				menu_esc.push_back(Menu_esc_in_game(view_game, 0, &font_menu));
				time_menu = menu_clock.restart().asMilliseconds();
				this->esc_stop_move = true;
			}
			else if (menu_esc.size() == 1 && time_menu >= 300)
			{
				menu_esc.erase(menu_esc.begin());
				time_menu = menu_clock.restart().asMilliseconds();
				this->esc_stop_move = false;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && esc_stop_move == false)
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
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && esc_stop_move == false)
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
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player_bunny[0].direction_player_out() == 100 && ladder_movement_enable == true && esc_stop_move == false)
		{
			player_bunny[0].movement_enabled_changing(true);
			if (time_directions >= 20)
			{
				player_bunny[0].animation_directon(3);
				colision.player_stay_in_ground_change(false);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player_bunny[0].direction_player_out() == 100 && ladder_movement_enable == true && esc_stop_move == false)
		{
			if (time_directions >= 20)
			{
				player_bunny[0].animation_directon(6);
				colision.player_stay_in_ground_change(false);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && colision.player_stay_in_ground() == true && esc_stop_move == false)
		{
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
		this->pressed_and_restart_new_level = false;
	}
	else if (esc_stop_move != true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && level_ini.game_over_ini_out() == false)
		{
			if (pressed_and_restart_new_level == false)
			{
				game_level++;
				level_ini.game_lvl_change(game_level);
				
				this->restart_player_level = true;
			}
			this->pressed_and_restart_new_level = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && level_ini.game_over_ini_out() == true && time_menu >= 300)
		{
			menu_esc.push_back(Menu_esc_in_game(view_game, 1, &font_menu));
			time_menu = menu_clock.restart().asMilliseconds();
			this->esc_stop_move = true;
		}			
	}
	else if (esc_stop_move == true)
		{
		if (game_over_frame_del == false)
		{
			level_ini.game_frame_delete();
			file_operations.add_new_score(player_bunny[0].player_point_out());
			game_over_frame_del = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && time_menu >= 300)
		{
			if (menu_esc[0].system(view_game, position_esc_menu) == 0)
			{
				menu_esc.erase(menu_esc.begin());
				time_menu = menu_clock.restart().asMilliseconds();
				this->esc_stop_move = false;
				return 0;
			}
			else if (menu_esc[0].system(view_game, position_esc_menu) == 1)
			{
				menu_esc.erase(menu_esc.begin());
				time_menu = menu_clock.restart().asMilliseconds();
				this->esc_stop_move = false;
				return 5;
			}
		}
		}
	if (menu_esc.size() > 0)
	{
		menu_esc[0].system(view_game, position_esc_menu);
	}
	time_directions = clock_directions.getElapsedTime().asMilliseconds();
	if (view_game.getCenter().x - view_game.getSize().x / 2 >= 0 && view_game.getCenter().x + view_game.getSize().x / 2 <= level_ini.level_size().x && 
		player_bunny[0].get_position().x + player_bunny[0].get_global().x / 2 - view_game.getSize().x / 2 >= 0 && 
		player_bunny[0].get_position().x + player_bunny[0].get_global().x / 2 <= level_ini.level_size().x - view_game.getSize().x / 2)
	{
		this->view_game.setCenter(player_bunny[0].get_position().x + player_bunny[0].get_global().x / 2, view_game.getCenter().y);
	}

	level_ini.system(window, game_level);
	time_animation = clock_animation.restart().asSeconds();
	player_bunny[0].animations(time_animation);
	player_bunny[0].system();
	player_bunny[0].gravity_insert(colision.gravityY_out());
	colision.level_size_input(level_ini.level_size());
	colision.no_of_bonus_in(level_ini.no_of_bonus_out());    
	colision.player_sprite_in(player_bunny[0].shape_player());
	colision.gravity_change(10);
	this->ladder_movement_enable = false;
	for (int i = 0; i < level_ini.no_tiles(); i++)
	{
		colision.tile_sprite_in(level_ini.tiles(i));
		colision.tiles_type_in(level_ini.tiles_type(i));

		colision.colision(window);
		if (colision.ladder_colision(window) == 1)
		{
			colision.gravity_change(0);
			this->ladder_movement_enable = true;
		}
	}
	if (ladder_movement_enable == false)
	{
		player_bunny[0].animation_finish(true);
	}


	if (level_ini.no_of_bonus_out() > 0)
	{
		for (bonus_index = 0; bonus_index < level_ini.no_of_bonus_out(); bonus_index++)
		{
			colision.bonus_sprite_in(level_ini.bonus_sprite_out(bonus_index));
			colision.colision_bonus();
			if (colision.catch_bonus() == true && level_ini.bonus_item_delete_confirm_out(bonus_index) == false)
			{
				level_ini.delete_bonus_yes(true, player_bunny[0].shape_player());
				level_ini.delete_bonus_ini(bonus_index);
				this->index_delete_bonus = level_ini.type_item_bonus_out(bonus_index);
				level_ini.bonus_item_delete_confirm(bonus_index);
				break;
			}
		}
	}
	if (level_ini.confirm_bonus_delete() == true && level_ini.no_of_bonus_out() > 0)
	{
		points_initialize(index_delete_bonus);
	}
	interface_texts.score_points_in(player_bunny[0].player_point_out());
	interface_texts.no_of_level_in(level_ini.no_of_level_out());
	level_ini.player_points_in(player_bunny[0].player_point_out());
	colision.gravity();
	level_ini.view_ini(view_game);
	if (restart_player_level == true)
	{
		player_reset(window);
		background_ini.backgroud_restart(window, view_game);
	}

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
	if (index == 1)
	{
		player_bunny[0].add_player_points(1);
	}
	else if (index == 2)
	{
		player_bunny[0].add_player_points(1);
	}
	else if (index == 3)
	{
		player_bunny[0].add_player_points(2);
	}
	else if (index == 4)
	{
		player_bunny[0].add_player_points(3);
	}
	else if (index == 5)
	{
		player_bunny[0].add_player_points(4);
	}
	else if (index == 6)
	{
		player_bunny[0].add_player_points(5);
	}
	else if (index == 7)
	{
		player_bunny[0].add_player_points(6);
	}
	else if (index == 8)
	{
		player_bunny[0].add_player_points(7);
	}
	else if (index == 9)
	{
		player_bunny[0].add_player_points(8);
	}
	else if (index == 10)
	{
		player_bunny[0].add_player_points(9);
	}
	else if (index == 11)
	{
		player_bunny[0].add_player_points(10);
	}
	else if (index == 12)
	{
		player_bunny[0].add_player_points(11);
	}
}

void Game_ini::player_reset(sf::RenderWindow& window)
{
	this->restart_player_level = false;
	player_bunny[0].player_restart_level(window);
	this->view_game.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	window.setView(view_game);
	this->background_ini.system(window, view_game, game_level);
}


void Game_ini::draw(sf::RenderWindow& window)
{
	background_ini.draw(window);
	level_ini.draw(window);
	for (auto i : player_bunny)
		i.draw(window);
	interface_texts.draw(window);
	for (auto i : menu_esc)
		i.draw(window);

}

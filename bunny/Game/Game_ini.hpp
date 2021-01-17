#pragma once
#include <SFML/Graphics.hpp>
#include "../Menu/Option.hpp"
#include "Background_ini.hpp"
#include "Player.hpp"
#include "Levels_ini.hpp"
#include "Colisions.hpp"
#include "Interface_text.hpp"
#include "../Menu/Files_operations.hpp"
#include "Menu_esc_in_game.hpp"

class Game_ini :public Option
{
public:
	Game_ini(sf::RenderWindow& window);
	uint8_t system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_ini(sf::RenderWindow& window);
	void settings(uint8_t volume);
	void points_initialize(uint16_t index);
	void draw(sf::RenderWindow& window);

private:
	uint8_t game_level;
	uint8_t index_delete_bonus{ 0 };
	uint16_t bonus_index;
	float time_animation, time_directions;
	sf::Texture bunny_tex;
	sf::Event event;
	std::vector<Player>player_bunny;
	sf::Clock clock_animation, clock_directions;
	Levels_ini level_ini;
	Background_ini background_ini;
	Colisions colision;
	std::vector<Menu_esc_in_game> menu_esc;
	//Menu_esc_in_game menu_esc;
	Interface_text interface_texts;
	sf::View view_game;
	bool direction_enabled;
	bool ladder_movement_enable{ false };
	bool confirm_delete_bonus_variable{ false };
	bool pressed_and_restart_new_level{ false };
	bool menu_esc_visible{ false };
	Files_operations file_operations;
};


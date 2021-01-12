#pragma once
#include <SFML/Graphics.hpp>
#include "Choise_level.hpp"
#include "Choise_lvl_bonus.hpp"
#include "Levels/Test_LVL.hpp"
#include "Levels/Pick_lvl_test.hpp"
#include "Object_lvl_ini.hpp"
#include "Level_end.hpp"
#include "Game_over.hpp"


class Levels_ini
{
public:
	Levels_ini(sf::RenderWindow& window);
	uint8_t system(sf::RenderWindow& window, uint8_t game_level);
	sf::Vector2i level_size();
	sf::Sprite* tiles(uint32_t index);
	uint16_t no_tiles();
	single_tile_out_for_bonus structure_bonuses(uint16_t index);
	void bonus_vector();
	uint16_t no_bonuses();
	sf::Sprite bonus_sprite_out(uint16_t index);
	uint16_t no_of_bonus_out();
	void delete_bonus_yes(bool index, sf::Sprite* player);
	void delete_bonus_ini(uint16_t index);
	uint16_t tiles_type(uint16_t index);
	uint8_t type_item_bonus_out(uint16_t index);
	bool confirm_bonus_delete();
	uint8_t no_of_level_out();
	void level_change();
	void start_new_lvl();
	void view_ini(sf::View& view);
	uint8_t game_lvl_out();
	void game_lvl_change(uint8_t lvl);
	void game_end_ini();
	bool turn_off_all_function_check();
	bool game_over_ini_out();
	void draw(sf::RenderWindow& window);

private:
	Choise_level* choise_level{ nullptr };
	Choise_lvl_bonus* choise_bonus{ nullptr };
	Test_LVL test_lvl;
	Pick_lvl_test pick_lvl_test;
	uint8_t game_lvl{ 0 };
	uint8_t level_indicator{ 99 };   // if lvl will be more levels than 99 changing this ////////////////////////////////////
	sf::Font font;
	sf::Vector2i lvl_size{ sf::Vector2i(0, 0) };
	sf::Sprite* player_pos{ nullptr };
	sf::Sprite* til_ini{ nullptr };
	sf::View view_level_ini;
	std::vector<single_tile_out_for_bonus>struct_bonus_out;
	std::vector<Level_end>level_end_vector;
	std::vector<Game_over>game_over;
	uint16_t no_til{ 0 };
	uint8_t bonus_delete_element{ 0 };
	uint8_t no_of_level{ 0 };
	bool bonus_yes{ true };
	bool bonus_delete_yes{ false };
	bool level_time_change{ false };
	bool turn_off_all_functions{ false };
	bool initialization_end_lvl_screen{ false };
	bool game_over_ini{ false };
	uint8_t last_level{ 1 }; // Always one more then maximum level

};


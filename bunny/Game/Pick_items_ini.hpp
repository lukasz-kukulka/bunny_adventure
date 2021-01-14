#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "Single_pick_bonus.hpp"
#include "Object_lvl_ini.hpp"
#include "Bonus_extra_effect.hpp"

class Pick_items_ini
{
public:
	Pick_items_ini(sf::RenderWindow& window);
	uint8_t system(sf::RenderWindow& window);
	uint16_t number_of_items_calculated();
	void single_pick_items_ini(sf::RenderWindow& window, uint8_t type);
	void bonus_parameters_ini(single_tile_out_for_bonus index);
	void bonus_quantity_in(uint16_t q);
	void no_of_tiles_in(uint16_t index);
	sf::Sprite bonus_sprite_out(uint16_t index);
	uint16_t no_of_bonus_out();
	uint16_t no_of_tiles_out();
	void animation_delete_bonus_ini(sf::RenderWindow& window);
	void player_mid_position(sf::Sprite* player);
	sf::Sprite* player_sprite_out();
	void delete_bonus_ele(uint16_t element_index);
	bool confirm_bonus_delete();
	uint8_t type_item_bonus_out(uint16_t index);
	void view_ini(sf::View& view);
	void delete_bonus_item_confirm(uint16_t index);
	bool delete_bonus_item_confirm_out(uint16_t index);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture awa501, awa502, awa503, awa504, awa505, awa506, awa507, awa508, awa509, awa510, awa511, awa512;
	sf::Font font;
	sf::View view_window;
	std::vector<Single_pick_bonus>bonuses;
	//std::vector<Single_pick_bonus>bonuses_before_delete;
	std::vector<single_tile_out_for_bonus>tiles_parameters;
	std::vector<int>teporary_tiles_tab;
	std::vector<Bonus_extra_effect>bonus_info;
	uint16_t bonus_quantity, tiles_quantity, random_pos;
	sf::Vector2f position_player_middle;
	sf::Sprite* player_sprite;
	bool bonus_position_ini;
	bool confirm_delete_variable{ false };
	bool animation_bonus_extra_effect{ false };
	//bool info_about_bonus{ false };
	//int aaa{ 0 }; // temporary variable

};


#pragma once
#include <SFML/Graphics.hpp>
#include "Object_lvl_ini.hpp"

class Choise_lvl_bonus
{
public:
	virtual uint8_t system(sf::RenderWindow& window) = 0;
	virtual void initialize_pick_class(sf::RenderWindow&) = 0;
	virtual void initialize_singe_bonus_item(sf::RenderWindow& window) = 0;
	virtual void bonus_parameters_ini(single_tile_out_for_bonus index) = 0;
	virtual void delete_bonus_elements(uint16_t element_index) = 0;
	virtual uint16_t no_of_bonus_out() = 0;
	virtual void no_of_tiles(uint16_t index) = 0;
	virtual sf::Sprite bonus_sprite_out(uint16_t index) = 0;
	virtual void player_mid_position(sf::Sprite* player) = 0;
	virtual uint8_t type_item_bonus_out(uint16_t index)= 0;
	virtual bool confirm_bonus_delete() = 0;
	virtual void view_ini(sf::View& view) = 0;
	virtual void delete_bonus_item_confirm(uint16_t index) = 0;
	virtual bool delete_bonus_item_confirm_out(uint16_t index) = 0;
	virtual void draw(sf::RenderWindow&) = 0;
};


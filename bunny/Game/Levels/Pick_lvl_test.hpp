#pragma once
#include <SFML/Graphics.hpp>
#include "../Pick_items_ini.hpp"
#include "../Choise_lvl_bonus.hpp"
#include "../Object_lvl_ini.hpp"

class Pick_lvl_test : public Choise_lvl_bonus
{
public:
	Pick_lvl_test(sf::RenderWindow& window);
	uint8_t system();
	void initialize_pick_class(sf::RenderWindow& window);
	void initialize_singe_bonus_item(sf::RenderWindow& window);
	void bonus_parameters_ini(single_tile_out_for_bonus index);
	void no_of_tiles(uint16_t index);
	sf::Sprite bonus_sprite_out(uint16_t index);
	void player_mid_position(sf::Sprite* player);
	uint16_t no_of_bonus_out();
	void delete_bonus_elements(uint16_t element_index);
	void draw(sf::RenderWindow& window);
private:
	uint8_t bonus501, bonus502, bonus503, bonus504, bonus505, bonus506, bonus507, bonus508, bonus509, bonus510, bonus511, bonus512;
	uint16_t bonus_quantity;
	//uint16_t no_tiles;
	std::vector<Pick_items_ini>bonus_ini;
	std::vector<single_tile_out_for_bonus>bonuses_vector;
};


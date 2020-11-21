#pragma once
#include <SFML/Graphics.hpp>
#include "Choise_level.hpp"
#include "Choise_lvl_bonus.hpp"
#include "Levels/Test_LVL.hpp"
#include "Levels/Pick_lvl_test.hpp"
#include "Object_lvl_ini.hpp"


class Levels_ini
{
public:
	Levels_ini(sf::RenderWindow& window);
	//~Levels_ini();
	uint8_t system(sf::RenderWindow& window, uint8_t game_level);
	sf::Vector2i level_size();
	sf::Sprite* tiles(uint32_t index);
	uint16_t no_tiles();
	single_tile_out_for_bonus structure_bonuses(uint16_t index);
	void bonus_vector();
	uint16_t no_bonuses();
	sf::Sprite bonus_sprite_out(uint16_t index);
	uint16_t no_of_bonus_out();
	void delete_bonus_yes(bool index);
	void delete_bonus_ini(uint16_t index);
	void draw(sf::RenderWindow& window);

private:
	Choise_level* choise_level;
	Choise_lvl_bonus* choise_bonus;
	Test_LVL test_lvl;
	//std::vector<Pick_lvl_test>test_lvl_pick;
	Pick_lvl_test pick_lvl_test;
	uint8_t game_lvl, level_indicator;
	sf::Vector2i lvl_size;
	sf::Sprite* til_ini;
	//uint32_t no_tile;
	std::vector<single_tile_out_for_bonus>struct_bonus_out;
	uint16_t no_til, bonus_delete_element;
	std::vector<single_tile_out_for_bonus>bonuses; // do usuniecia na koniec
	bool bonus_yes, bonus_delete_yes;
};


#pragma once
#include <SFML/Graphics.hpp>
#include "Choise_level.hpp"
#include "Levels/Test_LVL.hpp"
#include "Levels/Pick_lvl_test.hpp"


class Levels_ini
{
public:
	Levels_ini(sf::RenderWindow& window);

	uint8_t system(sf::RenderWindow& window, uint8_t game_level);
	sf::Vector2i level_size();
	sf::Sprite* tiles(uint32_t index);
	uint16_t no_tiles();
	void draw(sf::RenderWindow& window);

private:
	Choise_level* choise_level;
	Test_LVL test_lvl;
	Pick_lvl_test pick_lvl_test;
	uint8_t game_lvl;
	sf::Vector2i lvl_size;
	sf::Sprite* til_ini;
	//uint32_t no_tile;
	uint16_t no_til;
};


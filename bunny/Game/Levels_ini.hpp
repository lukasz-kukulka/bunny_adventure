#pragma once
#include <SFML/Graphics.hpp>
#include "Choise_level.hpp"
#include "Levels/Test_LVL.hpp"

class Levels_ini
{
public:
	Levels_ini(sf::RenderWindow& window);

	uint8_t system(sf::RenderWindow& window, uint8_t game_level);
	sf::Vector2i level_size();
	void draw(sf::RenderWindow& window);

private:
	Choise_level* choise_level;
	Test_LVL test_lvl;
	uint8_t game_lvl;
};

#pragma once
#include <SFML/Graphics.hpp>
#include "../Pick_items_ini.hpp"

class Pick_lvl_test
{
public:
	Pick_lvl_test(sf::RenderWindow& window);
	uint8_t system();
	void draw(sf::RenderWindow& window);
};


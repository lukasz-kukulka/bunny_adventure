#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Single_pick_bonus.hpp"

class Pick_items_ini
{
public:
	Pick_items_ini(sf::RenderWindow& window);
	uint16_t number_of_items_calculated();
	void single_pick_items_ini(sf::RenderWindow& window, uint8_t type);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture awa501, awa502, awa503, awa504, awa505, awa506, awa507, awa508, awa509, awa510, awa511, awa512;
	std::vector<Single_pick_bonus>bonuses;
};


#pragma once
#include <SFML/Graphics.hpp>

class Choise_lvl_bonus
{
public:

	virtual uint8_t system() = 0;
	virtual void initialize_pick_class(sf::RenderWindow&) = 0;
	virtual void initialize_singe_bonus_item(sf::RenderWindow& window) = 0;
	virtual void draw(sf::RenderWindow&) = 0;

};


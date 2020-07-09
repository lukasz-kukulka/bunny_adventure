#pragma once
#include <SFML/Graphics.hpp>

class Choise_level
{
public:
	
	virtual uint8_t system(sf::RenderWindow&) = 0;
	//virtual void settings(uint8_t) = 0;
	virtual void draw(sf::RenderWindow&) = 0;
};
#pragma once
#include <SFML/Graphics.hpp>

class Choise_level
{
public:
	
	virtual uint8_t system() = 0;
	virtual void objects_ini(sf::RenderWindow&, sf::Vector2i) = 0;
	virtual sf::Sprite* tiles(uint32_t index) = 0;
	virtual uint16_t no_til() = 0;
	virtual void draw(sf::RenderWindow&) = 0;
	virtual uint8_t bonus_size(uint8_t) = 0;
};
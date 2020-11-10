#pragma once
#include <SFML/Graphics.hpp>
#include "Object_lvl_ini.hpp"

class Choise_level
{
public:
	
	virtual uint8_t system() = 0;
	virtual void objects_ini(sf::RenderWindow&, sf::Vector2i) = 0;
	virtual sf::Sprite* tiles(uint32_t) = 0;
	virtual uint16_t no_til() = 0;
	virtual single_tile_out_for_bonus bonus_parameters(uint16_t index) = 0;
	virtual void draw(sf::RenderWindow&) = 0;
	//virtual uint8_t bonus_size(uint8_t) = 0;
};
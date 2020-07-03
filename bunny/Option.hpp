#pragma once
#include <SFML/Graphics.hpp>
class Option
{
public:
	virtual void draw(sf::RenderWindow&)=0;
	virtual uint8_t system(sf::RenderWindow&, sf::Vector2i)=0;
	virtual void settings(uint8_t) = 0;
};


#pragma once
#include <SFML/Graphics.hpp>
class Option
{
public:
	virtual void draw(sf::RenderWindow&)=0;
	virtual int system(sf::RenderWindow&, sf::Vector2i)=0;
};


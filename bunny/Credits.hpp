#pragma once
#include <SFML/Graphics.hpp>
#include "Option.hpp"

class Credits :public Option
{
public:
	Credits(sf::RenderWindow&);

	int system(sf::RenderWindow&, sf::Vector2i);
	void draw(sf::RenderWindow&);
};


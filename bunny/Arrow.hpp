#pragma once
#include <SFML/Graphics.hpp>

class Arrow
{
public:
	Arrow(sf::Texture&, int, int, double, double);

	int global_x();
	void draw(sf::RenderWindow&);

private:
	sf::Sprite arrow_sprite;
};

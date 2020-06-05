#pragma once
#include <SFML/Graphics.hpp>

class Arrow
{
public:
	Arrow(int, int, double, double, sf::Texture*);

	void draw(sf::RenderWindow&);

private:
	sf::Sprite arrow_sprite;
};

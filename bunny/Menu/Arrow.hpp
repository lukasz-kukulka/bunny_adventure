#pragma once
#include <SFML/Graphics.hpp>

class Arrow
{
public:
	Arrow(sf::Texture&, uint16_t, uint16_t, float, float);

	uint16_t global_x();
	void draw(sf::RenderWindow&);

private:
	sf::Sprite arrow_sprite;
};


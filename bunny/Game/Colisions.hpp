#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Colisions
{
public:
	Colisions();

	void gravity(sf::RenderWindow& window, sf::Sprite* player);
	void colision(sf::RenderWindow& window, sf::Sprite* player, sf::Sprite* tiles);
	void draw(sf::RenderWindow& window);
	int8_t gravityY_out();

private:
	int8_t gravityY, border;
	bool jump_available;
};


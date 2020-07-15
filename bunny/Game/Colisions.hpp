#pragma once
#include <SFML/Graphics.hpp>

class Colisions
{
public:
	Colisions();

	void gravity(sf::RenderWindow& window, sf::Sprite* player);
	void colision(sf::RenderWindow& window, sf::Sprite* player, sf::Sprite* tiles);
	void draw(sf::RenderWindow& window);

private:
	
};


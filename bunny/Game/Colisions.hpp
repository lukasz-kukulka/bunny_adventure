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
	bool jump_player_available();
	void jump_player_space_press(bool reset);
	int8_t gravityY_out();

private:
	int8_t gravityY;
	bool jump_available;
};


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
	bool player_stay_in_ground();
	void player_stay_in_ground_change(bool change);
	int8_t gravityY_out();

private:
	int8_t gravityY, border;
	bool jump_available, ground_yes_no;
};


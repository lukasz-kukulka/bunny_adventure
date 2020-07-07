#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Background
{
public:
	Background(sf::RenderWindow& window, sf::Texture* background_sky, uint8_t type_sprite, uint8_t index, uint8_t speed);
	uint8_t system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_ini(sf::RenderWindow& window);
	void move_background(sf::RenderWindow& window, int8_t direct_x);
	void draw(sf::RenderWindow& window);

private:
	sf::Sprite back_sprite;
	uint8_t index, type_sprite;
	float speed_f, movment_pooint_x;
};


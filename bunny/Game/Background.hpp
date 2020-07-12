#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Background
{
public:
	Background(sf::RenderWindow& window, sf::Texture* background_sky, uint8_t type_sprite, uint8_t index, float speed, sf::View& view_window);
	uint8_t system(sf::RenderWindow& window);
	void move_background_view(int8_t direct_x);
	void draw(sf::RenderWindow& window);

private:
	sf::Sprite back_sprite;
	uint8_t index, type_sprite;
	float speed_f, movment_pooint_x;
	sf::View view;
};


#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Game_over
{
public:
	Game_over(sf::View window, sf::Font* font, uint32_t points);
	uint8_t system();
	void draw(sf::RenderWindow& window);

private:
	sf::Text info_text;
	sf::RectangleShape rectangle;
	sf::View viewWindow;
	uint16_t system_clock{ 0 };
};
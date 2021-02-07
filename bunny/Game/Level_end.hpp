#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Level_end
{
public:
	Level_end(sf::View window, sf::Font* font, uint8_t level);
	uint8_t system(sf::View& window);
	uint8_t animation(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::Text info_text;
	sf::RectangleShape rectangle;
	sf::View viewWindow;
};


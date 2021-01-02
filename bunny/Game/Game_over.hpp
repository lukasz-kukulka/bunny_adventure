#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Game_over
{
public:
	Game_over(sf::View window, sf::Font* fontl);
	uint8_t system(sf::View& window);
	void draw(sf::RenderWindow& window);


private:
	sf::Text info_text;
	sf::RectangleShape rectangle;
	sf::View viewWindow;
};
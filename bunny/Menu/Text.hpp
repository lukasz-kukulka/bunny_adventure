#pragma once
#include <SFML/Graphics.hpp>
#include "Single_text.hpp"
#include <iostream>
class Text
{
public:
	Text(sf::RenderWindow& window, sf::Font* font, std::string text_string, uint16_t pos_x, uint16_t pos_y, uint8_t text_size, uint8_t type_sub);
	void create_single(sf::RenderWindow&);
	void reset();
	void draw(sf::RenderWindow&);

private:
	sf::Font single_font;
	sf::Text text;
	std::string temp_text;
	std::vector<Single_text>singles;
	uint16_t pos_x, pos_y, text_size, iterator, type_sub;
};


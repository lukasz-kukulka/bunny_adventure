#pragma once
#include <SFML/Graphics.hpp>
#include "Single_text.hpp"
#include <iostream>
class Text
{
public:
	Text(sf::RenderWindow&, sf::Font*, std::string, int, int, int, int);
	void create_single(sf::RenderWindow&);
	void reset();
	void draw(sf::RenderWindow&);

private:
	sf::Font single_font;
	sf::Text text;
	std::string temp_text;
	std::vector<Single_text>singles;
	int pos_x, pos_y, text_size, iterator, type_sub;
};


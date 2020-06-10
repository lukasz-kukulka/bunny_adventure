#pragma once
#include <SFML/Graphics.hpp>
class Single_text
{
public:
	Single_text(sf::RenderWindow&, sf::Font*, std::string, int, int, int, int, int);
	void draw(sf::RenderWindow&);
private:
	sf::Text text;
	int random_color_r, random_color_g, random_color_b, random_color_a, index_object, random_color_r_out, random_color_g_out, random_color_b_out, random_color_a_out;
};


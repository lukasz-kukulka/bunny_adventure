#pragma once
#include <SFML/Graphics.hpp>
class Single_text
{
public:
	Single_text(sf::RenderWindow& window, sf::Font* font, std::string sub, uint16_t pos_x, uint16_t pos_y, uint8_t index, uint8_t text_size, uint8_t type_sub);
	void draw(sf::RenderWindow&);

private:
	sf::Text text;
	uint8_t random_color_r, random_color_g, random_color_b, random_color_a, index_object, random_color_r_out, random_color_g_out, random_color_b_out, random_color_a_out;
};


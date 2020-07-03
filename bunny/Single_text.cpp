#include "Single_text.hpp"

Single_text::Single_text(sf::RenderWindow& window, sf::Font* font, std::string sub, uint16_t pos_x, uint16_t pos_y, uint8_t index, uint8_t text_size, uint8_t type_sub)
{
	this->index_object = index;
	this->random_color_r = (rand() % 254) + 1;
	this->random_color_g = (rand() % 254) + 1;
	this->random_color_b = (rand() % 254) + 1;
	this->random_color_a = (rand() % 254) + 1;
	this->random_color_r_out = (rand() % 254) + 1;
	this->random_color_g_out = (rand() % 254) + 1;
	this->random_color_b_out = (rand() % 254) + 1;
	this->random_color_a_out = (rand() % 254) + 1;
	this->text.setFont(*font);
	this->text.setString(sub);
	this->text.setCharacterSize(text_size);
	this->text.setFillColor(sf::Color(0, 0, 0, 255));
	this->text.setOutlineThickness(2);
	this->text.setOutlineColor(sf::Color(random_color_r_out, random_color_g_out, random_color_b_out, random_color_a_out));
	if (type_sub == 2)
		this->text.setPosition(pos_x + (index_object * text_size * 1.3), pos_y);
	else if (type_sub == 1)
		this->text.setPosition(pos_x + (index_object * text_size * 1.7), pos_y);
}

void Single_text::draw(sf::RenderWindow& window)
{
	window.draw(text);
}

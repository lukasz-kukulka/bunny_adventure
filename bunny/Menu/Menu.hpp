#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Arrow.hpp"


class Menu
{
public:
	Menu(sf::RenderWindow& window, sf::Texture*, sf::Texture*, sf::Texture*, sf::Texture*, sf::Texture*, sf::Font*, uint8_t, std::string);

	uint8_t mark(sf::RenderWindow&, sf::Vector2i);
	uint16_t begin_button_x();
	uint16_t end_button_x();
	uint16_t begin_button_y();
	float scale();
	void draw(sf::RenderWindow&);

private:
	sf::Texture* arrow_left, * arrow_right;
	sf::Sprite button_sprite_left, button_sprite_mid, button_sprite_right;
	sf::Text text_menu;
	uint8_t index_number, return_index;
	float scale_mid_sprite_x_mark, scale_mid_sprite_x;
	std::vector<Arrow>arrows;

};

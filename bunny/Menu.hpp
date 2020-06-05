#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Arrow.hpp"

class Menu 
{
public:
	Menu(sf::RenderWindow&, sf::Texture*, sf::Texture*, sf::Texture*, sf::Font*, int, std::string);

	int mark(sf::RenderWindow&, sf::Vector2i);

	void draw(sf::RenderWindow&);

private:
	sf::Sprite button_sprite_left, button_sprite_mid, button_sprite_right;
	sf::Text text_menu;

	int index_number;
	double scale_mid_sprite_x_mark, scale_mid_sprite_x;
	std::vector<Arrow>arrows;
};


#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.hpp"
#include "Option.hpp"


class Interface :public Option
{
public:
	Interface(sf::RenderWindow&);

	int system(sf::RenderWindow&, sf::Vector2i);
	void draw(sf::RenderWindow&); //draw interface

private:
	sf::Texture background_tex, menu_button_left, menu_button_mid, menu_button_right, arrow_left, arrow_right;
	sf::Sprite background_sprite;
	sf::Font font_menu_button;

	std::vector<Menu>button_menu;
	

	


};


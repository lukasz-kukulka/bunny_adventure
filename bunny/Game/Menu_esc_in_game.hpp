#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Singe_option_esc_menu.hpp"

class Menu_esc_in_game
{
public:
	Menu_esc_in_game(sf::View& window, uint8_t type_menu, sf::Font* font_text);
	~Menu_esc_in_game();
	uint8_t system(sf::View& window, uint8_t mark_single_menu);
	void objects_ini();
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape all_panel_top;
	sf::Font* font;
	bool menu_visible{ false };
	std::vector<Singe_option_esc_menu>single_option;
	uint8_t no_of_option_menu{ 3 };
};


#pragma once
#include <SFML/Graphics.hpp>

class Menu_esc_in_game
{
public:
	Menu_esc_in_game(sf::View& window, uint8_t type_menu);

	uint8_t system(sf::View& window);
	void objects_ini(sf::View& window);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape all_panel_top;
	bool menu_visible{ false };
};


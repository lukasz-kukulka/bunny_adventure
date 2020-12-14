#pragma once
#include <SFML/Graphics.hpp>
#include "Singe_interface_tile.hpp"
#include <iostream>

class Interface_text
{
public:
	Interface_text(sf::RenderWindow& window);
	void system(sf::View& window);
	void initialization_tiles_text(sf::RenderWindow& window);
	void score_points_in(int points);
	void life_player_in(uint8_t points);
	void draw(sf::RenderWindow& window);


private:
	sf::Font font_points;
	sf::Font font_life;
	sf::Font font_level;
	sf::Font font_bonus;
	sf::RectangleShape rectangle_panel_top;
	std::vector<Singe_interface_tile>text_tile;
	std::string score_points{ };
};


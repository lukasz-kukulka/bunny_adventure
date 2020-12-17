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
	void no_of_level_in(uint8_t index_level);
	void draw(sf::RenderWindow& window);


private:
	sf::Font font_points;
	sf::Font best_score;
	sf::Font font_level;
	sf::RectangleShape rectangle_panel_top;
	std::vector<Singe_interface_tile>text_tile;
	std::string score_points{ };
	sf::Texture life_texture;
	uint8_t max_life{ 5 };
	uint8_t min_life{ 1 };
	uint8_t no_of_level{ 0 };

};


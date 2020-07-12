#pragma once
#include <SFML/Graphics.hpp>
#include "Background.hpp"

class Background_ini
{
public:
	Background_ini(sf::RenderWindow& window);

	uint8_t system(sf::RenderWindow& window, sf::View& view_game, uint8_t lvl);
	void objects_ini(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture sky_texture, forest_light_texture, forest_mid_texture, forest_dark_texture;
	std::vector<Background>skys;
	uint8_t game_lvl;
	bool objects_ini_available;
	sf::View view_window;
};



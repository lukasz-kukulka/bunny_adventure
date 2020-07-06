#pragma once
#include <SFML/Graphics.hpp>
#include "../Menu/Option.hpp"
#include "Background.hpp"

class Game_ini :public Option
{
public:
	Game_ini(sf::RenderWindow& window);

	uint8_t system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_ini(sf::RenderWindow& window);
	void settings(uint8_t volume);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture sky_texture, forest_light_texture, forest_mid_texture, forest_dark_texture;
	std::vector<Background>skys;

	Option* go_to_option;
};


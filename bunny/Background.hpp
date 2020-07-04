#pragma once
#include <SFML/Graphics.hpp>

class Background
{
public:
	Background(sf::RenderWindow& window, sf::Texture* background_sky, uint8_t index);

	uint8_t system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_ini(sf::RenderWindow& window);
	void move_background(int8_t speed, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::Sprite sky_sprite;
	sf::Event event;
	uint8_t index;
};


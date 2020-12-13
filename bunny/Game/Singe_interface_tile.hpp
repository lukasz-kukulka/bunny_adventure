#pragma once
#include <SFML/Graphics.hpp>

class Singe_interface_tile
{
public:
	Singe_interface_tile(sf::Vector2f pos, std::string name_a, std::string name_b, sf::Vector2f size_tile, sf::Font* font);
	void draw(sf::RenderWindow& window);

private:
	sf::Text text;
	sf::RectangleShape text_frame;
};


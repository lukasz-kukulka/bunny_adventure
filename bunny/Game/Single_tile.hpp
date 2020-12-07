#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Single_tile
{
public:
	Single_tile(sf::RenderWindow& window, sf::Texture* tex, sf::Vector2f position, std::string type_tile);
	sf::Sprite* shape_sprite();
	sf::Vector2i position_tile();
	uint16_t return_type_tile();
	void draw(sf::RenderWindow& window);

private:
	sf::Sprite tile;
	uint16_t type_tiles{ 0 };
};


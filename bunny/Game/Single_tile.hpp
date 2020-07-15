#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Single_tile
{
public:
	Single_tile(sf::RenderWindow& window, sf::Texture* tex, sf::Vector2f position);
	sf::Sprite* shape_sprite();
	void draw(sf::RenderWindow& window);

private:
	sf::Sprite tile;
};


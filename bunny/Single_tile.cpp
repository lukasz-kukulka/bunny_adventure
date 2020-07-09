#include "Single_tile.hpp"

Single_tile::Single_tile(sf::RenderWindow& window, sf::Texture* tex, sf::Vector2f position)
{
	this->tile.setTexture(*tex);
	this->tile.setScale(1.0f, 1.0f );
	this->tile.setPosition(sf::Vector2f(position));
	this->tile.setColor(sf::Color(188, 255, 255, 0));
}

void Single_tile::draw(sf::RenderWindow& window)
{
	window.draw(tile);
}

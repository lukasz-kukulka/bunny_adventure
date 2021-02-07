#include "Single_tile.hpp"

Single_tile::Single_tile(sf::RenderWindow& window, sf::Texture* tex, sf::Vector2f position, std::string type_tile)
{
	this->type_tiles = stoi(type_tile);
	this->tile.setTexture(*tex);
	this->tile.setScale(1.0 / (*tex).getSize().x * 100, 1.0 / (*tex).getSize().x * 100);
	this->tile.setPosition(sf::Vector2f(position.x, position.y));
}

sf::Sprite* Single_tile::shape_sprite()
{
	return &tile;
}

sf::Vector2i Single_tile::position_tile()
{
	return sf::Vector2i(tile.getPosition().x, tile.getPosition().y);
}

uint16_t Single_tile::return_type_tile()
{
	return type_tiles;
}

void Single_tile::draw(sf::RenderWindow& window)
{
	window.draw(tile);
}

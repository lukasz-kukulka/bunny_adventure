#include "Single_tile.hpp"

Single_tile::Single_tile(sf::RenderWindow& window, sf::Texture* tex, sf::Vector2f position)
{
	this->tile.setTexture(*tex);
	this->tile.setScale(1.0 / (*tex).getSize().x * 100, 1.0 / (*tex).getSize().x * 100);
	this->tile.setPosition(sf::Vector2f(position.x, position.y));
	//this->tile.setColor(sf::Color(188, 255, 255, 222));
	//std::cout << tile.getPosition().x << " <<<<<<<<<<----->>>>>>>>> " << tile.getPosition().y << "\n";
	//std::cout << position.x << " CREATE " << position.y << "\n";
}

sf::Sprite* Single_tile::shape_sprite()
{
	return &tile;
}

sf::Vector2i Single_tile::position_tile()
{
	return sf::Vector2i(tile.getPosition().x, tile.getPosition().y);
}

void Single_tile::draw(sf::RenderWindow& window)
{
	window.draw(tile);
}

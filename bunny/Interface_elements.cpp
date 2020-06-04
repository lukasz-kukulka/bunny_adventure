#include "Interface_elements.hpp"

Interface_elements::Interface_elements(sf::Texture* texture, int pos_x, int pos_y, double scale_x, double scale_y)
{
	texture_sprite.setTexture(*texture);
	texture_sprite.setScale(scale_x, scale_y);
	texture_sprite.setPosition(pos_x, pos_y);
}



void Interface_elements::draw(sf::RenderWindow& window)
{
	window.draw(texture_sprite);
}

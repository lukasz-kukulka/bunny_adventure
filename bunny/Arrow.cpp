#include "Arrow.hpp"

Arrow::Arrow(int pos_x, int pos_y, double scale_x, double scale_y, sf::Texture* texture)
{
	arrow_sprite.setTexture(*texture);
	arrow_sprite.setScale(scale_x, scale_y);
	arrow_sprite.setPosition(pos_x, pos_y);
	arrow_sprite.setColor(sf::Color(255, 255, 255, 255));
}

void Arrow::draw(sf::RenderWindow& window)
{
	window.draw(arrow_sprite);
}

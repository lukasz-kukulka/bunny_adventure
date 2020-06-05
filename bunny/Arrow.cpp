#include "Arrow.hpp"

Arrow::Arrow(sf::Texture &texture, int pos_x, int pos_y, double scale_x, double scale_y)
{
	arrow_sprite.setTexture(texture);
	arrow_sprite.setScale(scale_x, scale_y);
	arrow_sprite.setPosition(pos_x, pos_y);
	arrow_sprite.setColor(sf::Color(255, 255, 255, 255));
}

int Arrow::global_x()
{
	return arrow_sprite.getGlobalBounds().width;
}

void Arrow::draw(sf::RenderWindow& window)
{
	window.draw(arrow_sprite);
}

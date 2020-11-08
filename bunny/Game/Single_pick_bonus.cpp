#include "Single_pick_bonus.hpp"

Single_pick_bonus::Single_pick_bonus(sf::RenderWindow& window, sf::Texture* texture, uint8_t type_of_item)
{
	this->bonus_sprite.setTexture(*texture);
	//this->bonus_sprite.setScale(1.0 / (*tex).getSize().x * 100, 1.0 / (*tex).getSize().x * 100);
	this->bonus_sprite.setPosition(sf::Vector2f(500, 500));
}

void Single_pick_bonus::draw(sf::RenderWindow& window)
{
	window.draw(bonus_sprite);
}

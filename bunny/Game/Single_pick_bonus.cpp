#include "Single_pick_bonus.hpp"

Single_pick_bonus::Single_pick_bonus(sf::RenderWindow& window, sf::Texture* texture, uint8_t type_of_item)
{
	this->bonus_sprite.setTexture(*texture);
	//this->bonus_sprite.setScale(1.0 / (*tex).getSize().x * 100, 1.0 / (*tex).getSize().x * 100);
	this->bonus_sprite.setPosition(sf::Vector2f(-1000, -1500));
	//std::cout << "BONUS CREATE" << std::endl;
}

void Single_pick_bonus::changing_bonus_position(sf::Vector2f position)
{
	bonus_sprite.setPosition(sf::Vector2f(position.x, position.y));
}

sf::Vector2f Single_pick_bonus::position_out()
{
	return sf::Vector2f(bonus_sprite.getPosition().x, bonus_sprite.getPosition().y);
}

sf::Vector2f Single_pick_bonus::globalbound_out()
{
	return sf::Vector2f(bonus_sprite.getGlobalBounds().width, bonus_sprite.getGlobalBounds().height);
}

sf::Sprite Single_pick_bonus::bonus_out()
{
	return bonus_sprite;
}

void Single_pick_bonus::draw(sf::RenderWindow& window)
{
	window.draw(bonus_sprite);
}

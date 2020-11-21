#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Single_pick_bonus
{
public:
	Single_pick_bonus(sf::RenderWindow& window, sf::Texture* texture, uint8_t type_of_item);
	//Single_pick_bonus(sf::RenderWindow& window, sf::Texture* texture, uint8_t id, uint8_t type_of_item, sf::Vector2i pos);
	void changing_bonus_position(sf::Vector2f position);
	sf::Vector2f position_out();
	sf::Vector2f globalbound_out();
	sf::Sprite bonus_out();
	void draw(sf::RenderWindow& window);
private:
	sf::Sprite bonus_sprite;
};


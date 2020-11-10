#pragma once
#include <SFML/Graphics.hpp>

class Single_pick_bonus
{
public:
	Single_pick_bonus(sf::RenderWindow& window, sf::Texture* texture, uint8_t type_of_item);
	//Single_pick_bonus(sf::RenderWindow& window, sf::Texture* texture, uint8_t id, uint8_t type_of_item, sf::Vector2i pos);
	void draw(sf::RenderWindow& window);
private:
	sf::Sprite bonus_sprite;
};


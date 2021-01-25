#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bonus_extra_effect.hpp"

class Single_pick_bonus
{
public:
	Single_pick_bonus(sf::RenderWindow& window, sf::Texture* texture, uint8_t type_of_item);
	~Single_pick_bonus();
	void changing_bonus_position(sf::Vector2f position);
	sf::Vector2f position_out();
	sf::Vector2f globalbound_out();
	sf::Sprite bonus_out();
	bool if_can_you_delete_item();
	void animation_delete();
	void animation_ini(sf::RenderWindow& window, sf::Sprite* player);
	bool animation_finish_out();
	void delete_item_confirm();
	uint8_t type_item_out();

	void draw(sf::RenderWindow& window);
private:
	sf::Sprite bonus_sprite;
	uint8_t type_item, animation_steps{ 0 };
	bool delete_item, animation_delete_start, animation_finish, animation_x_finished{ false }, animation_y_finished{ false };
	int8_t movement_bonus_x{ 2 }, movement_bonus_y{ 5 }, distanse_between_player_and_bonus_x{ 0 }, distanse_between_player_and_bonus_y{ -3 };
};


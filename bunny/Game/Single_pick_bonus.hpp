#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Single_pick_bonus
{
public:
	Single_pick_bonus(sf::RenderWindow& window, sf::Texture* texture, uint8_t type_of_item);
	Single_pick_bonus(sf::Texture* texture, uint8_t type_of_item, sf::Vector2f pos);
	//Single_pick_bonus(sf::RenderWindow& window, sf::Texture* texture, uint8_t id, uint8_t type_of_item, sf::Vector2i pos);
	void changing_bonus_position(sf::Vector2f position);
	sf::Vector2f position_out();
	sf::Vector2f globalbound_out();
	sf::Sprite bonus_out();
	bool if_can_you_delete_item();
	void animation_delete();
	void animation_ini(sf::Vector2f player_mid_pos);
	bool animation_finish_out();
	uint8_t type_item_out();
	//sf::Texture texture_out();

	void draw(sf::RenderWindow& window);
private:
	sf::Sprite bonus_sprite;
	//sf::Texture sprite_tex;
	uint8_t type_item;
	bool delete_item, animation_delete_start, animation_finish;

};


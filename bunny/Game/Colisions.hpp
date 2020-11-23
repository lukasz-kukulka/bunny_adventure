#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Colisions
{
public:
	Colisions();

	void gravity(sf::RenderWindow& window, sf::Sprite* player);
	void colision(sf::RenderWindow& window, sf::Sprite* player, sf::Sprite* tiles);
	void draw(sf::RenderWindow& window);
	bool player_stay_in_ground();
	void player_stay_in_ground_change(bool change);
	void level_size_input(sf::Vector2i size);
	void bonus_sprite_in(sf::Sprite bonus);
	void no_of_bonus_in(uint16_t index);
	void colision_bonus(sf::Sprite* player);
	//uint16_t bonus_no_initialize();
	//void bonus_index_incresed();
	bool catch_bonus();
	void player_sprite_in(sf::Sprite* player);
	int8_t gravityY_out();

private:
	sf::Sprite bonus_sprite;
	sf::Sprite* player_sprite;
	int8_t gravityY, border;
	uint16_t bonus_quantity, bonus_number;
	sf::Vector2i level_size;
	bool jump_available, ground_yes_no, catch_bonus_true;
};


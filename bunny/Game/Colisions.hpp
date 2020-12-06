#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Colisions
{
public:
	Colisions();

	void gravity();
	void colision(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	bool player_stay_in_ground();
	void player_stay_in_ground_change(bool change);
	void level_size_input(sf::Vector2i size);
	void bonus_sprite_in(sf::Sprite bonus);
	void no_of_bonus_in(uint16_t index);
	void colision_bonus();
	void tile_sprite_in(sf::Sprite* tiles);
	//uint16_t bonus_no_initialize();
	//void bonus_index_incresed();
	bool catch_bonus();
	bool catch_bonus_one_time();
	void catch_bonus_one_time_in(bool index);
	//void catch_change_to_false();
	void player_sprite_in(sf::Sprite* player);
	void free_memory();
	int8_t gravityY_out();

private:
	sf::Sprite bonus_sprite;
	sf::Sprite* player_sprite;
	sf::Sprite* tile_sprite;
	int8_t gravityY, border;
	uint16_t bonus_quantity, bonus_number;
	sf::Vector2i level_size;
	bool jump_available, ground_yes_no, catch_bonus_true, catch_bonus_one_time_true;
};


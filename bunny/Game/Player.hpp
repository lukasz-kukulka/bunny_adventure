#pragma once
#include <SFML/Graphics.hpp>
#include "Animations.hpp"
#include <iostream>
class Player
{
public:
	Player(sf::RenderWindow& window, sf::Texture* bunny, float time_animation);

	uint8_t system();
	void animations(float time_animation);
	sf::Sprite* shape_player();
	void objects_ini(sf::RenderWindow& window);
	void jump_reset(uint8_t size_jump);
	void jump_limits(float time_animation);
	void change_direction(uint8_t direction);
	void animation_directon(uint8_t dir);
	void movement_enabled_changing(bool yes_no);
	void animation_reset(uint8_t with_animation);
	uint8_t direction_player_out();
	uint8_t direction_animation_begin();
	sf::Vector2i get_position();
	sf::Vector2f get_global();
	void gravity_insert(int8_t grav);
	void animation_finish(bool index);
	void add_player_points(uint16_t points);
	uint8_t no_of_life_out();
	void no_of_life_change(int8_t life);
	void player_restart_level(sf::RenderWindow& window);
	unsigned int player_point_out();

	void draw(sf::RenderWindow& window);

private:
	sf::Texture* texture_animation;
	sf::IntRect window_animation;
	sf::Sprite player_sprite;
	std::vector<Animations>animation;
	unsigned int player_points{ 0 };
	uint8_t steps_animation_right_left, jump_size, directions, lines_of_animations, no_of_life{ 3 };
	int16_t jump_distans_max, jump_start_position, jump_max_position;
	int8_t gravitY, direction_player;
	float time_animations;
	bool animation_plays_right, animation_plays_left, jump_true, movement_enable, animation_end_variable{ false };
};


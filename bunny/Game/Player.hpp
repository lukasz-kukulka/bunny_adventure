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
	void jump_reset(uint8_t size_jump, int8_t gravityY);
	void change_direction(uint8_t direction);
	void animation_directon(uint8_t dir);
	uint8_t direction_player_out();
	sf::Vector2i get_position();
	sf::Vector2f get_global();
	void draw(sf::RenderWindow& window);

private:
	sf::Texture* texture_animation;
	sf::IntRect window_animation;
	sf::Sprite player_sprite;
	std::vector<Animations>animation;
	uint8_t steps_animation_right_left, jump_size, directions, lines_of_animations;
	int16_t jump_distans_max;
	int8_t gravitY, direction_player;
	float time_animations;
	bool animation_plays_right, animation_plays_left, jump_true;
};


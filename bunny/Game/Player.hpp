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
	void animation_play_method_right(bool play);
	void animation_play_method_left(bool play);
	void objects_ini(sf::RenderWindow& window);
	void jump();
	void jump_reset(uint8_t size_jump, int8_t gravityY);
	bool jump_available();
	sf::Vector2i get_position();
	sf::Vector2f get_global();
	void draw(sf::RenderWindow& window);

private:
	sf::Texture* texture_animation;
	sf::IntRect window_animation;
	sf::Sprite player_sprite;
	std::vector<Animations>animation;
	uint8_t steps_animation_right_left, jump_size;
	int16_t jump_distans_max;
	int8_t gravitY;
	float time_animations;
	bool animation_plays_right, animation_plays_left, jump_true;
};


#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Animations
{
public:
	Animations(sf::Sprite* object_sprite, uint8_t max_fram, uint8_t row);

	uint8_t system(float next_frame_time, sf::Sprite* object_sprite);
	void objects_ini(sf::RenderWindow& window);
	void reset_animation();
	void end_animation();
	void draw(sf::RenderWindow& window);
	void diretion_change(uint8_t dir, sf::Sprite* object_sprite);

private:
	sf::Vector2f start_pos;
	sf::RectangleShape window_animation;
	sf::IntRect window_animation_rec;
	float time_temp;
	uint8_t max_frame;
};


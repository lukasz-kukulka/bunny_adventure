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
	//bool end_animations();
	//void end_animation_change(bool yes);

private:
	sf::Vector2f start_pos;
	sf::RectangleShape window_animation;
	sf::IntRect window_animation_rec;
	float next_frame_time;
	float time_temp;
	int max_frame;
	//bool end_animation_player;
};


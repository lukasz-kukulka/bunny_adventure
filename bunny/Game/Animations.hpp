#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Animations
{
public:
	Animations(sf::Sprite* object, sf::Texture* text_object, uint8_t max_fram);

	uint8_t system(float next_frame_time, sf::Sprite* object_sprite);
	void objects_ini(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture* tex_object;
	sf::Sprite** object;
	sf::Vector2f start_pos;
	sf::RectangleShape window_animation;
	sf::IntRect window_animation_rec;
	float next_frame_time;
	float time_temp;
	int max_frame;
};


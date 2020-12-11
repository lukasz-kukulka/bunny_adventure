#include "Animations.hpp"

Animations::Animations(sf::Sprite * object_sprite, uint8_t max_frame, uint8_t row)
{
	//end_animation_player = true;
	this->max_frame = max_frame;
	this->next_frame_time = next_frame_time;
	this->time_temp = 0;
	this->window_animation_rec.width = object_sprite->getGlobalBounds().width;
	this->window_animation_rec.height = object_sprite->getGlobalBounds().height;
	this->window_animation_rec.left = 0.0f;
	this->window_animation_rec.top = row * window_animation_rec.height;
	object_sprite->setTextureRect(window_animation_rec);

}

uint8_t Animations::system(float next_frame_time, sf::Sprite* object_sprite)
{
	
	this->time_temp += next_frame_time;
	if (time_temp >= 0.1)
	{
		this->window_animation_rec.left += window_animation_rec.width;
		this->time_temp = 0;
		object_sprite->setTextureRect(window_animation_rec);
		if (window_animation_rec.left >= max_frame * window_animation_rec.width)
		{
			window_animation_rec.left = 0.0f;
			object_sprite->setTextureRect(window_animation_rec);

			return 1;
		}
	}
	return 0;
	
}

void Animations::reset_animation()
{
	this->window_animation_rec.left = 0.0f;
}

void Animations::end_animation()
{
	this->window_animation_rec.left = max_frame * window_animation_rec.width;
}

void Animations::diretion_change(uint8_t dir, sf::Sprite* object_sprite)
{
	this->window_animation_rec.left = 0.0f;
	this->window_animation_rec.top = dir * window_animation_rec.height;
	object_sprite->setTextureRect(window_animation_rec);
}


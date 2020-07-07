#include "Animations.hpp"

Animations::Animations(sf::Sprite *object_sprite, sf::Texture* text_object, uint8_t max_frame)
{
	this->max_frame = max_frame;
	object = &object_sprite;

	this->next_frame_time = next_frame_time;
	this->time_temp = 0;
	this->tex_object = text_object;
	this->window_animation_rec.width = (*object)->getGlobalBounds().width;
	this->window_animation_rec.height = (*object)->getGlobalBounds().height;
	this->window_animation_rec.left = 0.0f;
	this->window_animation_rec.top = 0.0f;
	(*object)->setTextureRect(window_animation_rec);
	(*object)->setTexture(*tex_object);
}

uint8_t Animations::system(float next_frame_time, sf::Sprite* object_sprite)
{
	this->time_temp += next_frame_time;
	if (time_temp >= 0.1)
	{

		this->window_animation_rec.left += window_animation_rec.width;

		this->time_temp = 0;
		object_sprite->setTextureRect(window_animation_rec);
		object_sprite->setTexture(*tex_object);
		if (window_animation_rec.left >= max_frame * window_animation_rec.width)
		{
			window_animation_rec.left = 0.0f;
			object_sprite->setTextureRect(window_animation_rec);
			object_sprite->setTexture(*tex_object);
			return 1;
		}
	}
	return 0;
}

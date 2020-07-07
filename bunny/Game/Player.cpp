#include "Player.hpp"

Player::Player(sf::RenderWindow& window, sf::Texture* bunny, float time_animation)
{
	this->steps_animation_right_left = 9;
	this->time_animations = time_animation;
	this->texture_animation = bunny;
	this->animation_plays = false;
	objects_ini(window);
}

uint8_t Player::system()
{
	return 0;
}

void Player::animations(float time_animation)
{
	if (animation_plays == true)
	{
		for (uint8_t i = 0; i < animation.size(); i++)
		{
			if (animation[i].system(time_animation, &player_sprite) == 1)
			{
				this->animation_plays = false;
			}
		}
	}

}

void Player::animation_play_method(bool play)
{
	this->animation_plays = true;
}



void Player::objects_ini(sf::RenderWindow& window)
{
	this->window_animation.width = texture_animation->getSize().x / steps_animation_right_left;
	this->window_animation.height = texture_animation->getSize().y;
	this->window_animation.left = 0.0f;
	this->window_animation.top = 0.0f;

	this->player_sprite.setTexture(*texture_animation);
	this->player_sprite.setTextureRect(window_animation);
	this->animation.push_back(Animations(&player_sprite, texture_animation, steps_animation_right_left));
}



void Player::draw(sf::RenderWindow& window)
{
	window.draw(player_sprite);
}

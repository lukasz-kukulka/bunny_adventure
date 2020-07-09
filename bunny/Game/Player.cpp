#include "Player.hpp"

Player::Player(sf::RenderWindow& window, sf::Texture* bunny, float time_animation)
{
	this->steps_animation_right_left = 9;
	this->time_animations = time_animation;
	this->texture_animation = bunny;
	this->animation_plays_right = false;
	this->animation_plays_left = false;
	objects_ini(window);
}

uint8_t Player::system()
{
	return 0;
}

void Player::animations(float time_animation)
{
	if (animation_plays_right == true)
	{
		this->animation_plays_left = false;
		if (animation[0].system(time_animation, &player_sprite) == 1)
		{
			this->animation_plays_right = false;
		}
	}
	if (animation_plays_left == true)
	{
		this->animation_plays_right = false;
		if (animation[1].system(time_animation, &player_sprite) == 1)
		{
			this->animation_plays_left = false;
		}
	}
}

void Player::animation_play_method_right(bool play)
{
	this->animation_plays_right = play;
}



void Player::animation_play_method_left(bool play)
{
	this->animation_plays_left = play;
}

void Player::objects_ini(sf::RenderWindow& window)
{
	this->window_animation.width = texture_animation->getSize().x / steps_animation_right_left;
	this->window_animation.height = texture_animation->getSize().y / 2;

	this->player_sprite.setTexture(*texture_animation);
	this->player_sprite.setTextureRect(window_animation);
	this->player_sprite.setPosition(window.getSize().x / 2 - player_sprite.getGlobalBounds().width / 2, window.getSize().y - 250);

	this->animation.push_back(Animations(&player_sprite, steps_animation_right_left, 0));
	this->animation.push_back(Animations(&player_sprite, steps_animation_right_left, 1));
}



void Player::draw(sf::RenderWindow& window)
{
	window.draw(player_sprite);
}

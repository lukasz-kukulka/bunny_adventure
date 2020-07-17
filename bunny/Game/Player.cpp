#include "Player.hpp"

Player::Player(sf::RenderWindow& window, sf::Texture* bunny, float time_animation)
{
	this->steps_animation_right_left = 9;
	this->time_animations = time_animation;
	this->texture_animation = bunny;
	this->animation_plays_right = false;
	this->animation_plays_left = false;
	this->jump_distans_max = 0;
	this->jump_size = 0;
	this->jump_true = true;
	this->gravitY = 0;
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
		this->player_sprite.move(2, 0);
		this->animation_plays_left = false;
		if (animation[0].system(time_animation, &player_sprite) == 1)
		{
			this->animation_plays_right = false;
		}
	}
	if (animation_plays_left == true)
	{
		this->player_sprite.move(-2, 0);
		this->animation_plays_right = false;
		if (animation[1].system(time_animation, &player_sprite) == 1)
		{
			this->animation_plays_left = false;
		}
	}
}

sf::Sprite* Player::shape_player()
{
	return &player_sprite;
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
	this->player_sprite.setPosition(window.getSize().x / 2 - player_sprite.getGlobalBounds().width / 2, 250);

	this->animation.push_back(Animations(&player_sprite, steps_animation_right_left, 0));
	this->animation.push_back(Animations(&player_sprite, steps_animation_right_left, 1));
}

void Player::jump()
{
	//std::cout << " SPACE   " << static_cast<int>(jump_distans_max) << std::endl;
	if (jump_distans_max > 0)
	{
		this->player_sprite.move(0, -(jump_size + gravitY));
		this->jump_distans_max -= jump_size;
	}
	else
	{
		this->jump_distans_max = 0;
		jump_true = true;
	}
		
}

void Player::jump_reset(uint8_t size_jump, int8_t gravityY)
{
	jump_true = false;
	if (this->jump_distans_max <= size_jump)
	{
		//std::cout << " SPACE   " << jump_distans_max << std::endl;
		this->jump_size = size_jump;
		this->gravitY = gravityY;
		this->jump_distans_max = 200;
	}
}

bool Player::jump_available()
{
	return jump_true;
}

sf::Vector2i Player::get_position()
{
	return sf::Vector2i(player_sprite.getPosition());
}

sf::Vector2f Player::get_global()
{
	return sf::Vector2f(player_sprite.getGlobalBounds().width, player_sprite.getGlobalBounds().height);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(player_sprite);
}

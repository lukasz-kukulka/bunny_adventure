#include "Player.hpp"

Player::Player(sf::RenderWindow& window, sf::Texture* bunny, float time_animation)
{
	this->movement_enable = false;
	this->direction_player = 100;
	this->steps_animation_right_left = 9;
	this->lines_of_animations = 9;
	this->time_animations = time_animation;
	this->texture_animation = bunny;
	this->animation_plays_right = false;
	this->animation_plays_left = false;
	this->jump_distans_max = 0;
	this->jump_size = 0;
	this->jump_true = true;
	this->gravitY = 0;
	this->directions = 1;
	objects_ini(window);
}

uint8_t Player::system()
{
	return 0;
}

void Player::animations(float time_animation)
{
	std::cout << "----->  " << static_cast<int>(direction_player) << std::endl;
	switch (direction_player)
	{
	case 0:
	{

		jump_limits(time_animation);

		if (directions == 1)
		{
			if (animation[1].system(time_animation, &player_sprite) == 1)
			{
				this->direction_player = 100;
			}
		}
		if (directions == 2)
		{
			if (animation[2].system(time_animation, &player_sprite) == 1)
			{
				this->direction_player = 100;
			}
		}
		break;
	}
	case 1:
	{
		if (movement_enable == true)
		{
			this->player_sprite.move(3, 0);
			//std::cout << "event";
		}
		if (animation[1].system(time_animation, &player_sprite) == 1)
		{
			this->direction_player = 100;
		}
		break;
	}
	case 2:
	{
		if (movement_enable == true)
		{
			this->player_sprite.move(-3, 0);
		}
		//this->player_sprite.move(-3, 0);
		if (animation[2].system(time_animation, &player_sprite) == 1)
		{
			this->direction_player = 100;
		}
		break;
	}
	case 3:
	{
		this->player_sprite.move(0, -2 - gravitY);
		if (directions == 2)
		{
			if (animation[3].system(time_animation, &player_sprite) == 1)
			{
				this->direction_player = 100;
			}
		}
		if (directions == 1)
		{
			if (animation[4].system(time_animation, &player_sprite) == 1)
			{
				this->direction_player = 100;
			}
		}
		break;
	}
	case 4:
	{
		if (movement_enable == true)
		{
			this->player_sprite.move(4, 0);
			//std::cout << "event";
		}
		
		jump_limits(time_animation);
		if (animation[1].system(time_animation, &player_sprite) == 1)
		{
			this->direction_player = 100;
		}
		break;
	}
	case 5:
	{
		if (movement_enable == true)
		{
			this->player_sprite.move(-4, 0);
			//std::cout << "event";
		}
		//this->player_sprite.move(-4, 0);
		jump_limits(time_animation);
		if (animation[2].system(time_animation, &player_sprite) == 1)
		{
			this->direction_player = 100;
		}
		break;
	}
	case 6:
	{
		this->player_sprite.move(0, 2);
		if (directions == 2)
		{
			if (animation[3].system(time_animation, &player_sprite) == 1)
			{
				this->direction_player = 100;
			}
		}
		if (directions == 1)
		{
			if (animation[4].system(time_animation, &player_sprite) == 1)
			{
				this->direction_player = 100;
			}
		}
		break;
	}
	case 7:
	{

		break;
	}
	case 8:
	{

		break;
	}
	case 9:
	{

		break;
	}
	default:
		break;
	}
	//this->movement_enable = false;
}

sf::Sprite* Player::shape_player()
{
	return &player_sprite;
}

void Player::objects_ini(sf::RenderWindow& window)
{
	this->window_animation.width = texture_animation->getSize().x / steps_animation_right_left;
	this->window_animation.height = texture_animation->getSize().y / lines_of_animations;

	this->player_sprite.setTexture(*texture_animation);
	this->player_sprite.setTextureRect(window_animation);
	this->player_sprite.setPosition(window.getSize().x / 2 - player_sprite.getGlobalBounds().width / 2, 250);

	this->animation.push_back(Animations(&player_sprite, steps_animation_right_left, 0));
	this->animation.push_back(Animations(&player_sprite, steps_animation_right_left, 1));
	this->animation.push_back(Animations(&player_sprite, steps_animation_right_left, 2));
	this->animation.push_back(Animations(&player_sprite, steps_animation_right_left, 3));
	this->animation.push_back(Animations(&player_sprite, steps_animation_right_left, 4));
}

void Player::jump_reset(uint8_t size_jump)
{
	if (this->jump_distans_max <= size_jump && jump_true == true)
	{
		this->jump_size = size_jump;
		this->jump_distans_max = 300;
		this->jump_true = false;
	}
}

void Player::jump_limits(float time_animation)
{
	if (jump_distans_max > 0)
	{
		this->player_sprite.move(0, -(jump_size + gravitY));
		this->jump_distans_max -= jump_size;
	}
	else
	{
		this->jump_distans_max = 0;
		this->jump_true = true;
	}
	//if (animation[0].system(time_animation, &player_sprite) == 1)
	//{
	//	this->direction_player = 100;
	//}
}

void Player::change_direction(uint8_t direction)
{
	this->directions = direction;
	this->animation[directions].diretion_change(directions, &player_sprite);
}

void Player::animation_directon(uint8_t dir)
{
	this->direction_player = dir;
}

void Player::movement_enabled_changing(bool yes_no)
{
	this->movement_enable = yes_no;
}

void Player::animation_reset(uint8_t with_animation)
{
	animation[with_animation].reset_animation();
}

uint8_t Player::direction_player_out()
{
	return direction_player;
}

uint8_t Player::direction_animation_begin()
{
	return directions;
}

sf::Vector2i Player::get_position()
{
	return sf::Vector2i(player_sprite.getPosition());
}

sf::Vector2f Player::get_global()
{
	return sf::Vector2f(player_sprite.getGlobalBounds().width, player_sprite.getGlobalBounds().height);
}

void Player::gravity_insert(int8_t grav)
{
	gravitY = grav;
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(player_sprite);
}

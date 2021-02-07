#include "Colisions.hpp"

Colisions::Colisions()
{
	this->gravityY = 10;
	this->border = 20;
	this->level_size = sf::Vector2i(10000, 0);
	this->ground_yes_no = false;
	this->catch_bonus_true = false;
	this->catch_bonus_one_time_true = true;
	this->bonus_quantity = 0;
	this->bonus_number = 0;
}

void Colisions::gravity()
{
	player_sprite->move(0, gravityY);

}

void Colisions::colision(sf::RenderWindow& window)
{
	if (player_sprite->getPosition().x <= 0)
	{
		player_sprite->setPosition(0, player_sprite->getPosition().y);
	}
	if (player_sprite->getPosition().x + player_sprite->getGlobalBounds().width >= level_size.x)
	{
		player_sprite->setPosition(level_size.x - player_sprite->getGlobalBounds().width, player_sprite->getPosition().y);
	}
	if (player_sprite->getPosition().y + player_sprite->getGlobalBounds().height >= tile_sprite->getPosition().y &&
		player_sprite->getPosition().y + player_sprite->getGlobalBounds().height < tile_sprite->getPosition().y + tile_sprite->getGlobalBounds().height  &&
		player_sprite->getPosition().x + player_sprite->getGlobalBounds().width - border > tile_sprite->getPosition().x &&
		player_sprite->getPosition().x + border < tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width && tiles_type != 111)
	{

		player_sprite->setPosition(player_sprite->getPosition().x, tile_sprite->getPosition().y - player_sprite->getGlobalBounds().height - gravityY);
		this->ground_yes_no = true;
	}
	else if (player_sprite->getPosition().y + border <= tile_sprite->getPosition().y + tile_sprite->getGlobalBounds().height &&
		player_sprite->getPosition().y >= tile_sprite->getPosition().y + tile_sprite->getGlobalBounds().height - tile_sprite->getGlobalBounds().height / 3 * 2&&
		player_sprite->getPosition().x + player_sprite->getGlobalBounds().width - border > tile_sprite->getPosition().x &&
		player_sprite->getPosition().x + border < tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width && tiles_type != 111)
	{
		player_sprite->setPosition(player_sprite->getPosition().x, tile_sprite->getPosition().y + tile_sprite->getGlobalBounds().height - border);
	}

	if (player_sprite->getPosition().y + player_sprite->getGlobalBounds().height == tile_sprite->getPosition().y + tile_sprite->getGlobalBounds().height &&
		player_sprite->getPosition().y + player_sprite->getGlobalBounds().height >= tile_sprite->getPosition().y &&
		player_sprite->getPosition().x + player_sprite->getGlobalBounds().width - border >= tile_sprite->getPosition().x &&
		player_sprite->getPosition().x + player_sprite->getGlobalBounds().width - border <= tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width / 3 && tiles_type != 111)
	{
		player_sprite->setPosition(tile_sprite->getPosition().x - player_sprite->getGlobalBounds().width + border, player_sprite->getPosition().y);
	}
	else if (player_sprite->getPosition().y + player_sprite->getGlobalBounds().height == tile_sprite->getPosition().y + tile_sprite->getGlobalBounds().height &&
		player_sprite->getPosition().y + player_sprite->getGlobalBounds().height >= tile_sprite->getPosition().y + 10 && 
		player_sprite->getPosition().x + border <= tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width &&
		player_sprite->getPosition().x + border >= tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width / 3 * 2 && tiles_type != 111)
	{
		player_sprite->setPosition(tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width - border, player_sprite->getPosition().y);
	}
}

uint8_t Colisions::ladder_colision(sf::RenderWindow& window)
{
	if (player_sprite->getPosition().y + player_sprite->getGlobalBounds().height >= tile_sprite->getPosition().y &&
		player_sprite->getPosition().y + player_sprite->getGlobalBounds().height <= tile_sprite->getPosition().y + tile_sprite->getGlobalBounds().height &&
		player_sprite->getPosition().x + player_sprite->getGlobalBounds().width - border * 3 > tile_sprite->getPosition().x &&
		player_sprite->getPosition().x + border * 3 < tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width && tiles_type == 111)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

bool Colisions::player_stay_in_ground()
{
	return ground_yes_no;
}

void Colisions::player_stay_in_ground_change(bool change)
{
	this->ground_yes_no = change;
}

void Colisions::level_size_input(sf::Vector2i size)
{
	this->level_size = size;
}

void Colisions::bonus_sprite_in(sf::Sprite bonus)
{
	this->bonus_sprite = bonus;
}

void Colisions::no_of_bonus_in(uint16_t index)
{
	this->bonus_quantity = index;
}

void Colisions::colision_bonus()
{
	if (player_sprite->getPosition().x + player_sprite->getGlobalBounds().width > bonus_sprite.getPosition().x &&
		player_sprite->getPosition().x < bonus_sprite.getPosition().x + bonus_sprite.getGlobalBounds().width &&
		player_sprite->getPosition().y + player_sprite->getGlobalBounds().height > bonus_sprite.getPosition().y &&
		player_sprite->getPosition().y < bonus_sprite.getPosition().y + bonus_sprite.getGlobalBounds().height)
	{
		this->catch_bonus_true = true;

	}
	else
	{
		this->catch_bonus_true = false;
	}
}

void Colisions::tile_sprite_in(sf::Sprite* tiles)
{
	tile_sprite = tiles;
}

bool Colisions::catch_bonus()
{
	return catch_bonus_true;
}

void Colisions::player_sprite_in(sf::Sprite* player)
{
	player_sprite = player;
}

void Colisions::tiles_type_in(uint16_t value)
{
	this->tiles_type = value;
}

void Colisions::ledder_gravity_ground(bool index)
{
	this->ledder_gravity_botton_bool = index;
}

int8_t Colisions::gravityY_out()
{
	return gravityY;
}

void Colisions::gravity_change(uint8_t index)
{
	this->gravityY = index;
}

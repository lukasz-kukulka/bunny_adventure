#include "Colisions.hpp"

Colisions::Colisions()
{
	this->gravityY = 10;
	this->border = 20;
	this->level_size = sf::Vector2i(10000, 0);// uwazac bo z ta wartoscia bedzie zaczynal player
	this->ground_yes_no = false;
	this->catch_bonus_true = false;
	this->catch_bonus_one_time_true = true;
	this->bonus_quantity = 0;
	this->bonus_number = 0;
	//this->player_sprite = nullptr;
}

void Colisions::gravity()
{
	player_sprite->move(0, gravityY);

}

void Colisions::colision(sf::RenderWindow& window)
{
	//std::cout << "PLAYER ---> " << player_sprite->getPosition().x + player_sprite->getGlobalBounds().height << "    ========    tiles ---> " << tile_sprite->getPosition().x << std::endl;
	//std::cout << level_size.x << std::endl;
	//player_sprite = player;
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
		player_sprite->getPosition().x + border < tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width && tiles_type != 111 || ledder_gravity_botton_bool == true)
	{
		player_sprite->setPosition(player_sprite->getPosition().x, tile_sprite->getPosition().y - player_sprite->getGlobalBounds().height - gravityY);
		//std::cout << "PLAYER ---> " << player_sprite->getPosition().x / 100 + player_sprite->getGlobalBounds().height << "    ========    tiles ---> " << tile_sprite->getPosition().x / 100 << std::endl;
		//std::cout << "1" << std::endl;
		this->ground_yes_no = true;
		
	}
	else if (player_sprite->getPosition().y + border <= tile_sprite->getPosition().y + tile_sprite->getGlobalBounds().height &&
		player_sprite->getPosition().y >= tile_sprite->getPosition().y + tile_sprite->getGlobalBounds().height - tile_sprite->getGlobalBounds().height / 3 * 2&&
		player_sprite->getPosition().x + player_sprite->getGlobalBounds().width - border > tile_sprite->getPosition().x &&
		player_sprite->getPosition().x + border < tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width && tiles_type != 111)
	{
		player_sprite->setPosition(player_sprite->getPosition().x, tile_sprite->getPosition().y + tile_sprite->getGlobalBounds().height - border);
		//std::cout << "2" << std::endl;
	}
	if (player_sprite->getPosition().y + player_sprite->getGlobalBounds().height == tile_sprite->getPosition().y + tile_sprite->getGlobalBounds().height &&
		player_sprite->getPosition().y + player_sprite->getGlobalBounds().height >= tile_sprite->getPosition().y &&
		player_sprite->getPosition().x + player_sprite->getGlobalBounds().width - border >= tile_sprite->getPosition().x &&
		player_sprite->getPosition().x + player_sprite->getGlobalBounds().width - border <= tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width / 3 && tiles_type != 111)
	{
		player_sprite->setPosition(tile_sprite->getPosition().x - player_sprite->getGlobalBounds().width + border, player_sprite->getPosition().y);
		//std::cout << "3" << std::endl;
	}
	else if (player_sprite->getPosition().y + player_sprite->getGlobalBounds().height == tile_sprite->getPosition().y + tile_sprite->getGlobalBounds().height &&
		player_sprite->getPosition().y + player_sprite->getGlobalBounds().height >= tile_sprite->getPosition().y + 10 && 
		player_sprite->getPosition().x + border <= tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width &&
		player_sprite->getPosition().x + border >= tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width / 3 * 2 && tiles_type != 111)
	{
		player_sprite->setPosition(tile_sprite->getPosition().x + tile_sprite->getGlobalBounds().width - border, player_sprite->getPosition().y);
		//std::cout << "4" << std::endl;
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
	//std::cout << "PLAYER ---> " << player_sprite->getPosition().x << "    ========    BONUS ---> " << bonus_sprite.getPosition().x <<std::endl;
	if (player_sprite->getPosition().x + player_sprite->getGlobalBounds().width > bonus_sprite.getPosition().x &&
		player_sprite->getPosition().x < bonus_sprite.getPosition().x + bonus_sprite.getGlobalBounds().width &&
		player_sprite->getPosition().y + player_sprite->getGlobalBounds().height > bonus_sprite.getPosition().y &&
		player_sprite->getPosition().y < bonus_sprite.getPosition().y + bonus_sprite.getGlobalBounds().height)
	{
		//std::cout << catch_bonus_true << std::endl;
		//std::cout << bonus_sprite.getPosition().x << " ------- POSITION X "<< std::endl;
		this->catch_bonus_true = true;

	}
	else
	{
		this->catch_bonus_true = false;
		//this->catch_bonus_one_time_true = true;
		//std::cout << "__________________________________________________________________________" << std::endl;
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

bool Colisions::catch_bonus_one_time()
{
	return catch_bonus_one_time_true;
}

void Colisions::catch_bonus_one_time_in(bool index)
{
	this->catch_bonus_one_time_true = index;
}

//void Colisions::catch_change_to_false()
//{
//	this->catch_bonus_true = false;
//}

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

#include "Colisions.hpp"

Colisions::Colisions()
{
	this->gravityY = 10;
	this->border = 20;
	this->level_size = sf::Vector2i(10000, 0);// uwazac bo z ta wartoscia bedzie zaczynal player
	this->ground_yes_no = false;
	this->catch_bonus_true = false;
	this->bonus_quantity = 0;
	this->bonus_number = 0;
	//this->player_sprite = nullptr;
}

void Colisions::gravity(sf::RenderWindow& window, sf::Sprite* player)
{
	player->move(0, gravityY);

}

void Colisions::colision(sf::RenderWindow& window, sf::Sprite* player, sf::Sprite* tiles)
{
	//std::cout << " ---- Bonus iloœæ = " << bonus_quantity;
	//std::cout << " ---- Bonus ktory = " << bonus_quantity - 1;
	//std::cout << " ---- POS_X = " << bonus_sprite.getPosition().x << std::endl;

	//std::cout << ground_yes_no << std::endl;
	if (player->getPosition().x <= 0)
	{
		player->setPosition(0, player->getPosition().y);
	}
	if (player->getPosition().x + player->getGlobalBounds().width >= level_size.x)
	{
		//std::cout << level_size.x << std::endl;
		player->setPosition(level_size.x - player->getGlobalBounds().width, player->getPosition().y);
	}
	if (player->getPosition().y + player->getGlobalBounds().height >= tiles->getPosition().y &&
		player->getPosition().y + player->getGlobalBounds().height < tiles->getPosition().y + tiles->getGlobalBounds().height  &&
		player->getPosition().x + player->getGlobalBounds().width - border > tiles->getPosition().x &&
		player->getPosition().x + border < tiles->getPosition().x + tiles->getGlobalBounds().width)
	{
		player->setPosition(player->getPosition().x, tiles->getPosition().y - player->getGlobalBounds().height - gravityY);
		this->ground_yes_no = true;
		
	}
	else if (player->getPosition().y + border <= tiles->getPosition().y + tiles->getGlobalBounds().height &&
		player->getPosition().y >= tiles->getPosition().y + tiles->getGlobalBounds().height - tiles->getGlobalBounds().height / 3 * 2&&
		player->getPosition().x + player->getGlobalBounds().width - border > tiles->getPosition().x &&
		player->getPosition().x + border < tiles->getPosition().x + tiles->getGlobalBounds().width)
	{
		player->setPosition(player->getPosition().x, tiles->getPosition().y + tiles->getGlobalBounds().height - border);
	}
	if (player->getPosition().y + player->getGlobalBounds().height == tiles->getPosition().y + tiles->getGlobalBounds().height &&
		player->getPosition().y + player->getGlobalBounds().height >= tiles->getPosition().y &&
		player->getPosition().x + player->getGlobalBounds().width - border >= tiles->getPosition().x &&
		player->getPosition().x + player->getGlobalBounds().width - border <= tiles->getPosition().x + tiles->getGlobalBounds().width / 3)
	{
		player->setPosition(tiles->getPosition().x - player->getGlobalBounds().width + border, player->getPosition().y);
	}
	else if (player->getPosition().y + player->getGlobalBounds().height == tiles->getPosition().y + tiles->getGlobalBounds().height &&
		player->getPosition().y + player->getGlobalBounds().height >= tiles->getPosition().y + 10 && 
		player->getPosition().x + border <= tiles->getPosition().x + tiles->getGlobalBounds().width &&
		player->getPosition().x + border >= tiles->getPosition().x + tiles->getGlobalBounds().width / 3 * 2)
	{
		player->setPosition(tiles->getPosition().x + tiles->getGlobalBounds().width - border, player->getPosition().y);
	}
	else
	{
		//this->ground_yes_no = false;
	}
	this->catch_bonus_true = false;

	//std::cout << player->getPosition().x << std::endl;
	//std::cout << bonus_sprite.getPosition().x << std::endl;

	//std::cout << catch_bonus_true << std::endl;
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
		//std::cout << catch_bonus_truex << std::endl;
		//std::cout << "TAK" << std::endl;
		this->catch_bonus_true = true;

	}
	else
	{
		//std::cout << "NIE" << std::endl;
	}
}

//uint16_t Colisions::bonus_no_initialize()
//{
//	//std::cout << bonus_number << std::endl;
//	return this->bonus_number;
//}
//
//void Colisions::bonus_index_incresed()
//{
//	this->bonus_number++;
//}

bool Colisions::catch_bonus()
{
	return catch_bonus_true;
}

void Colisions::player_sprite_in(sf::Sprite* player)
{
	player_sprite = player;
}

int8_t Colisions::gravityY_out()
{
	return gravityY;
}

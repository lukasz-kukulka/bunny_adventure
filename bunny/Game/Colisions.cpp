#include "Colisions.hpp"

Colisions::Colisions()
{
	this->gravityY = 5;
	this->jump_available = false;
}

void Colisions::gravity(sf::RenderWindow& window, sf::Sprite* player)
{
	player->move(0, gravityY);
}

void Colisions::colision(sf::RenderWindow& window, sf::Sprite* player, sf::Sprite* tiles)
{
	if (player->getPosition().y + player->getGlobalBounds().height >= tiles->getPosition().y &&
		player->getPosition().y + player->getGlobalBounds().height < tiles->getPosition().y + tiles->getGlobalBounds().height / 2  &&
		player->getPosition().x + player->getGlobalBounds().width > tiles->getPosition().x &&
		player->getPosition().x < tiles->getPosition().x + tiles->getGlobalBounds().width)
	{
		std::cout << " test 1  " << std::endl;
		player->setPosition(player->getPosition().x, tiles->getPosition().y - player->getGlobalBounds().height - gravityY);
		this->jump_available = true;
	}
}

bool Colisions::jump_player_available()
{
	return jump_available;
}

void Colisions::jump_player_space_press(bool reset)
{
	this->jump_available = reset;
}

int8_t Colisions::gravityY_out()
{
	return gravityY;
}

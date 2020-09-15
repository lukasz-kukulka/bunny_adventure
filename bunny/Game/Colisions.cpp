#include "Colisions.hpp"

Colisions::Colisions()
{
	this->gravityY = 10;
	this->border = 20;
}

void Colisions::gravity(sf::RenderWindow& window, sf::Sprite* player)
{
	player->move(0, gravityY);

}

void Colisions::colision(sf::RenderWindow& window, sf::Sprite* player, sf::Sprite* tiles)
{
	if (player->getPosition().x <= 0)
	{
		player->setPosition(0, player->getPosition().y);
	}

	if (player->getPosition().y + player->getGlobalBounds().height >= tiles->getPosition().y &&
		player->getPosition().y + player->getGlobalBounds().height < tiles->getPosition().y + tiles->getGlobalBounds().height  &&
		player->getPosition().x + player->getGlobalBounds().width - border > tiles->getPosition().x &&
		player->getPosition().x + border < tiles->getPosition().x + tiles->getGlobalBounds().width)
	{
		player->setPosition(player->getPosition().x, tiles->getPosition().y - player->getGlobalBounds().height - gravityY);
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
}

int8_t Colisions::gravityY_out()
{
	return gravityY;
}

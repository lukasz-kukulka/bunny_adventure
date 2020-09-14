#include "Colisions.hpp"

Colisions::Colisions()
{
	this->gravityY = 10;
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
		player->getPosition().x + player->getGlobalBounds().width > tiles->getPosition().x &&
		player->getPosition().x < tiles->getPosition().x + tiles->getGlobalBounds().width)
	{
		player->setPosition(player->getPosition().x, tiles->getPosition().y - player->getGlobalBounds().height - gravityY);
		//std::cout << "gravitacja\n";
	}
	else if (player->getPosition().y <= tiles->getPosition().y + tiles->getGlobalBounds().height &&
		player->getPosition().y >= tiles->getPosition().y + tiles->getGlobalBounds().height - tiles->getGlobalBounds().height / 3 * 2&&
		player->getPosition().x + player->getGlobalBounds().width > tiles->getPosition().x &&
		player->getPosition().x < tiles->getPosition().x + tiles->getGlobalBounds().width)
	{
		player->setPosition(player->getPosition().x, tiles->getPosition().y + tiles->getGlobalBounds().height);
		std::cout << "top\n";
	}
	if (player->getPosition().y + player->getGlobalBounds().height == tiles->getPosition().y + tiles->getGlobalBounds().height &&
		player->getPosition().y + player->getGlobalBounds().height >= tiles->getPosition().y &&
		player->getPosition().x + player->getGlobalBounds().width >= tiles->getPosition().x &&
		player->getPosition().x + player->getGlobalBounds().width <= tiles->getPosition().x + tiles->getGlobalBounds().width / 3)
	{
		player->setPosition(tiles->getPosition().x - player->getGlobalBounds().width, player->getPosition().y);
		std::cout << "colision right\n";
	}
	else if (player->getPosition().y + player->getGlobalBounds().height == tiles->getPosition().y + tiles->getGlobalBounds().height &&
		player->getPosition().y + player->getGlobalBounds().height >= tiles->getPosition().y + 10 && 
		player->getPosition().x <= tiles->getPosition().x + tiles->getGlobalBounds().width &&
		player->getPosition().x >= tiles->getPosition().x + tiles->getGlobalBounds().width / 3 * 2)
	{
		player->setPosition(tiles->getPosition().x + tiles->getGlobalBounds().width, player->getPosition().y);
		std::cout << "colision left\n";
	}
}

int8_t Colisions::gravityY_out()
{
	return gravityY;
}

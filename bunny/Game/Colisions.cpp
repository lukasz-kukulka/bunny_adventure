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
	if (player->getPosition().y + player->getGlobalBounds().height >= tiles->getPosition().y &&
		player->getPosition().y + player->getGlobalBounds().height < tiles->getPosition().y + tiles->getGlobalBounds().height / 2  &&
		player->getPosition().x + player->getGlobalBounds().width > tiles->getPosition().x &&
		player->getPosition().x < tiles->getPosition().x + tiles->getGlobalBounds().width)
	{
		//std::cout << " test 1  " << std::endl;
		player->setPosition(player->getPosition().x, tiles->getPosition().y - player->getGlobalBounds().height - gravityY);
	}


}

int8_t Colisions::gravityY_out()
{
	return gravityY;
}

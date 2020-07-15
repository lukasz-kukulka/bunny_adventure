#include "Colisions.hpp"

Colisions::Colisions()
{

}

void Colisions::gravity(sf::RenderWindow& window, sf::Sprite* player)
{
	player->move(0, 10);
}

void Colisions::colision(sf::RenderWindow& window, sf::Sprite* player, sf::Sprite* tiles)
{
	if (player->getPosition().y + player->getGlobalBounds().height >= tiles->getPosition().y &&
		player->getPosition().y <= tiles->getPosition().y + tiles->getGlobalBounds().height &&
		player->getPosition().x + player->getGlobalBounds().width >= tiles->getPosition().x &&
		player->getPosition().x <= tiles->getPosition().x + tiles->getGlobalBounds().width)
	{
		player->setPosition(player->getPosition().x, tiles->getPosition().y - player->getGlobalBounds().height - 5);
	}
}

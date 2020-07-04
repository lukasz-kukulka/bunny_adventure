#include "Background.hpp"

Background::Background(sf::RenderWindow& window, sf::Texture* background_sky, uint8_t index)
{
	this->index = index;
	this->sky_sprite.setTexture(*background_sky);
	this->sky_sprite.setScale(window.getSize().x / sky_sprite.getGlobalBounds().width, window.getSize().x / sky_sprite.getGlobalBounds().width);
	this->sky_sprite.setPosition(index * sky_sprite.getGlobalBounds().width, 0);
}

uint8_t Background::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		move_background(-10, window);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		move_background(10, window);
	}

	return 0;
}

void Background::move_background(int8_t speed, sf::RenderWindow& window)
{
	
	if (sky_sprite.getPosition().x + sky_sprite.getGlobalBounds().width <= 0)
	{
		sky_sprite.setPosition(sky_sprite.getGlobalBounds().width, 0);
	}
	else if (sky_sprite.getPosition().x >= window.getSize().x)
	{
		sky_sprite.setPosition(0 - sky_sprite.getGlobalBounds().width, 0);
	}
	sky_sprite.move(speed, 0);
}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(sky_sprite);
}

#include "Background.hpp"

Background::Background(sf::RenderWindow& window, sf::Texture* back_tex, uint8_t type_sprite, uint8_t index, uint8_t speed)
{
	this->index = index;
	this->speed_f = 1.0 * window.getSize().x / (window.getSize().x / speed);
	this->movment_pooint_x = 0;
	this->type_sprite = type_sprite;
	this->back_sprite.setTexture(*back_tex);
	this->back_sprite.setScale( window.getSize().x / back_sprite.getGlobalBounds().width, window.getSize().x / back_sprite.getGlobalBounds().width);
	if (type_sprite == 0)
	{
		this->back_sprite.setPosition(index * back_sprite.getGlobalBounds().width, 0);
	}
	else if (type_sprite == 1)
	{
		this->back_sprite.setPosition(index * back_sprite.getGlobalBounds().width, window.getSize().y - back_sprite.getGlobalBounds().height);
	}
	
}

uint8_t Background::system(sf::RenderWindow& window, sf::Vector2i mouse)
{


	return 0;
}

void Background::move_background(sf::RenderWindow& window, int8_t direct_x)
{
	if (movment_pooint_x <= 0 && direct_x == (-1))
	{
		movment_pooint_x = window.getSize().x;
	}
	else if (movment_pooint_x >= window.getSize().x && direct_x == 1)
	{
		movment_pooint_x = 0;
	}
	this->movment_pooint_x = movment_pooint_x + direct_x * speed_f;
	if (index == 0)
	{
		this->back_sprite.setPosition(movment_pooint_x, back_sprite.getPosition().y);
	}
	else if (index == 1)
	{
		this->back_sprite.setPosition(movment_pooint_x - back_sprite.getGlobalBounds().width, back_sprite.getPosition().y);
	}
}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(back_sprite);
	
}

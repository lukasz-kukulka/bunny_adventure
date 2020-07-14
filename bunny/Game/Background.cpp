#include "Background.hpp"

Background::Background(sf::RenderWindow& window, sf::Texture* back_tex, uint8_t type_sprite, uint8_t index, float speed, sf::View& view_window)
{
	this->index = index;
	this->speed_f = 1.0 * window.getSize().x / (window.getSize().x / speed);
	this->movment_pooint_x = view_window.getCenter().x;
	this->type_sprite = type_sprite;
	this->back_sprite.setTexture(*back_tex);
	this->back_sprite.setScale( window.getSize().x / back_sprite.getGlobalBounds().width, window.getSize().x / back_sprite.getGlobalBounds().width);
	if (type_sprite == 0)
	{
		this->back_sprite.setPosition(movment_pooint_x - index * back_sprite.getGlobalBounds().width, 0);
	}
	else if (type_sprite == 1)
	{
		this->back_sprite.setPosition(movment_pooint_x - index * back_sprite.getGlobalBounds().width, window.getSize().y - back_sprite.getGlobalBounds().height);
	}
}

uint8_t Background::system(sf::RenderWindow& window)
{
	return 0;
}

void Background::move_background_view(int8_t direct_x, sf::View& view)
{
	if (movment_pooint_x <= view.getCenter().x - view.getSize().x / 2 && direct_x == (-1))
	{
		movment_pooint_x = view.getCenter().x + view.getSize().x / 2 ;
	}
	if (movment_pooint_x >= view.getCenter().x + view.getSize().x / 2 && direct_x == 1)
	{
		movment_pooint_x = view.getCenter().x - view.getSize().x / 2;
	}

	this->movment_pooint_x = movment_pooint_x + direct_x * speed_f / 10.0;
	if (index == 0)
	{
		this->back_sprite.setPosition(movment_pooint_x, back_sprite.getPosition().y);
	}
	else if (index == 1)
	{
		this->back_sprite.setPosition(movment_pooint_x - back_sprite.getGlobalBounds().width, back_sprite.getPosition().y);
	}
}

void Background::level_size(sf::Vector2i lvl_size)
{
	this->lvl_size = lvl_size;
}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(back_sprite);
	
}

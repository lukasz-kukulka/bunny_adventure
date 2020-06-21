#include "Slider_score.hpp"

Slider_score::Slider_score(sf::RenderWindow& window, sf::RectangleShape& base, sf::Texture* up, sf::Texture* mid, sf::Texture* down)
{
	this->rec_base = base;
	this->up_tex = up; 
	this->mid_tex = mid; 
	this->down_tex = down;

	this->objects_ini(window);
}

int Slider_score::system(sf::RenderWindow& window, sf::Vector2i mouse)
{

	return 0;
}

void Slider_score::objects_ini(sf::RenderWindow& window)
{
	this->slider_shape.setSize(sf::Vector2f(52, rec_base.getSize().y));
	this->slider_shape.setPosition(rec_base.getPosition().x + rec_base.getGlobalBounds().width, rec_base.getPosition().y);
	this->slider_shape.setFillColor(sf::Color(255, 255, 255, 88));
	this->slider_shape.setOutlineThickness(1);
	this->slider_shape.setOutlineColor(sf::Color(0, 0, 0, 111));

	this->slider_up.setTexture(*up_tex);
	this->slider_up.setPosition(slider_shape.getPosition().x, slider_shape.getPosition().y);

	this->slider_mid.setTexture(*mid_tex);
	this->slider_mid.setPosition(slider_up.getPosition().x, slider_shape.getPosition().y + slider_up.getGlobalBounds().height);

	this->slider_down.setTexture(*down_tex);
	this->slider_down.setPosition(slider_shape.getPosition().x, slider_shape.getPosition().y + slider_shape.getGlobalBounds().height - slider_down.getGlobalBounds().height);
}

void Slider_score::draw(sf::RenderWindow& window)
{
	window.draw(slider_shape);
	window.draw(slider_down);
	window.draw(slider_mid);
	window.draw(slider_up);
	window.draw(rec_base);
	
}

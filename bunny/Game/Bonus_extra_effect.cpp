#include "Bonus_extra_effect.hpp"

Bonus_extra_effect::Bonus_extra_effect(sf::RenderWindow& window, sf::Font* font, std::string text, uint8_t type)
{
	this->bonus_text.setString(text);
	this->bonus_text.setCharacterSize(window.getSize().x / 50);;
	this->bonus_text.setFont(*font);
	this->bonus_text.setStyle(sf::Text::Bold);

	if (type == 1)
		this->bonus_text.setFillColor(sf::Color(155, 155, 155));
	if (type == 2)
		this->bonus_text.setFillColor(sf::Color(155, 0, 0));
	if (type == 3)
		this->bonus_text.setFillColor(sf::Color(0, 155, 0));
	if (type == 4)
		this->bonus_text.setFillColor(sf::Color(200, 100, 0));
	if (type == 5)
		this->bonus_text.setFillColor(sf::Color(100, 50, 0));
	if (type == 6)
		this->bonus_text.setFillColor(sf::Color(50, 255, 255));
	if (type == 7)
		this->bonus_text.setFillColor(sf::Color(255, 100, 255));
	if (type == 8)
		this->bonus_text.setFillColor(sf::Color(50, 50, 255));
	if (type == 9)
		this->bonus_text.setFillColor(sf::Color(255, 255, 50));
	if (type == 10)
		this->bonus_text.setFillColor(sf::Color(200, 0, 110));
	if (type == 11)
		this->bonus_text.setFillColor(sf::Color(255, 255, 255));
	if (type == 12)
		this->bonus_text.setFillColor(sf::Color(0, 100, 0));

	this->bonus_text.setOutlineThickness(0);
	this->bonus_text.setOutlineColor(sf::Color::Black);
	this->bonus_text.setScale(0, 0);
	
}

uint8_t Bonus_extra_effect::system(sf::View window)
{
	if (bonus_text.getScale().x == 0 && can_delete == false)
		this->bonus_text.setPosition(window.getCenter().x - bonus_text.getGlobalBounds().width / 2, window.getCenter().y);
	if (bonus_text.getScale().x < 1 && can_delete == true)
	{
		this->bonus_text.setScale(bonus_text.getScale().x + 0.005, bonus_text.getScale().x + 0.005);
		this->bonus_text.setPosition(window.getCenter().x - bonus_text.getGlobalBounds().width / 2, bonus_text.getPosition().y - 1);
		this->bonus_text.setOutlineThickness(2);
		if (bonus_text.getScale().x >= 0.99)
			return 1;
	}
	return 0;
}

void Bonus_extra_effect::can_delete_change(bool index)
{
	this->can_delete = index;
}



bool Bonus_extra_effect::can_delete_out()
{
	return can_delete;
}

void Bonus_extra_effect::draw(sf::RenderWindow& window)
{
	window.draw(bonus_text);
}

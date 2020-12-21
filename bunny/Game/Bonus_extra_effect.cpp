#include "Bonus_extra_effect.hpp"

Bonus_extra_effect::Bonus_extra_effect(sf::RenderWindow& window, sf::Font* font, sf::Vector2f position, uint8_t type_of_bonus)
{
	this->bonus_text.setString("test_test adasdsadsadas   dsadasdasdasd");
	this->bonus_text.setCharacterSize(window.getSize().x / 50);
	//this->bonus_text.setPosition(position.x - bonus_text.getGlobalBounds().width / 2, position.y);
	this->bonus_text.setFont(*font);
	
	this->bonus_text.setStyle(sf::Text::Bold);
	this->bonus_text.setFillColor(sf::Color::Red);
	this->bonus_text.setOutlineThickness(0);
	this->bonus_text.setOutlineColor(sf::Color::Black);
	this->bonus_text.setScale(0, 0);
	
}

uint8_t Bonus_extra_effect::system(sf::View window)
{
	
	if (bonus_text.getScale().x < 1 && can_delete == true)
	{
		std::cout << "STEP 1" << std::endl;
		//this->bonus_text.setCharacterSize(window.getSize().x / 50);
		this->bonus_text.setScale(bonus_text.getScale().x + 0.03, bonus_text.getScale().x + 0.03);
		this->bonus_text.setPosition(window.getCenter().x - bonus_text.getGlobalBounds().width / 2, window.getCenter().y);
		this->bonus_text.setOutlineThickness(2);
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

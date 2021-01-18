#include "Singe_option_esc_menu.hpp"

Singe_option_esc_menu::Singe_option_esc_menu(sf::Font* font_text, sf::Vector2f pos, sf::Vector2f size, std::string name)
{
	this->esc_option.setSize(sf::Vector2f(size.x, size.y));
	this->esc_option.setPosition(pos.x, pos.y);
	this->esc_option.setFillColor(sf::Color(0, 255, 0, 111));
	this->mark_option.setSize(sf::Vector2f(size.x, size.y));
	this->mark_option.setPosition(pos.x, pos.y);
	this->mark_option.setFillColor(sf::Color(0, 0, 0, 111));
	this->mark_option.setScale(sf::Vector2f(0, 0));

	this->text_menu.setString(name);
	this->text_menu.setFont(*font_text);
	this->text_menu.setCharacterSize(size.y);
	this->text_menu.setFillColor(sf::Color(111, 222, 55, 255));

	this->text_menu.setPosition(esc_option.getPosition().x + esc_option.getGlobalBounds().width / 2 - text_menu.getGlobalBounds().width / 2,
		esc_option.getPosition().y + esc_option.getGlobalBounds().height / 2 - text_menu.getGlobalBounds().height / 2);

}

uint8_t Singe_option_esc_menu::system(sf::View& window, bool mark_on)
{
	this->mark_visible = mark_on;
	if (mark_visible == true)
	{
		this->mark_option.setScale(sf::Vector2f(1.0, 1.0));
	}
	else
	{
		this->mark_option.setScale(sf::Vector2f(0, 0));
	}

	return 0;
}

void Singe_option_esc_menu::draw(sf::RenderWindow& window)
{
	window.draw(esc_option);
	window.draw(mark_option);
	window.draw(text_menu);
}

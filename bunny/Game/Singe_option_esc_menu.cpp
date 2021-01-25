#include "Singe_option_esc_menu.hpp"

Singe_option_esc_menu::Singe_option_esc_menu(sf::Font* font_text, sf::Vector2f pos, sf::Vector2f size, std::string name, uint8_t index, bool mark)
{
	this->mark_visible = mark;
	this->esc_option.setSize(sf::Vector2f(size.x, size.y));
	this->esc_option.setPosition(pos.x, pos.y + size.y * index);
	this->esc_option.setFillColor(sf::Color(255, 0, 0, 111));
	this->esc_option.setOutlineThickness(2);
	this->esc_option.setOutlineColor(sf::Color(255, 255, 255, 255));

	this->mark_option.setSize(sf::Vector2f(size.x, size.y));
	this->mark_option.setPosition(pos.x, pos.y);
	this->mark_option.setFillColor(sf::Color(0, 0, 0, 199));
	if (mark_visible == true)
		this->mark_option.setScale(sf::Vector2f(1, 1));
	else
		this->mark_option.setScale(sf::Vector2f(0, 0));

	this->text_menu.setString(name);
	this->text_menu.setFont(*font_text);
	this->text_menu.setCharacterSize(size.y / 3);
	this->text_menu.setFillColor(sf::Color(255, 255, 255, 255));
	this->text_menu.setOutlineThickness(2);
	this->text_menu.setOutlineColor(sf::Color(0, 0, 0, 255));

	this->text_menu.setPosition(esc_option.getPosition().x + esc_option.getGlobalBounds().width / 2 - text_menu.getGlobalBounds().width / 2,
		esc_option.getPosition().y + esc_option.getGlobalBounds().height / 3 - text_menu.getGlobalBounds().height / 2);

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
	//text_menu.getFont();
	window.draw(text_menu);
}

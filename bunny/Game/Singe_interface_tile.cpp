#include "Singe_interface_tile.hpp"

Singe_interface_tile::Singe_interface_tile(sf::RenderWindow& window, sf::Vector2f pos, std::string name_a, std::string name_b, sf::Vector2f size_tile, sf::Font* font)
{
	this->text_frame.setSize(sf::Vector2f(size_tile.x, size_tile.y));
	this->text_frame.setPosition(pos.x, pos.y);
	this->text_frame.setFillColor(sf::Color(0, 0, 0, 0));

	this->text.setString(name_a + " " + name_b);
	this->text.setPosition(text_frame.getPosition().x + text_frame.getGlobalBounds().width / 2 - text.getGlobalBounds().width / 2, 
		text_frame.getPosition().y + text_frame.getGlobalBounds().height / 2 - text.getGlobalBounds().height / 2);
	this->text.setFont(*font);
	this->text.setCharacterSize(window.getSize().x / 35);
	this->text.setStyle(sf::Text::Bold);
	this->text.setFillColor(sf::Color::Blue);
}

void Singe_interface_tile::system(sf::View& window, sf::Vector2f pos, std::string name_a, std::string name_b)
{
	this->text_frame.setPosition(pos.x, pos.y);

	this->text.setString(name_a + " " + name_b);
	this->text.setPosition(text_frame.getPosition().x + text_frame.getGlobalBounds().width / 2 - text.getGlobalBounds().width / 2,
		text_frame.getPosition().y + text_frame.getGlobalBounds().height / 2 - text.getGlobalBounds().height / 2);
}

void Singe_interface_tile::draw(sf::RenderWindow& window)
{
	window.draw(text_frame);
	window.draw(text);
}

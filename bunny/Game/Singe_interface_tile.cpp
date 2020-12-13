#include "Singe_interface_tile.hpp"

Singe_interface_tile::Singe_interface_tile(sf::Vector2f pos, std::string name_a, std::string name_b, sf::Vector2f size_tile, sf::Font* font)
{
	this->text_frame.setSize(sf::Vector2f(size_tile.x, size_tile.y));
	this->text_frame.setPosition(pos.x, pos.y);
	this->text_frame.setFillColor(sf::Color(255, 0, 0, 111));

	this->text.setString(name_a + " " + name_b);
	this->text.setPosition(pos.x, pos.y);
	this->text.setFont(*font);
	this->text.setCharacterSize(30);
	this->text.setStyle(sf::Text::Bold);
	this->text.setFillColor(sf::Color::Blue);
}

void Singe_interface_tile::draw(sf::RenderWindow& window)
{
	window.draw(text_frame);
	window.draw(text);
}

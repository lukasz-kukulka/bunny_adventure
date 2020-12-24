#include "Level_end.hpp"

Level_end::Level_end(sf::View window, sf::Font* font)
{
	this->info_text.setString("END LVL TEST");
	this->info_text.setCharacterSize(window.getSize().x / 25);
	this->info_text.setPosition(window.getCenter().x - info_text.getGlobalBounds().width / 2, window.getCenter().y - info_text.getGlobalBounds().height / 2);
	this->info_text.setFont(*font);

	this->info_text.setStyle(sf::Text::Bold);
	this->info_text.setFillColor(sf::Color::Yellow);
	this->info_text.setOutlineThickness(0);
	this->info_text.setOutlineColor(sf::Color::Black);
	this->info_text.setScale(0, 0);
}

uint8_t Level_end::system(sf::RenderWindow& window)
{
	return 0;
}

uint8_t Level_end::animation(sf::RenderWindow& window)
{
	return 0;
}

void Level_end::draw(sf::RenderWindow& window)
{
	window.draw(info_text);
}

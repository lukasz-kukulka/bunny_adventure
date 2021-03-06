#include "Level_end.hpp"

Level_end::Level_end(sf::View window, sf::Font* font, uint8_t level)
{
	this->rectangle.setSize(sf::Vector2f(window.getSize().x - 200, window.getSize().y - 200));
	this->rectangle.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->rectangle.setFillColor(sf::Color(0, 0, 0, 155));
	this->rectangle.setPosition(window.getCenter().x - rectangle.getGlobalBounds().width / 2, window.getCenter().y - rectangle.getGlobalBounds().height / 2);

	this->info_text.setString("  END LVL " + std::to_string(level) + "\n PRESS SPACE TO CONTINUE");
	this->info_text.setFont(*font);
	this->info_text.setCharacterSize(window.getSize().x / 25);
	this->info_text.setPosition(window.getCenter().x - info_text.getGlobalBounds().width / 2, window.getCenter().y - info_text.getGlobalBounds().height / 2);
	
	this->info_text.setStyle(sf::Text::Bold);
	this->info_text.setFillColor(sf::Color::Yellow);
	this->info_text.setOutlineThickness(3);
	this->info_text.setOutlineColor(sf::Color::Red);
	this->info_text.setScale(1, 1);
}

uint8_t Level_end::system(sf::View& window)
{
	this->info_text.setPosition(window.getCenter().x - info_text.getGlobalBounds().width / 2, window.getCenter().y - info_text.getGlobalBounds().height / 2);
	this->rectangle.setPosition(window.getCenter().x - rectangle.getGlobalBounds().width / 2, window.getCenter().y - rectangle.getGlobalBounds().height / 2);
	return 0;
}

uint8_t Level_end::animation(sf::RenderWindow& window)
{
	return 0;
}

void Level_end::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
	window.draw(info_text);
}

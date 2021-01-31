#include "Game_over.hpp"

Game_over::Game_over(sf::View window, sf::Font* font, uint32_t points)
{
	this->rectangle.setSize(sf::Vector2f(window.getSize().x - 200, window.getSize().y - 200));
	this->rectangle.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->rectangle.setFillColor(sf::Color(0, 0, 0, 155));
	this->rectangle.setPosition(window.getCenter().x - rectangle.getGlobalBounds().width / 2, window.getCenter().y - rectangle.getGlobalBounds().height / 2);

	this->info_text.setString("Game over \n You get\n" + std::to_string(points) + " points\n press SPACE to continue");
	this->info_text.setFont(*font);
	this->info_text.setCharacterSize(window.getSize().x / 25);
	this->info_text.setPosition(window.getCenter().x - info_text.getGlobalBounds().width / 2, window.getCenter().y - info_text.getGlobalBounds().height / 2);

	this->info_text.setStyle(sf::Text::Bold);
	this->info_text.setFillColor(sf::Color::Yellow);
	this->info_text.setOutlineThickness(3);
	this->info_text.setOutlineColor(sf::Color::Red);
	this->info_text.setScale(1, 1);
}

uint8_t Game_over::system()
{
	//std::cout << "---> " << system_clock << std::endl;
	this->system_clock++;
	if (system_clock >= 30)
	{
		system_clock = 31;
		return 1;
	}
	else
	{
		return 0;
	}
	
}

void Game_over::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
	window.draw(info_text);
}

#include "Interface_text.hpp"

Interface_text::Interface_text(sf::RenderWindow& window)
{
	this->font_points.loadFromFile("Game/Fonts/beachday.ttf");
	this->rectangle_panel_top.setSize(sf::Vector2f(window.getSize().x - 100, window.getSize().y / 10));
	this->rectangle_panel_top.setPosition((window.getSize().x - rectangle_panel_top.getGlobalBounds().width) / 2, window.getSize().y / 20);
	this->rectangle_panel_top.setFillColor(sf::Color(0, 0, 0, 111));
}

void Interface_text::system(sf::View& window)
{
	this->rectangle_panel_top.setPosition(window.getCenter().x - rectangle_panel_top.getGlobalBounds().width / 2, window.getCenter().y / 10);
}

void Interface_text::initialization_tiles_text()
{

}

void Interface_text::draw(sf::RenderWindow& window)
{
	window.draw(rectangle_panel_top);
}

#include "Interface_text.hpp"

Interface_text::Interface_text(sf::RenderWindow& window)
{
	this->font_points.loadFromFile("Game/Fonts/beachday.ttf");
	this->rectangle_panel_top.setSize(sf::Vector2f(window.getSize().x - 100, window.getSize().y / 10));
	this->rectangle_panel_top.setPosition((window.getSize().x - rectangle_panel_top.getGlobalBounds().width) / 2, window.getSize().y / 20);
	this->rectangle_panel_top.setFillColor(sf::Color(0, 0, 0, 0));
	initialization_tiles_text(window);
}

void Interface_text::system(sf::View& window)
{
	this->rectangle_panel_top.setPosition(window.getCenter().x - rectangle_panel_top.getGlobalBounds().width / 2, 0);
	for (int i = 0; i < text_tile.size(); i++)
	{
		text_tile[i].system(window, sf::Vector2f(rectangle_panel_top.getPosition().x + rectangle_panel_top.getGlobalBounds().width * i, rectangle_panel_top.getPosition().y), "Score: ", score_points);
	}
}

void Interface_text::initialization_tiles_text(sf::RenderWindow& window)
{
	text_tile.push_back(Singe_interface_tile(window, sf::Vector2f(rectangle_panel_top.getPosition().x, rectangle_panel_top.getPosition().y), "Score", "00000000",
		sf::Vector2f(rectangle_panel_top.getGlobalBounds().width / 3, rectangle_panel_top.getGlobalBounds().height), &font_points));
}

void Interface_text::score_points_in(int points)
{
	this->score_points = std::to_string(points);

	for(int i = score_points.size(); i < 8; i++)
	{
		//std::cout << score_points.size() <<    "   -----------------------------------------  " << score_points << std::endl;
		this->score_points = "0" + score_points;
	}
}

void Interface_text::life_player_in(uint8_t points)
{

}

void Interface_text::draw(sf::RenderWindow& window)
{
	window.draw(rectangle_panel_top);
	for (auto i : text_tile)
		i.draw(window);
}

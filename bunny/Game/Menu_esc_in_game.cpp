#include "Menu_esc_in_game.hpp"

Menu_esc_in_game::Menu_esc_in_game(sf::View& window, uint8_t type_menu)
{
	this->font_menu.loadFromFile("Game/Fonts/butler.ttf");
	this->all_panel_top.setSize(sf::Vector2f(window.getSize().x / 3, window.getSize().y / 3));
	this->all_panel_top.setPosition(window.getCenter().x - all_panel_top.getGlobalBounds().width / 2, window.getCenter().y - all_panel_top.getGlobalBounds().height / 2);
	this->all_panel_top.setFillColor(sf::Color(255, 0, 0, 111));
	this->objects_ini(window);
}

uint8_t Menu_esc_in_game::system(sf::View& window)
{
	if (menu_visible == false)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}

void Menu_esc_in_game::objects_ini(sf::View& window)
{
	single_option.push_back(Singe_option_esc_menu(&font_menu, sf::Vector2f(all_panel_top.getPosition().x, all_panel_top.getPosition().y),
		sf::Vector2f(all_panel_top.getGlobalBounds().width, all_panel_top.getGlobalBounds().height / no_of_option_menu), "Resume game"));
}

void Menu_esc_in_game::draw(sf::RenderWindow& window)
{ 
	window.draw(all_panel_top);
	for (uint8_t i = 0; i < single_option.size(); i++)
	{
		single_option[i].draw(window);
	}
	//for (auto i : single_option)
	//	i.draw(window);

}

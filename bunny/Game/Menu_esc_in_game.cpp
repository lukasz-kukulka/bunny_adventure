#include "Menu_esc_in_game.hpp"

Menu_esc_in_game::Menu_esc_in_game(sf::View& window, uint8_t type_menu, sf::Font* font_text)
{
	this->font = font_text;
	this->all_panel_top.setSize(sf::Vector2f(window.getSize().x / 3, window.getSize().y / 3));
	this->all_panel_top.setPosition(window.getCenter().x - all_panel_top.getGlobalBounds().width / 2, window.getCenter().y - all_panel_top.getGlobalBounds().height / 2);
	this->all_panel_top.setFillColor(sf::Color(255, 0, 0, 0));
	this->objects_ini(type_menu);
}

Menu_esc_in_game::~Menu_esc_in_game()
{

}

uint8_t Menu_esc_in_game::system(sf::View& window, uint8_t position_menu)
{
	uint8_t temp_return{ 0 };
	for (uint8_t i = 0; i < single_option.size(); i++)
	{
		if (i == position_menu)
		{
			single_option[i].system(window, true);
			temp_return = i;
		}
		else
		{
			single_option[i].system(window, false);
		}
	}

	return temp_return;
}

void Menu_esc_in_game::objects_ini(uint8_t type_menu)
{
	if (type_menu == 0)
	{
		single_option.push_back(Singe_option_esc_menu(font, sf::Vector2f(all_panel_top.getPosition().x, all_panel_top.getPosition().y),
			sf::Vector2f(all_panel_top.getGlobalBounds().width, all_panel_top.getGlobalBounds().height / no_of_option_menu), "Resume game", 0, true));

		single_option.push_back(Singe_option_esc_menu(font, sf::Vector2f(all_panel_top.getPosition().x, all_panel_top.getPosition().y),
			sf::Vector2f(all_panel_top.getGlobalBounds().width, all_panel_top.getGlobalBounds().height / no_of_option_menu), "Back to menu", 1, false));

		single_option.push_back(Singe_option_esc_menu(font, sf::Vector2f(all_panel_top.getPosition().x, all_panel_top.getPosition().y),
			sf::Vector2f(all_panel_top.getGlobalBounds().width, all_panel_top.getGlobalBounds().height / no_of_option_menu), "Exit game", 2, false));
	}
	else if (type_menu == 1)
	{
		this->no_of_option_menu = 2;
		single_option.push_back(Singe_option_esc_menu(font, sf::Vector2f(all_panel_top.getPosition().x, all_panel_top.getPosition().y),
			sf::Vector2f(all_panel_top.getGlobalBounds().width, all_panel_top.getGlobalBounds().height / no_of_option_menu), "Back to menu", 0, true));

		single_option.push_back(Singe_option_esc_menu(font, sf::Vector2f(all_panel_top.getPosition().x, all_panel_top.getPosition().y),
			sf::Vector2f(all_panel_top.getGlobalBounds().width, all_panel_top.getGlobalBounds().height / no_of_option_menu), "Exit game", 1, false));
	}


}

uint8_t Menu_esc_in_game::no_of_option_menu_out()
{
	return no_of_option_menu;
}

void Menu_esc_in_game::draw(sf::RenderWindow& window)
{ 
	window.draw(all_panel_top);
	for (auto i : single_option)
		i.draw(window);

}

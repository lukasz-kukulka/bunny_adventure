#include "Confirm_screen.hpp"


Confirm_screen::Confirm_screen(sf::RenderWindow& window, sf::Font* font, std::string text_input, sf::Texture* tex_color, sf::Texture* tex_grey)
{
	this->font = font;
	this->text_input = text_input;
	this->tex_color = tex_color;
	this->tex_grey = tex_grey;

	objects_ini(window);
}

uint8_t Confirm_screen::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	for (uint8_t i = 0; i < buttons.size(); i++)
	{
		uint8_t buttons_index = buttons[i].system(window, mouse);
		if (buttons_index == 12)
		{
			return 1;
		}
		if (buttons_index == 13)
		{
			return 2;
		}
	}
	return 0;
}

void Confirm_screen::objects_ini(sf::RenderWindow& window)
{
	this->background_rec.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	this->background_rec.setPosition(0, 0);
	this->background_rec.setFillColor(sf::Color(0, 0, 0, 222));
	this->info_text.setFont(*font);
	this->info_text.setString(text_input);
	this->info_text.setCharacterSize(20);
	this->info_text.setFillColor(sf::Color(111, 0, 0, 255));
	this->info_text.setOutlineThickness(1);
	this->info_text.setOutlineColor(sf::Color(255, 255, 255, 255));
	this->info_text.setPosition(window.getSize().x / 2 - info_text.getGlobalBounds().width / 2, window.getSize().y / 2 - info_text.getGlobalBounds().height / 2);
	this->buttons.push_back(Button_option(window, background_rec, tex_color, tex_grey, font, "YES", 2, 11, false));
	this->buttons.push_back(Button_option(window, background_rec, tex_color, tex_grey, font, "NO", 2, 12, false));
}

void Confirm_screen::draw(sf::RenderWindow& window)
{
	window.draw(background_rec);
	window.draw(info_text);
	for (auto i : buttons)
		i.draw(window);
}

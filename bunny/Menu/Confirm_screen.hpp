#pragma once
#include <SFML/Graphics.hpp>
#include "Button_option.hpp"
class Confirm_screen
{
public:
	Confirm_screen(sf::RenderWindow& window, sf::Font* font, std::string text_input, sf::Texture* tex_color, sf::Texture* tex_grey);
	uint8_t system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_ini(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::Font* font;
	sf::String text_input;
	sf::Text info_text;
	sf::Texture* tex_color, * tex_grey;
	sf::RectangleShape background_rec;
	std::vector<Button_option>buttons;
};

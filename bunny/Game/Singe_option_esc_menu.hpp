#pragma once
#include <SFML/Graphics.hpp>

class Singe_option_esc_menu
{
public:
	Singe_option_esc_menu(sf::Font* font_text, sf::Vector2f pos, sf::Vector2f size, std::string name, uint8_t index, bool mark);

	uint8_t system(sf::View& window, bool mark_on);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape esc_option;
	sf::RectangleShape mark_option;
	bool mark_visible{ false };
	sf::Text text_menu;
};
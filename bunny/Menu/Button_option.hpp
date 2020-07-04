#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Button_option
{
public:
	Button_option(sf::RenderWindow& window, sf::RectangleShape work_space, sf::Texture* texture, sf::Texture* texture_grey, sf::Font* font, std::string text_button, uint8_t how_many, uint8_t index, bool true_false);
	uint8_t system(sf::RenderWindow& window, sf::Vector2i mouse);
	void changing_status(uint8_t index);
	void draw(sf::RenderWindow& window);

protected:
	sf::Sprite button_sprite;
	sf::Text button_text;
	sf::Texture* button_color, *button_grey;
	sf::RectangleShape work_space, single_workspace;
	sf::Event event;
	uint8_t how_many, perm_index;
	bool enabled_button;
};


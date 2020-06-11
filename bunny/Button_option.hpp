#pragma once
#include <SFML/Graphics.hpp>

class Button_option
{
public:
	Button_option(sf::RenderWindow& window, sf::RectangleShape work_space, sf::Texture* texture, sf::Texture* texture_grey, sf::Font* font, std::string text_button, int how_many, int index);
	
	int system(sf::RenderWindow& window, sf::Vector2i mouse);
	void draw(sf::RenderWindow& window);

protected:
	sf::Sprite button_sprite;
	sf::Text button_text;
	sf::Texture* button_color, *button_grey;
	sf::RectangleShape work_space, single_workspace;
	int how_many;
};


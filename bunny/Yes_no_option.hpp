#pragma once
#include <SFML/Graphics.hpp>
class Yes_no_option
{
public:
	Yes_no_option(sf::RenderWindow& window, sf::RectangleShape work_space, sf::Texture* yes_tex, sf::Texture* no_tex, sf::Font* font, int volume, int index, std::string text_title);

	int system(sf::RenderWindow& window, sf::Vector2i mouse);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape work_space, single_workspace;
	sf::Sprite yes_button, no_button;
	sf::Texture* no_tex, *yes_tex;
	sf::Text title, on_text, off_text;
	bool no_button_bool, yes_button_bool;
};


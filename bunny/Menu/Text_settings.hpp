#pragma once
#include <SFML/Graphics.hpp>
class Text_settings
{
public:
	Text_settings(sf::RenderWindow& window, sf::RectangleShape work_space, sf::Font* font, std::string text_control, uint8_t max_x, uint8_t max_y, uint8_t index_x, uint8_t index_y);
	uint8_t system(sf::RenderWindow& window, sf::Vector2i mouse);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape work_space, single_workspace;
	sf::Sprite back_control;
	sf::Text control_text;
};


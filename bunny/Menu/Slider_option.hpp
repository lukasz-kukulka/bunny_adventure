#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Slider_option
{
public:
	Slider_option(sf::RenderWindow& window, sf::RectangleShape work_space, sf::Texture* slider, sf::Texture* slider_black_tex, sf::Texture* slider_bunny, sf::Font* font, uint8_t volume, uint8_t index, std::string text_title, uint8_t volume_index);
	uint8_t system(sf::RenderWindow& window, sf::Vector2i mouse);
	void draw(sf::RenderWindow& window);

private:
	sf::Sprite slider_all, slider_black, slider_hand;
	sf::RectangleShape single_workspace, work_space;
	sf::Text text_procets, title;
	uint8_t index, volume, volume_sound;

};


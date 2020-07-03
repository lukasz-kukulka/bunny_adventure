#pragma once
#include <SFML/Graphics.hpp>
#include "Files_operations.hpp"
class Button
{
public:
	Button(sf::RenderWindow&, sf::Texture*, sf::Font*, std::string, uint8_t, uint16_t, uint16_t);
	uint8_t system(sf::RenderWindow&, sf::Vector2i);
	void draw(sf::RenderWindow&);

private:
	sf::Sprite button_sprite;
	sf::Text button_text;
	sf::Event event;
	Files_operations load_vol;
	uint8_t button_index;
};


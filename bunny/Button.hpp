#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Button
{
public:
	Button(sf::RenderWindow&, sf::Texture*, sf::Font*, std::string, int, int, int);

	int system(sf::RenderWindow&, sf::Vector2i);
	void draw(sf::RenderWindow&);

private:
	sf::Sprite button_sprite;
	sf::Text button_text;

	int button_index;
};


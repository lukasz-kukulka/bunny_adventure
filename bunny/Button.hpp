#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Files_operations.hpp"
class Button
{
public:
	Button(sf::RenderWindow&, sf::Texture*, sf::Font*, std::string, int, int, int);

	int system(sf::RenderWindow&, sf::Vector2i);
	void draw(sf::RenderWindow&);

private:
	sf::Sprite button_sprite;
	sf::Text button_text;
	Files_operations load_vol;
	int button_index;
};


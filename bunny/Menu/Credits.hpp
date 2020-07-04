#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Option.hpp"
#include "Text.hpp"
#include "Button.hpp"
#include "Files_operations.hpp"
#include "Load_from_files.hpp"

class Credits :public Option, public Load_from_files
{
public:
	Credits(sf::RenderWindow&);
	uint8_t system(sf::RenderWindow&, sf::Vector2i);
	void settings(uint8_t volume);
	void draw(sf::RenderWindow&);

private:
	sf::Sprite background_sprite;
	std::vector<Text>texts;
	std::vector<Button>buttons;
};


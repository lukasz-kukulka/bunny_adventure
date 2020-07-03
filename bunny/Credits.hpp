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

	int system(sf::RenderWindow&, sf::Vector2i);
	void settings(int volume);
	void draw(sf::RenderWindow&);

private:
	sf::Font cat_font, good_mor, font_button;
	sf::Sprite background_sprite;
	std::vector<Text>texts;
	std::vector<Button>buttons;
	sf::SoundBuffer button_buffer;
	sf::Sound button_sound;
};


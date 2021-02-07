#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.hpp"
#include "Option.hpp"
#include "Exit.hpp"
#include "Button.hpp"
#include "Files_operations.hpp"
#include <SFML/Audio.hpp>
#include "Files_operations.hpp"

class Interface :public Option
{
public:
	Interface(sf::RenderWindow&);
	uint8_t system(sf::RenderWindow&, sf::Vector2i);
	void settings(uint8_t volume);
	void draw(sf::RenderWindow&);

private:
	sf::Sprite background_sprite;
	std::vector<Menu>button_menu;
	std::vector<Exit>exit_objects;
	std::vector<Button>buttons;
	bool play_click[5] = {1, 1, 1, 1, 1};
	bool end_animation;
	uint8_t button_answer;
	sf::Texture leaf, menu_button_left, menu_button_mid, menu_button_right, arrow_left, arrow_right, background_base, jaguar, cloud, forest;
	sf::SoundBuffer buffer_menu, buffer_menu_choise;
	sf::Sound click_sound, choise_sound;
	sf::Font font_menu_button, button_confirm_font;
};



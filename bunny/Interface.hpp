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

	int system(sf::RenderWindow&, sf::Vector2i);
	void draw(sf::RenderWindow&);

private:
	sf::Texture background_tex, menu_button_left, menu_button_mid, menu_button_right, arrow_left, arrow_right, jaguar, cloud, forest, leaf;
	sf::Sprite background_sprite;
	sf::Font font_menu_button, button_confirm_font;
	sf::SoundBuffer buffer_menu, buffer_menu_choise;
	sf::Sound click_sound, choise_sound;
	std::vector<Menu>button_menu;
	std::vector<Exit>exit_objects;
	std::vector<Button>buttons;
	bool play_click[5] = {1, 1, 1, 1, 1};
	bool end_animation;
	int button_answer;
};



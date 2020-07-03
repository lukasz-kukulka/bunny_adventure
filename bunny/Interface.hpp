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
#include "Load_from_files.hpp"

class Interface :public Option, public Load_from_files
{
public:
	Interface(sf::RenderWindow&);

	int system(sf::RenderWindow&, sf::Vector2i);
	void settings(int volume);
	void draw(sf::RenderWindow&);

private:
	sf::Sprite background_sprite;
	std::vector<Menu>button_menu;
	std::vector<Exit>exit_objects;
	std::vector<Button>buttons;
	bool play_click[5] = {1, 1, 1, 1, 1};
	bool end_animation;
	int button_answer;
};



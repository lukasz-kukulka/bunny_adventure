#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <chrono>
#include "Interface_elements.hpp"
#include "Option.hpp"

class Interface :public Option
{
public:
	Interface(sf::RenderWindow&);

	void draw(sf::RenderWindow&); //draw interface

private:
	sf::Texture background_tex, tree_tex, small_tree_tex, green1_tex, green2_tex, green3_tex, house_tex, rock_tex, road_tex, dan_tex;

	std::vector<Interface_elements>background;
	std::vector<Interface_elements>tree;
	std::vector<Interface_elements>small_tree;
	std::vector<Interface_elements>green1;
	std::vector<Interface_elements>green2;
	std::vector<Interface_elements>green3;
	std::vector<Interface_elements>road;
	std::vector<Interface_elements>rock;
	std::vector<Interface_elements>dan;

	std::default_random_engine generator;

	int win_size_X, win_size_Y;

};


#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Exit
{
public:
	Exit(sf::RenderWindow&, sf::Texture*, sf::Texture*, sf::Texture*, sf::Font*);

	int system(sf::RenderWindow&, sf::Vector2i);
	int sub();
	int fox_pos_X_out();
	int fox_pos_Y_out();
	void no_exit();
	void draw(sf::RenderWindow&);
	
	
private:
	sf::Text ask;
	sf::Sprite bunny_sprite, cloud_sprite, forest_tex;
	std::string full_ask, single_ask;
	int transparent;
};


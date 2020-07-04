#pragma once
#include <SFML/Graphics.hpp>
class Exit
{
public:
	Exit(sf::RenderWindow&, sf::Texture*, sf::Texture*, sf::Texture*, sf::Font*);
	uint8_t system(sf::RenderWindow&, sf::Vector2i);
	uint8_t sub();
	uint16_t fox_pos_X_out();
	uint16_t fox_pos_Y_out();
	void no_exit();
	void draw(sf::RenderWindow&);
	
	
private:
	sf::Text ask;
	sf::Sprite bunny_sprite, cloud_sprite, forest_tex;
	std::string full_ask, single_ask;
	uint8_t transparent;
};


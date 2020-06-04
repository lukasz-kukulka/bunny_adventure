#pragma once
#include <SFML/Graphics.hpp>
class Interface_elements
{
public:
	Interface_elements(sf::Texture*, int, int, double, double);



	void draw(sf::RenderWindow&);
private:

	sf::Sprite texture_sprite;

	
};


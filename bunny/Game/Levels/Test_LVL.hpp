#pragma once
#include <SFML/Graphics.hpp>
#include "../Choise_level.hpp"

class Test_LVL :public Choise_level
{
public:
	Test_LVL(sf::RenderWindow& window);

	uint8_t system(sf::RenderWindow& window);
	//void objects_ini(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	std::vector<std::vector<sf::Sprite>>level_test;
};
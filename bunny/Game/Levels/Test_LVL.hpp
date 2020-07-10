#pragma once
#include <SFML/Graphics.hpp>
#include "../Choise_level.hpp"
#include "../Object_lvl_ini.hpp"

class Test_LVL :public Choise_level
{
public:
	Test_LVL(sf::RenderWindow& window);

	uint8_t system();
	void objects_ini();
	void draw(sf::RenderWindow& window);

private:
	sf::Vector2f size_lvl;
	uint8_t one_tile;
	std::string file_name;
	Object_lvl_ini lvl0;
	bool ini_object_true;
};
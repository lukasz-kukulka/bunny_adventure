#pragma once
#include <SFML/Graphics.hpp>
#include "../Choise_level.hpp"
#include "../Object_lvl_ini.hpp"

class Test_LVL :public Choise_level
{
public:
	Test_LVL(sf::RenderWindow& window);

	uint8_t system();
	void objects_ini(sf::RenderWindow& window, sf::Vector2i size_board);
	sf::Sprite* tiles(uint32_t index);
	uint16_t no_til();
	uint8_t bonus_size(uint8_t index);
	void draw(sf::RenderWindow& window);

private:
	sf::Vector2f size_lvl;
	std::string file_name;
	Object_lvl_ini lvl0;
	bool ini_object_true;
	uint8_t bonus501, bonus502, bonus503, bonus504, bonus505, bonus506, bonus507, bonus508, bonus509, bonus510, bonus511, bonus512;

};
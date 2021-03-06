#pragma once
#include <SFML/Graphics.hpp>
#include "../Choise_level.hpp"
#include "../Object_lvl_ini.hpp"

class Test_LVL_2 :public Choise_level
{
public:
	Test_LVL_2(sf::RenderWindow& window);
	uint8_t system();
	void objects_ini(sf::RenderWindow& window, sf::Vector2i size_board);
	sf::Sprite* tiles(uint32_t index);
	uint16_t no_til();
	single_tile_out_for_bonus bonus_parameters(uint16_t index);
	uint16_t bonus_size();
	uint16_t tiles_type(uint16_t index);
	void draw(sf::RenderWindow& window);

private:
	sf::Vector2f size_lvl;
	std::string file_name;
	Object_lvl_ini lvl1;
	bool ini_object_true;
};



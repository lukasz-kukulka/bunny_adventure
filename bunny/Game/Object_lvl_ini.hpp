#pragma once
#include <SFML/Graphics.hpp>
#include "Single_tile.hpp"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

struct single_tile_out_for_bonus
{
	int16_t id{ 0 };
	int8_t type{ 0 };
	int16_t x_position{ 0 };
	int16_t y_position{ 0 };
};

class Object_lvl_ini
{


public:
	Object_lvl_ini(sf::RenderWindow& window);
	uint8_t system(sf::RenderWindow& window);
	void create_objects(sf::RenderWindow& window, std::string path_lvl, sf::Vector2f size_board);
	sf::Sprite* shape(uint32_t index);
	void initialization_structure(std::string type, sf::Vector2i position_tile);
	uint16_t no_tiles();
	single_tile_out_for_bonus tiles_setings_to_bonus(int index);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture tex001, tex002, tex003, tex004, tex005, tex006, tex007, tex008, tex009, tex010, tex011, tex012, tex013, tex014, tex015,
		tex016, tex017, tex018, tex020, tex021, tex022, tex023, tex024, tex101, tex102, tex103, tex104, tex105, tex106, tex107, tex108, temp_tex;
	uint8_t no_line, no_tiles_row;
	std::vector<single_tile_out_for_bonus>struct_bonus_out;
	std::vector<Single_tile>tiles_tex;
	std::string line, temp;
};


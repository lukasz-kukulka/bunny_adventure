#include "Test_LVL_2.hpp"

Test_LVL_2::Test_LVL_2(sf::RenderWindow& window) :lvl1(window)
{
	this->size_lvl.x = 10000;
	this->size_lvl.y = 2000;
	this->file_name = "Game/Textures/Levels/lvl1.txt";
	this->ini_object_true = true;
}

uint8_t Test_LVL_2::system()
{
	return 0;
}

void Test_LVL_2::objects_ini(sf::RenderWindow& window, sf::Vector2i size_board)
{
	if (ini_object_true == true)
	{
		lvl1.create_objects(window, file_name, sf::Vector2f(size_board));
		ini_object_true = false;
	}
}

sf::Sprite* Test_LVL_2::tiles(uint32_t index)
{

	return lvl1.shape(index);
}

uint16_t Test_LVL_2::no_til()
{
	return lvl1.no_tiles();
}

single_tile_out_for_bonus Test_LVL_2::bonus_parameters(uint16_t index)
{
	return lvl1.tiles_setings_to_bonus(index);
}

uint16_t Test_LVL_2::bonus_size()
{
	return lvl1.no_bonuses();
}

uint16_t Test_LVL_2::tiles_type(uint16_t index)
{
	return lvl1.tiles_type(index);
}


void Test_LVL_2::draw(sf::RenderWindow& window)
{
	lvl1.draw(window);
}



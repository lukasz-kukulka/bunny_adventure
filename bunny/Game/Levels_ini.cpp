#include "Levels_ini.hpp"

Levels_ini::Levels_ini(sf::RenderWindow& window) : test_lvl(window), pick_lvl_test(window)
{
	//pick_items = nullptr;
	this->level_indicator = 99;                  // if lvl will be more than 99 changing this type ////////////////////////////////////
	this->lvl_size = sf::Vector2i(0, 0);
	choise_level = &test_lvl;
	this->no_til = 0;
	//std::cout << "--->" << static_cast<int>(game_level)  << std::endl;
}

//Levels_ini::~Levels_ini()
//{
//	choise_level = nullptr;
//}

uint8_t Levels_ini::system(sf::RenderWindow& window, uint8_t game_level)
{
	this->game_lvl = game_level;
	switch (game_lvl)
	{
	case 0:
	{
		if (level_indicator != 0)
		{
			lvl_size = sf::Vector2i(10000, 2000);
			choise_level = &test_lvl;
			level_indicator = 0;
		}
		break;
	}
	default:
		break;
	}
	choise_level->objects_ini(window, lvl_size);
	pick_lvl_test.system();
	return 0;
}

sf::Vector2i Levels_ini::level_size()
{
	return lvl_size;
}

sf::Sprite* Levels_ini::tiles(uint32_t index)
{
	choise_level->tiles(index);
	til_ini = choise_level->tiles(index);
	return til_ini;
}

uint16_t Levels_ini::no_tiles()
{
	no_til = choise_level->no_til();
	return no_til;
}

void Levels_ini::draw(sf::RenderWindow& window)
{
	switch (game_lvl)
	{
	case 0:
	{
		//choise_pick_items = &pick_lvl_test;
		//choise_level = &test_lvl;
		choise_level->draw(window);
		pick_lvl_test.draw(window);
		break;
	}
	default:
		break;
	}
	//choise_level = nullptr;
}


#include "Levels_ini.hpp"

Levels_ini::Levels_ini(sf::RenderWindow& window) : test_lvl(window), pick_lvl_test(window)
{
	//pick_items = nullptr;
	this->level_indicator = 99;                  // if lvl will be more than 99 changing this type ////////////////////////////////////
	this->lvl_size = sf::Vector2i(0, 0);
	choise_level = nullptr;
	choise_bonus = nullptr;
	this->no_til = 0;
	this->bonus_delete_yes = false;
	this->bonus_yes = true;
	this->bonus_delete_element = 0;
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
			//std::cout << "---> teste " << std::endl;
			//test_lvl_pick.push_back(window);
			lvl_size = sf::Vector2i(10000, 2000);
			choise_level = &test_lvl;
			choise_bonus = &pick_lvl_test;
			choise_bonus->initialize_pick_class(window);
			choise_bonus->initialize_singe_bonus_item(window);
			this->bonus_yes = true;
			//choise_level->bonus_parameters(i);
			//choise_bonus->
			level_indicator = 0;
			//std::cout << bonuses.size() << std::endl;
			
		}
		break;
	}
	default:
		break;
	}
	choise_level->objects_ini(window, lvl_size);
	
	//choise_level->
	//std::cout << no_tiles() << std::endl;
	//std::cout << choise_level->bonus_parameters(no_tiles()-1).id << std::endl;
	if (bonus_yes == true)
	{
		bonus_vector();
	}
	choise_bonus->system();
	if (bonus_delete_yes == true)
	{
		choise_bonus->delete_bonus_elements(bonus_delete_element);
	}

	//choise_bonus->bonus_sprite_out
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

single_tile_out_for_bonus Levels_ini::structure_bonuses(uint16_t index)
{
	return struct_bonus_out[index];
}

void Levels_ini::bonus_vector()
{
	//std::cout << no_tiles() << std::endl;
	//choise_bonus->bonus_parameters_ini(choise_level->bonus_parameters(i));
	for (uint16_t i = 0; i < no_tiles(); i++)
	{
		bonuses.push_back(single_tile_out_for_bonus(choise_level->bonus_parameters(i))); // do usuniêcia na koniec
		choise_bonus->bonus_parameters_ini(choise_level->bonus_parameters(i));
	}
	bonus_yes = false;
	pick_lvl_test.no_of_tiles(no_tiles());
}

uint16_t Levels_ini::no_bonuses()
{
	return 0;
}

sf::Sprite Levels_ini::bonus_sprite_out(uint16_t index)
{

	//std::cout << index << std::endl;
	return pick_lvl_test.bonus_sprite_out(index);
}

uint16_t Levels_ini::no_of_bonus_out()
{
	//std::cout << pick_lvl_test.no_of_bonus_out() << std::endl;
	return pick_lvl_test.no_of_bonus_out();
}

void Levels_ini::delete_bonus_yes(bool index)
{
	this->bonus_delete_yes = index;
}

void Levels_ini::delete_bonus_ini(uint16_t index)
{
	this->bonus_delete_element = index;
}

void Levels_ini::draw(sf::RenderWindow& window)
{
	switch (game_lvl)
	{
	case 0:
	{
		choise_level->draw(window);
		choise_bonus->draw(window);
		break;
	}
	default:
		break;
	}
	//choise_level = nullptr;
}


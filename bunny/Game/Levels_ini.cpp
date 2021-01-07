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
	this->font.loadFromFile("Game/Fonts/beachday.ttf");
	//std::cout << "--->" << static_cast<int>(game_level)  << std::endl;
}

//Levels_ini::~Levels_ini()
//{
//	choise_level = nullptr;
//}

uint8_t Levels_ini::system(sf::RenderWindow& window, uint8_t game_level)
{
	this->game_lvl = game_level;
	//std::cout << "--->  " << static_cast<int>(game_level) << std::endl;
	switch (game_lvl)
	{
	case 0:
	{
		if (level_indicator != 0)
		{
			this->turn_off_all_functions = false;
			//std::cout << "---> teste " << std::endl;
			lvl_size = sf::Vector2i(10000, 2000);
			choise_level = &test_lvl;
			choise_bonus = &pick_lvl_test;
			choise_bonus->initialize_pick_class(window);
			choise_bonus->initialize_singe_bonus_item(window);
			this->bonus_yes = true;
			level_indicator = 0;		
		}
		break;
	}
	default:
	{
		//std::cout << "---> test " << std::endl;
		if (level_indicator != 99)
		{
			game_end_ini();
			level_indicator = 99;
		}
		this->turn_off_all_functions = true;
		for (int i = 0; i < game_over.size(); i++)
		{
			//game_over[i].system();
			if (game_over[i].system() == 1)
			{
				//std::cout << "---> test " << std::endl;
				this->game_over_ini = true;
			}
		}
		break;
	}
		
	}
	choise_level->objects_ini(window, lvl_size);

	if (bonus_yes == true)
	{
		bonus_vector();
	}
	choise_bonus->system(window);
	if (bonus_delete_yes == true)
	{
		choise_bonus->delete_bonus_elements(bonus_delete_element);
		delete_bonus_yes(false, player_pos);
	}

	if (pick_lvl_test.no_of_bonus_out() == 0)
	{
		
		if (initialization_end_lvl_screen == false)
		{
			//std::cout << "---> 1 " << std::endl;
			level_change();
			initialization_end_lvl_screen = true;
		}
		else
		{
			//std::cout << "---> 2 " << std::endl;
			for (int i = 0; i < level_end_vector.size(); i++)
			{
				level_end_vector[0].system(view_level_ini);
			}
			
		}
		this->turn_off_all_functions = true;
		//std::cout << "---> 3 " << std::endl;
	}
	else
	{
		//std::cout << "---> 4 " << std::endl;
		start_new_lvl();
		initialization_end_lvl_screen == true;
		this->turn_off_all_functions = false;
	}
		

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
	for (uint16_t i = 0; i < test_lvl.bonus_size(); i++)
	{
		choise_bonus->bonus_parameters_ini(choise_level->bonus_parameters(i));
	}
	bonus_yes = false;
	pick_lvl_test.no_of_tiles(test_lvl.bonus_size());
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

void Levels_ini::delete_bonus_yes(bool index, sf::Sprite* player)
{
	player_pos = player;
	bonus_delete_yes = index;
	pick_lvl_test.player_mid_position(player_pos);
}

void Levels_ini::delete_bonus_ini(uint16_t index)
{
	
	this->bonus_delete_element = index;
	//std::cout << bonus_delete_element << std::endl;
}

uint16_t Levels_ini::tiles_type(uint16_t index)
{
	//std::cout << test_lvl.tiles_type(index) << std::endl;
	return test_lvl.tiles_type(index);
}

uint8_t Levels_ini::type_item_bonus_out(uint16_t index)
{
	return pick_lvl_test.type_item_bonus_out(index);
}

bool Levels_ini::confirm_bonus_delete()
{
	return pick_lvl_test.confirm_bonus_delete();
}

uint8_t Levels_ini::no_of_level_out()
{
	return no_of_level;
}

void Levels_ini::level_change()
{
	level_end_vector.push_back(Level_end(view_level_ini, &font, game_lvl));
}

void Levels_ini::start_new_lvl()
{
	for (int i = 0; i < level_end_vector.size(); i++)
	{
		level_end_vector.erase(level_end_vector.begin());
	}
}

void Levels_ini::view_ini(sf::View& view)
{
	view_level_ini = view;
	pick_lvl_test.view_ini(view_level_ini);
}

uint8_t Levels_ini::game_lvl_out()
{
	return game_lvl;
}

void Levels_ini::game_lvl_change(uint8_t lvl)
{
	this->game_lvl = lvl;
}

void Levels_ini::game_end_ini()
{
	start_new_lvl();
	game_over.push_back(Game_over(view_level_ini, &font));
}

bool Levels_ini::turn_off_all_function_check()
{
	return turn_off_all_functions;
}

bool Levels_ini::game_over_ini_out()
{
	return game_over_ini;
}


void Levels_ini::draw(sf::RenderWindow& window)
{
	switch (game_lvl)
	{
	case 0:
	{
		choise_level = &test_lvl;
		choise_bonus = &pick_lvl_test;
		break;
	}
	default:
		break;
	}
	//system(window, 0);
	if (level_indicator != 99)
	{
		choise_level->draw(window);
		choise_bonus->draw(window);
	}

	for (auto i : level_end_vector)
		i.draw(window);
	for (auto i : game_over)
		i.draw(window);
}


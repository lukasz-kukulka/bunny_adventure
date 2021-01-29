#include "Pick_items_ini.hpp"


Pick_items_ini::Pick_items_ini(sf::RenderWindow& window)
{
	this->awa501.loadFromFile("Game/Textures/Levels/Awards/awa501.png");
	this->awa502.loadFromFile("Game/Textures/Levels/Awards/awa502.png");
	this->awa503.loadFromFile("Game/Textures/Levels/Awards/awa503.png");
	this->awa504.loadFromFile("Game/Textures/Levels/Awards/awa504.png");
	this->awa505.loadFromFile("Game/Textures/Levels/Awards/awa505.png");
	this->awa506.loadFromFile("Game/Textures/Levels/Awards/awa506.png");
	this->awa507.loadFromFile("Game/Textures/Levels/Awards/awa507.png");
	this->awa508.loadFromFile("Game/Textures/Levels/Awards/awa508.png");
	this->awa509.loadFromFile("Game/Textures/Levels/Awards/awa509.png");
	this->awa510.loadFromFile("Game/Textures/Levels/Awards/awa510.png");
	this->awa511.loadFromFile("Game/Textures/Levels/Awards/awa511.png");
	this->awa512.loadFromFile("Game/Textures/Levels/Awards/awa512.png");
	this->font.loadFromFile("Game/Fonts/beachday.ttf");
	this->bonus_quantity = 0;
	this->tiles_quantity = 0;
	this->bonus_position_ini = true;
	this->random_pos = 0;
}

uint8_t Pick_items_ini::system(sf::RenderWindow& window)
{

	if (bonus_position_ini == true)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int>dist(0, no_of_tiles_out() - 2);
		for (uint16_t i = bonuses.size(); i > 0; i--)
		{

			random_pos = dist(mt);
			teporary_tiles_tab.push_back(int(random_pos));
			for (uint16_t j = teporary_tiles_tab.size() - 1; j > 0; j--)
			{
				if (random_pos == teporary_tiles_tab[j - 1])
				{
					teporary_tiles_tab.erase(teporary_tiles_tab.begin() + teporary_tiles_tab.size() - 1);
					j--;
					i++;
					break;
				}
			}
		}
		//for (uint16_t z = teporary_tiles_tab.size(); z > 0; z--)
		//{
		//	bonuses[z - 1].changing_bonus_position(sf::Vector2f(tiles_parameters[teporary_tiles_tab[z - 1]].x_position,
		//		tiles_parameters[teporary_tiles_tab[z - 1]].y_position - bonuses[z - 1].globalbound_out().y));
		//}
		for (uint16_t i = 0; i < bonuses.size(); i++)
		{
			bonuses[i].changing_bonus_position(sf::Vector2f(tiles_parameters[teporary_tiles_tab[i]].x_position,
			tiles_parameters[teporary_tiles_tab[i]].y_position - bonuses[i].globalbound_out().y));
		}
		bonus_position_ini = false;
		//std::cout << "TEST" << std::endl;
	}
	animation_delete_bonus_ini(window);
	return 0;
}

void Pick_items_ini::single_pick_items_ini(sf::RenderWindow& window, uint8_t type, std::string show_text)
{
	if (type == 1)
	{
		bonuses.push_back(Single_pick_bonus(window, &awa501, 1));
		bonus_info.push_back(Bonus_extra_effect(window, &font, show_text, 1));
	}
	else if (type == 2)
	{
		//std::cout << "TEST" << std::endl;
		bonuses.push_back(Single_pick_bonus(window, &awa502, 2));
		bonus_info.push_back(Bonus_extra_effect(window, &font, show_text, 2));
	}
	else if (type == 3)
	{
		bonuses.push_back(Single_pick_bonus(window, &awa503, 3));
		bonus_info.push_back(Bonus_extra_effect(window, &font, show_text, 3));
	}
	else if (type == 4)
	{
		bonuses.push_back(Single_pick_bonus(window, &awa504, 4));
		bonus_info.push_back(Bonus_extra_effect(window, &font, show_text, 4));
	}
	else if (type == 5)
	{
		bonuses.push_back(Single_pick_bonus(window, &awa505, 5));
		bonus_info.push_back(Bonus_extra_effect(window, &font, show_text, 5));
	}
	else if (type == 6)
	{
		bonuses.push_back(Single_pick_bonus(window, &awa506, 6));
		bonus_info.push_back(Bonus_extra_effect(window, &font, show_text, 6));
	}
	else if (type == 7)
	{
		bonuses.push_back(Single_pick_bonus(window, &awa507, 7));
		bonus_info.push_back(Bonus_extra_effect(window, &font, show_text, 7));
	}
	else if (type == 8)
	{
		bonuses.push_back(Single_pick_bonus(window, &awa508, 8));
		bonus_info.push_back(Bonus_extra_effect(window, &font, show_text, 8));
	}
	else if (type == 9)
	{
		bonuses.push_back(Single_pick_bonus(window, &awa509, 9));
		bonus_info.push_back(Bonus_extra_effect(window, &font, show_text, 9));
	}
	else if (type == 10)
	{
		bonuses.push_back(Single_pick_bonus(window, &awa510, 10));
		bonus_info.push_back(Bonus_extra_effect(window, &font, show_text, 10));
	}
	else if (type == 11)
	{
		bonuses.push_back(Single_pick_bonus(window, &awa511, 11));
		bonus_info.push_back(Bonus_extra_effect(window, &font, show_text, 11));
	}
	else if (type == 12)
	{
		bonuses.push_back(Single_pick_bonus(window, &awa512, 12));
		bonus_info.push_back(Bonus_extra_effect(window, &font, show_text, 12));
	}
	
}

void Pick_items_ini::bonus_parameters_ini(single_tile_out_for_bonus index)
{
	tiles_parameters.push_back(single_tile_out_for_bonus(index));
	tiles_parameters.push_back(single_tile_out_for_bonus(index));
	tiles_parameters[tiles_parameters.size() - 1].x_position = tiles_parameters[tiles_parameters.size() - 1].x_position + 50;
}

void Pick_items_ini::bonus_quantity_in(uint16_t q)
{
	this->bonus_quantity = q;
}

void Pick_items_ini::no_of_tiles_in(uint16_t index)
{
	this->tiles_quantity = index * 2;
}

sf::Sprite Pick_items_ini::bonus_sprite_out(uint16_t index)
{
	return bonuses[index].bonus_out();
}

uint16_t Pick_items_ini::no_of_bonus_out()
{
	return bonuses.size();
}

uint16_t Pick_items_ini::no_of_tiles_out()
{
	//std::cout << tiles_parameters.size() << std::endl;
	return tiles_quantity;
}

void Pick_items_ini::animation_delete_bonus_ini(sf::RenderWindow& window)
{
	
	for (int i = 0; i < bonuses.size(); i++)
	{

		this->confirm_delete_variable = false;
		//std::cout << i << std::endl;
		//bonus_info[i].system(view_window);
		bonuses[i].animation_ini(window ,player_sprite_out());
		if (bonuses[i].animation_finish_out() == true)
		{
			//bonus_info.erase(bonus_info.begin() + i);
			bonuses.erase(bonuses.begin() + i);
			this->confirm_delete_variable = true;
			//i=0;

			break;
		}
	}
	for (int i = 0; i < bonus_info.size(); i++)
	{

		//this->confirm_delete_variable = false;
		//std::cout << i << std::endl;
		bonus_info[i].system(view_window);
		//bonuses[i].animation_ini(window, player_sprite_out());
		if (bonus_info[i].system(view_window) == 1)
		{
			bonus_info.erase(bonus_info.begin() + i);
			//i=0;
			break;
		}
	}
}

void Pick_items_ini::player_mid_position(sf::Sprite* player)
{
	player_sprite = player;
}

sf::Sprite* Pick_items_ini::player_sprite_out()
{
	return player_sprite;
}

void Pick_items_ini::delete_bonus_ele(uint16_t element_index)
{
	bonuses[element_index].animation_delete();
	bonus_info[element_index].can_delete_change(true);
}

bool Pick_items_ini::confirm_bonus_delete()
{
	return confirm_delete_variable;
}

uint8_t Pick_items_ini::type_item_bonus_out(uint16_t index)
{
	return bonuses[index].type_item_out();
}

void Pick_items_ini::view_ini(sf::View& view)
{
	view_window = view;
}

void Pick_items_ini::delete_bonus_item_confirm(uint16_t index)
{
	bonuses[index].delete_item_confirm();
}

bool Pick_items_ini::delete_bonus_item_confirm_out(uint16_t index)
{
	return bonuses[index].if_can_you_delete_item();
}

void Pick_items_ini::draw(sf::RenderWindow& window)
{
	for (auto i : bonuses)
		i.draw(window);
	for (auto i : bonus_info)
		i.draw(window);
}



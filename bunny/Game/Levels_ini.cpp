#include "Levels_ini.hpp"

Levels_ini::Levels_ini(sf::RenderWindow& window) :test_lvl(window)
{
	this->lvl_size = sf::Vector2i(0, 0);
	this->choise_level = &test_lvl;
	this->no_til = 0;
	//std::cout << "--->" << static_cast<int>(game_level)  << std::endl;
}

uint8_t Levels_ini::system(sf::RenderWindow& window, uint8_t game_level)
{
	this->game_lvl = game_level;
	switch (game_lvl)
	{
	case 0:
	{
		this->lvl_size = sf::Vector2i(10000, 2000);
		this->choise_level = &test_lvl;
		this->choise_level->objects_ini(window, lvl_size);
		
		break;
	}
	default:
		break;
	}
	//choise_level = nullptr;
	return 0;
}

sf::Vector2i Levels_ini::level_size()
{
	return lvl_size;
}

sf::Sprite* Levels_ini::tiles(uint32_t index)
{
	//choise_level->tiles(index);
	this->til_ini = choise_level->tiles(index);
	//choise_level = nullptr;
	return til_ini;
}

uint16_t Levels_ini::no_tiles()
{
	this->no_til = choise_level->no_til();
	return no_til;
}

void Levels_ini::draw(sf::RenderWindow& window)
{
	switch (game_lvl)
	{
	case 0:
	{
		
		this->choise_level = &test_lvl;
		this->choise_level->draw(window);
		break;
	}
	default:
		break;
	}
	//choise_level = nullptr;
}


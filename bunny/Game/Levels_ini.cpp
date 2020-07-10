#include "Levels_ini.hpp"

Levels_ini::Levels_ini(sf::RenderWindow& window, uint8_t game_level) :test_lvl(window)
{
	this->game_lvl = game_level;
	this->choise_level = &test_lvl;
	//std::cout << "--->" << static_cast<int>(game_level)  << std::endl;
}

uint8_t Levels_ini::system()
{
	switch (game_lvl)
	{
	case 0:
	{
		this->choise_level = &test_lvl;
		this->choise_level->objects_ini();
		break;
	}
	default:
		break;
	}
	return 0;
}

void Levels_ini::draw(sf::RenderWindow& window)
{
	switch (game_lvl)
	{
	case 0:
	{
		this->choise_level->draw(window);
		break;
	}
	default:
		break;
	}
	
}

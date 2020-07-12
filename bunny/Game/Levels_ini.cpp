#include "Levels_ini.hpp"

Levels_ini::Levels_ini(sf::RenderWindow& window) :test_lvl(window)
{
	
	this->choise_level = &test_lvl;
	//std::cout << "--->" << static_cast<int>(game_level)  << std::endl;
}

uint8_t Levels_ini::system(sf::RenderWindow& window, uint8_t game_level)
{
	this->game_lvl = game_level;
	switch (game_lvl)
	{
	case 0:
	{
		this->choise_level = &test_lvl;
		this->choise_level->objects_ini(window, sf::Vector2f(10000.0, 2000.0));
		break;
	}
	default:
		break;
	}
	this->choise_level = nullptr;
	return 0;
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
	this->choise_level = nullptr;
}


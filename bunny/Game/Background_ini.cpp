#include "Background_ini.hpp"

Background_ini::Background_ini(sf::RenderWindow& window, uint8_t game_level)
{
	this->game_lvl = game_level;
	// ======================================================================================Textures====================================================================
	this->sky_texture.loadFromFile("Game/Textures/sky_back.jpg");
	this->forest_dark_texture.loadFromFile("Game/Textures/forest_back_dark.png");
	this->forest_mid_texture.loadFromFile("Game/Textures/forest_back_mid.png");
	this->forest_light_texture.loadFromFile("Game/Textures/forest_back_light.png");

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Backgroung::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	this->objects_ini(window);
}

uint8_t Background_ini::system(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (uint8_t i = 0; i < skys.size(); i++)
		{
			skys[i].move_background(window, -1);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (uint8_t i = 0; i < skys.size(); i++)
		{
			skys[i].move_background(window, 1);
		}
	}
	for (auto i : skys)// ============Backgroung 1====================================================================
		i.system(window);// ::::::::::::::::::Backgroung 1::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	return 0;
}

void Background_ini::objects_ini(sf::RenderWindow& window)
{
	if (game_lvl == 0) // ============Backgroung 1====================================================================
	{
		this->skys.push_back(Background(window, &sky_texture, 0, 0, 1));
		this->skys.push_back(Background(window, &sky_texture, 0, 1, 1));
		this->skys.push_back(Background(window, &forest_dark_texture, 1, 0, 2));
		this->skys.push_back(Background(window, &forest_dark_texture, 1, 1, 2));
		this->skys.push_back(Background(window, &forest_mid_texture, 1, 0, 3));
		this->skys.push_back(Background(window, &forest_mid_texture, 1, 1, 3));
		this->skys.push_back(Background(window, &forest_light_texture, 1, 0, 4));
		this->skys.push_back(Background(window, &forest_light_texture, 1, 1, 4));
	}// ::::::::::::::::::Backgroung 1::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
}

void Background_ini::draw(sf::RenderWindow& window)
{
		for (auto i : skys)
		i.draw(window);
}

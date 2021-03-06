#include "Background_ini.hpp"

Background_ini::Background_ini(sf::RenderWindow& window)
{
	this->sky_texture.loadFromFile("Game/Textures/sky_back.png");
	this->forest_dark_texture.loadFromFile("Game/Textures/forest_back_dark.png");
	this->forest_mid_texture.loadFromFile("Game/Textures/forest_back_mid.png");
	this->forest_light_texture.loadFromFile("Game/Textures/forest_back_light.png");
	this->objects_ini_available = true;
	this->game_lvl = 0;
}

uint8_t Background_ini::system(sf::RenderWindow& window, sf::View& view_game, uint8_t lvl)
{
	view_window = view_game;
	this->game_lvl = lvl;
	if (objects_ini_available == true)
	{
		objects_ini_available = false;
		this->objects_ini(window, view_window);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (uint8_t i = 0; i < skys.size(); i++)
		{
			skys[i].move_background_view(-1, view_window);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (uint8_t i = 0; i < skys.size(); i++)
		{
			skys[i].move_background_view(1, view_window);
		}
	}
	return 0;
}

void Background_ini::objects_ini(sf::RenderWindow& window, sf::View& view_game)
{
	view_window = view_game;
	this->skys.push_back(Background(window, &sky_texture, 0, 0, 0.1, view_window));
	this->skys.push_back(Background(window, &sky_texture, 0, 1, 0.1, view_window));
	this->skys.push_back(Background(window, &forest_dark_texture, 1, 0, 0.4, view_window));
	this->skys.push_back(Background(window, &forest_dark_texture, 1, 1, 0.4, view_window));
	this->skys.push_back(Background(window, &forest_mid_texture, 1, 0, 1.2, view_window));
	this->skys.push_back(Background(window, &forest_mid_texture, 1, 1, 1.2, view_window));
	this->skys.push_back(Background(window, &forest_light_texture, 1, 0, 4, view_window));
	this->skys.push_back(Background(window, &forest_light_texture, 1, 1, 4, view_window));
}

void Background_ini::backgroud_restart(sf::RenderWindow& window, sf::View& view_game)
{
	view_window = view_game;
	skys.erase(skys.begin(), skys.end());
	objects_ini(window, view_window);
}

void Background_ini::draw(sf::RenderWindow& window)
{
	for (auto i : skys)
		i.draw(window);
}

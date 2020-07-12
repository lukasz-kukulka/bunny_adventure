#pragma once
#include <SFML/Graphics.hpp>
#include "../Menu/Option.hpp"
#include "Background_ini.hpp"
#include "Player.hpp"
#include "Levels_ini.hpp"

class Game_ini :public Option
{
public:
	Game_ini(sf::RenderWindow& window);

	uint8_t system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_ini(sf::RenderWindow& window);
	void settings(uint8_t volume);
	void draw(sf::RenderWindow& window);

private:
	uint8_t game_level;
	float time_animation;
	sf::Texture bunny_tex;
	std::vector<Player>player_bunny;
	sf::Clock clock_animation;
	Levels_ini level_ini;
	Background_ini background_ini;
	sf::View view_game;
};


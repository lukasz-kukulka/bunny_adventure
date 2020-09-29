#pragma once
#include <SFML/Graphics.hpp>
#include "../Menu/Option.hpp"
#include "Background_ini.hpp"
#include "Player.hpp"
#include "Levels_ini.hpp"
#include "Colisions.hpp"

class Game_ini :public Option
{
public:
	Game_ini(sf::RenderWindow& window);
	//~Game_ini();
	uint8_t system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_ini(sf::RenderWindow& window);
	void settings(uint8_t volume);
	void draw(sf::RenderWindow& window);

private:
	uint8_t game_level;
	float time_animation, time_directions;
	sf::Texture bunny_tex;
	//sf::Vector2i level_size_map;
	sf::Event event;
	std::vector<Player>player_bunny;
	sf::Clock clock_animation, clock_directions;
	Levels_ini level_ini;
	Background_ini background_ini;
	Colisions colision;
	sf::View view_game;
	bool direction_enabled;
};


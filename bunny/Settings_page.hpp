#pragma once
#include <SFML/Graphics.hpp>
#include "Option.hpp"
#include "Section.hpp"

class Settings_page :public Option
{
public:
	Settings_page(sf::RenderWindow&);

	int system(sf::RenderWindow&, sf::Vector2i);
	void draw(sf::RenderWindow&);

private:
	sf::Texture background;
	sf::Sprite background_sprite;
	sf::RectangleShape basic;
	sf::Font sec_font;

	std::vector<Section>sections;
	int settings_sections_no;
};


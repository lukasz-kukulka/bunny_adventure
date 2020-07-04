#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Section
{
public:
	Section(sf::RenderWindow& window, uint8_t index_section, std::string title, uint8_t limit_section, sf::RectangleShape& basic, sf::Font* font, sf::Texture* arrow);
	uint8_t system(sf::RenderWindow&, sf::Vector2i);
	sf::RectangleShape shape();
	void draw(sf::RenderWindow&);
private:
	sf::Sprite arrow_sprite;
	sf::Text title_section;
	sf::RectangleShape basic_rec, section_rec, top_rec, cursor_rec, funcion_rec;

};


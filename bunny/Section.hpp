#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Section
{
public:
	Section(sf::RenderWindow& window, int index_section, std::string title, int limit_section, sf::RectangleShape& basic, sf::Font* font);

	int system(sf::RenderWindow&, sf::Vector2i);
	sf::RectangleShape shape();
	void draw(sf::RenderWindow&);
private:
	sf::Text title_section;
	sf::RectangleShape basic_rec, section_rec, top_rec, cursor_rec, funcion_rec;

};


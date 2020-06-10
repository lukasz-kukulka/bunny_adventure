#pragma once
#include <SFML/Graphics.hpp>
class Category
{
public:
	Category(sf::RenderWindow&, sf::Texture*, sf::Font*, std::string, int);

	int system(sf::RenderWindow&, sf::Vector2i);
	int pos_y();
	void draw(sf::RenderWindow&);
private:
	sf::Sprite category_sprite;
	sf::Text text_category;

	int index_cat;
};


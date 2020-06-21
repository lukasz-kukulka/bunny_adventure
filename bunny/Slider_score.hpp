#pragma once
#include <SFML/Graphics.hpp>


class Slider_score
{
public:
	Slider_score(sf::RenderWindow& window, sf::RectangleShape &base, sf::Texture* up, sf::Texture* mid, sf::Texture* down);
	int system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_ini(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture up_tex, mid_tex, down_tex;
	sf::Sprite slider_up, slider_mid, slider_down;
	sf::RectangleShape rec_base, slider_shape;
};


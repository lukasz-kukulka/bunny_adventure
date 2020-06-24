#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Slider_score
{
public:
	Slider_score(sf::RenderWindow& window, sf::RectangleShape &base, sf::Texture* up_texture, sf::Texture* mid_texture, sf::Texture* down_texture, 
		sf::Texture* up_texture_press, sf::Texture* mid_texture_press, sf::Texture* down_texture_press, bool enable_slider);

	int system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_ini(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture* up_tex,* mid_tex,* down_tex, * up_tex_press, * mid_tex_press, * down_tex_press;
	sf::Sprite slider_up, slider_mid, slider_down;
	sf::RectangleShape rec_base, slider_shape;
	sf::Event event;
	bool slider_on_off;
	int return_index;
};


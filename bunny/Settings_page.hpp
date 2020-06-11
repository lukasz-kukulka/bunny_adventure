#pragma once
#include <SFML/Graphics.hpp>
#include "Option.hpp"
#include "Section.hpp"
#include "Button_option.hpp"
#include "Slider_option.hpp"

class Settings_page :public Option
{
public:
	Settings_page(sf::RenderWindow&);

	int system(sf::RenderWindow&, sf::Vector2i);
	void draw(sf::RenderWindow&);

private:
	sf::Texture background, button_color, button_grey, slider_base, slider_black, slider_volume;
	sf::Sprite background_sprite;
	sf::RectangleShape basic;
	sf::Font sec_font, button_font;

	std::vector<Section>sections;
	std::vector<Button_option>buttons_resolution;
	std::vector<Button_option>buttons_diff;
	std::vector<Slider_option>sliders_sound;
	int settings_sections_no, settings_resolution, settings_sound, settings_dificult, settings_control, settings_summary;
};


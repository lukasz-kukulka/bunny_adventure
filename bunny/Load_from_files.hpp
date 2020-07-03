#pragma once
#pragma once
#include <SFML/Graphics.hpp>

class Load_from_files
{
public:
	Load_from_files(sf::RenderWindow& window);


protected:
	sf::Texture background_tex, trash_tex, down_slider, mid_slider, up_slider, back_button_tex, back_button_grey_tex, down_slider_grey, mid_slider_grey, up_slider_grey,
		down_slider_press, mid_slider_press, up_slider_press, button_color, button_grey, slider_base, slider_black, slider_volume, yes_color, yes_grey, cursor_section, 
		save_exit_button, save_exit_button_grey, cat_tex, menu_button_left, menu_button_mid, menu_button_right, arrow_left, arrow_right, jaguar, cloud, forest, leaf, background_base;

};
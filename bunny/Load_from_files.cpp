#include "Load_from_files.hpp"

Load_from_files::Load_from_files(sf::RenderWindow& window)
{
	this->background_tex.loadFromFile("Textures/Credits/back.jpg");
	this->trash_tex.loadFromFile("Textures/Score/trash.png");
	this->down_slider.loadFromFile("Textures/Score/down.png");
	this->up_slider.loadFromFile("Textures/Score/up.png");
	this->mid_slider.loadFromFile("Textures/Score/slider.png");
	this->down_slider_press.loadFromFile("Textures/Score/down_press.png");
	this->up_slider_press.loadFromFile("Textures/Score/up_press.png");
	this->mid_slider_press.loadFromFile("Textures/Score/slider_press.png");
	this->down_slider_grey.loadFromFile("Textures/Score/down_grey.png");
	this->up_slider_grey.loadFromFile("Textures/Score/up_grey.png");
	this->mid_slider_grey.loadFromFile("Textures/Score/slider_grey.png");
	this->back_button_tex.loadFromFile("Textures/Settings/control.png");
	this->back_button_grey_tex.loadFromFile("Textures/Settings/control_grey.png");
	this->button_color.loadFromFile("Textures/Settings/button_color.png");
	this->button_grey.loadFromFile("Textures/Settings/button_grey.png");
	this->cursor_section.loadFromFile("Textures/Settings/id_rec.png");
	this->save_exit_button.loadFromFile("Textures/Settings/control.png");
	this->save_exit_button_grey.loadFromFile("Textures/Settings/control_grey.png");
	this->slider_base.loadFromFile("Textures/Settings/slider.png");
	this->slider_black.loadFromFile("Textures/Settings/slider_black.png");
	this->slider_volume.loadFromFile("Textures/Settings/slider_bunny1.png");
	this->yes_color.loadFromFile("Textures/Settings/yes.png");
	this->yes_grey.loadFromFile("Textures/Settings/yes_grey.png");
	this->cat_tex.loadFromFile("Textures/Credits/cat.png");
	this->leaf.loadFromFile("Textures/Menu/leaf.png");
	this->menu_button_left.loadFromFile("Textures/Menu/left_button_blue.png");
	this->menu_button_mid.loadFromFile("Textures/Menu/mid_button_blue.png");
	this->menu_button_right.loadFromFile("Textures/Menu/right_button_blue.png");
	this->jaguar.loadFromFile("Textures/Menu/Jaguar.png");
	this->cloud.loadFromFile("Textures/Menu/cloud.png");
	this->forest.loadFromFile("Textures/Menu/forest1.png");
	this->arrow_left.loadFromFile("Textures/Menu/arrow_left.png");
	this->arrow_right.loadFromFile("Textures/Menu/arrow_right.png");
	this->background_base.loadFromFile("Textures/Menu/background1.jpg");
}
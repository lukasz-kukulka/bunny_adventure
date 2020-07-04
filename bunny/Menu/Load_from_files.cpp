#include "Load_from_files.hpp"

Load_from_files::Load_from_files(sf::RenderWindow& window)
{
	this->background_tex.loadFromFile("Menu/Textures/Credits/back.jpg");
	this->trash_tex.loadFromFile("Menu/Textures/Score/trash.png");
	this->down_slider.loadFromFile("Menu/Textures/Score/down.png");
	this->up_slider.loadFromFile("Menu/Textures/Score/up.png");
	this->mid_slider.loadFromFile("Menu/Textures/Score/slider.png");
	this->down_slider_press.loadFromFile("Menu/Textures/Score/down_press.png");
	this->up_slider_press.loadFromFile("Menu/Textures/Score/up_press.png");
	this->mid_slider_press.loadFromFile("Menu/Textures/Score/slider_press.png");
	this->down_slider_grey.loadFromFile("Menu/Textures/Score/down_grey.png");
	this->up_slider_grey.loadFromFile("Menu/Textures/Score/up_grey.png");
	this->mid_slider_grey.loadFromFile("Menu/Textures/Score/slider_grey.png");
	this->back_button_tex.loadFromFile("Menu/Textures/Settings/control.png");
	this->back_button_grey_tex.loadFromFile("Menu/Textures/Settings/control_grey.png");
	this->button_color.loadFromFile("Menu/Textures/Settings/button_color.png");
	this->button_grey.loadFromFile("Menu/Textures/Settings/button_grey.png");
	this->cursor_section.loadFromFile("Menu/Textures/Settings/id_rec.png");
	this->save_exit_button.loadFromFile("Menu/Textures/Settings/control.png");
	this->save_exit_button_grey.loadFromFile("Menu/Textures/Settings/control_grey.png");
	this->slider_base.loadFromFile("Menu/Textures/Settings/slider.png");
	this->slider_black.loadFromFile("Menu/Textures/Settings/slider_black.png");
	this->slider_volume.loadFromFile("Menu/Textures/Settings/slider_bunny1.png");
	this->yes_color.loadFromFile("Menu/Textures/Settings/yes.png");
	this->yes_grey.loadFromFile("Menu/Textures/Settings/yes_grey.png");
	this->cat_tex.loadFromFile("Menu/Textures/Credits/cat.png");
	this->leaf.loadFromFile("Menu/Textures/Menu/leaf.png");
	this->menu_button_left.loadFromFile("Menu/Textures/Menu/left_button_blue.png");
	this->menu_button_mid.loadFromFile("Menu/Textures/Menu/mid_button_blue.png");
	this->menu_button_right.loadFromFile("Menu/Textures/Menu/right_button_blue.png");
	this->jaguar.loadFromFile("Menu/Textures/Menu/Jaguar.png");
	this->cloud.loadFromFile("Menu/Textures/Menu/cloud.png");
	this->forest.loadFromFile("Menu/Textures/Menu/forest1.png");
	this->arrow_left.loadFromFile("Menu/Textures/Menu/arrow_left.png");
	this->arrow_right.loadFromFile("Menu/Textures/Menu/arrow_right.png");
	this->background_base.loadFromFile("Menu/Textures/Menu/background1.jpg");

	this->buffer_menu.loadFromFile("Menu/Sound/Menu/click.wav");
	this->click_sound.setBuffer(buffer_menu);
	this->click_sound.setVolume(15.f);
	this->buffer_menu_choise.loadFromFile("Menu/Sound/Menu/choise.wav");
	this->choise_sound.setBuffer(buffer_menu_choise);
	this->choise_sound.setVolume(15.f);
	this->delete_buffer.loadFromFile("Menu/Sound/Menu/save_file.wav");
	this->delete_sound.setBuffer(delete_buffer);
	this->delete_sound.setVolume(15.f);
	this->button_buffer.loadFromFile("Menu/Sound/Menu/options_button.wav"); 
	this->button_sound.setBuffer(button_buffer);
	this->button_sound.setVolume(15.f);
	this->slider_buffer.loadFromFile("Menu/Sound/Menu/slider.wav");
	this->slider_sound.setBuffer(slider_buffer);
	this->slider_sound.setVolume(15.f);

	this->font_menu_button.loadFromFile("Menu/Fonts/avocado.ttf");
	this->button_confirm_font.loadFromFile("Menu/Fonts/bongus.ttf");
	this->cat_font.loadFromFile("Menu/Fonts/flut.ttf");
	this->good_mor.loadFromFile("Menu/Fonts/good_mor.ttf");
	this->butler.loadFromFile("Menu/Fonts/butler.ttf");
	this->sec_font.loadFromFile("Menu/Fonts/beachday.ttf");
	this->game_font.loadFromFile("Menu/Fonts/game.ttf");
	this->kids_font.loadFromFile("Menu/Fonts/kids.ttf");
}

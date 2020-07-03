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

	this->buffer_menu.loadFromFile("Sound/Menu/click.wav");
	this->click_sound.setBuffer(buffer_menu);
	this->click_sound.setVolume(15.f);
	this->buffer_menu_choise.loadFromFile("Sound/Menu/choise.wav");
	this->choise_sound.setBuffer(buffer_menu_choise);
	this->choise_sound.setVolume(15.f);
	this->delete_buffer.loadFromFile("Sound/Menu/save_file.wav");
	this->delete_sound.setBuffer(delete_buffer);
	this->delete_sound.setVolume(15.f);
	this->button_buffer.loadFromFile("Sound/Menu/options_button.wav"); 
	this->button_sound.setBuffer(button_buffer);
	this->button_sound.setVolume(15.f);
	this->slider_buffer.loadFromFile("Sound/Menu/slider.wav");
	this->slider_sound.setBuffer(slider_buffer);
	this->slider_sound.setVolume(15.f);




	this->font_menu_button.loadFromFile("Fonts/avocado.ttf");
	this->button_confirm_font.loadFromFile("Fonts/bongus.ttf");
	this->cat_font.loadFromFile("Fonts/flut.ttf");
	this->good_mor.loadFromFile("Fonts/good_mor.ttf");
	this->butler.loadFromFile("Fonts/butler.ttf");
	this->sec_font.loadFromFile("Fonts/beachday.ttf");
	this->game_font.loadFromFile("Fonts/game.ttf");
	this->kids_font.loadFromFile("Fonts/kids.ttf");
}

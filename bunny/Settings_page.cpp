#include "Settings_page.hpp"

Settings_page::Settings_page(sf::RenderWindow& window)
{
	this->settings_sections_no = 5;
	this->settings_resolution = 3;
	this->settings_sound = 3;
	this->settings_dificult = 3;
	this->settings_control = 3;
	this->settings_summary = 2;
	this->max_row_control = 3;
	this->background.loadFromFile("Textures/Credits/back.jpg");
	this->background_sprite.setTexture(background);
	this->basic.setSize(sf::Vector2f(window.getSize().x - 50, window.getSize().y - 50));
	this->basic.setPosition(window.getSize().x / 2 - basic.getGlobalBounds().width / 2, window.getSize().y / 2 - basic.getGlobalBounds().height / 2);
	this->basic.setFillColor(sf::Color(255, 255, 255, 0));

	this->button_font.loadFromFile("Fonts/flut.ttf");
	this->sec_font.loadFromFile("Fonts/beachday.ttf");
	this->game_font.loadFromFile("Fonts/game.ttf");
	this->kids_font.loadFromFile("Fonts/kids.ttf"); 

	this->button_color.loadFromFile("Textures/Settings/button_color.png");
	this->button_grey.loadFromFile("Textures/Settings/button_grey.png");

	this->slider_base.loadFromFile("Textures/Settings/slider.png");
	this->slider_black.loadFromFile("Textures/Settings/slider_black.png");
	this->slider_volume.loadFromFile("Textures/Settings/slider_bunny1.png");

	this->yes_color.loadFromFile("Textures/Settings/yes.png");
	this->yes_grey.loadFromFile("Textures/Settings/yes_grey.png");


	this->sections.push_back(Section(window, sections.size(), "RESOLUTION", settings_sections_no, basic, &sec_font));
	this->buttons_resolution.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "1280 X 1024", settings_resolution, buttons_resolution.size()));
	this->buttons_resolution.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "1600 X 900", settings_resolution, buttons_resolution.size()));
	this->buttons_resolution.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "1920 X 1080", settings_resolution, buttons_resolution.size()));

	this->sections.push_back(Section(window, sections.size(), "SOUND", settings_sections_no, basic, &sec_font));
	this->sliders_sound.push_back(Slider_option(window, sections[sections.size() - 1].shape(), &slider_base, &slider_black, &slider_volume, &sec_font, settings_sound, 0, "Volume"));
	this->yes_no_buttons.push_back(Yes_no_option(window, sections[sections.size() - 1].shape(), &yes_color, &yes_grey, &sec_font, settings_sound, 1, "EFECTS"));
	this->yes_no_buttons.push_back(Yes_no_option(window, sections[sections.size() - 1].shape(), &yes_color, &yes_grey, &sec_font, settings_sound, 2, "MUSIC"));

	this->sections.push_back(Section(window, sections.size(), "DIFFICULTY", settings_sections_no, basic, &sec_font));
	this->buttons_diff.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "EASY", settings_resolution, buttons_diff.size()));
	this->buttons_diff.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "NORMAL", settings_resolution, buttons_diff.size()));
	this->buttons_diff.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "HARD", settings_resolution, buttons_diff.size()));

	this->sections.push_back(Section(window, sections.size(), "CONTROL", settings_sections_no, basic, &sec_font));
	//RenderWindow& window, sf::RectangleShape work_space, sf::Font* font, std::string text_control, int max_x, int max_y, int index_x, int index_y);
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "space - jump", settings_control, max_row_control, 1, 1));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control, max_row_control, 1, 2));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control, max_row_control, 1, 3));

	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control, max_row_control, 2, 1));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control, max_row_control, 2, 2));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control, max_row_control, 2, 3));

	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control, max_row_control, 3, 1));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control, max_row_control, 3, 2));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control, max_row_control, 3, 3));

	this->sections.push_back(Section(window, sections.size(), "", settings_sections_no, basic, &sec_font));


}

int Settings_page::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	for (int i = 0; i < sections.size(); i++)
	{
		sections[i].system(window, mouse);
	}
	for (int i = 0; i < buttons_resolution.size(); i++)
	{
		buttons_resolution[i].system(window, mouse);
	}
	for (int i = 0; i < buttons_diff.size(); i++)
	{
		buttons_diff[i].system(window, mouse);
	}
	for (int i = 0; i < sliders_sound.size(); i++)
	{
		sliders_sound[i].system(window, mouse);
	}
	for (int i = 0; i < yes_no_buttons.size(); i++)
	{
		yes_no_buttons[i].system(window, mouse);
	}

	return 3;
}

void Settings_page::draw(sf::RenderWindow& window)
{
	window.draw(background_sprite);
	window.draw(basic);
	for (int i = 0; i < sections.size(); i++)
	{
		sections[i].draw(window);
	}
	for (int i = 0; i < buttons_resolution.size(); i++)
	{
		buttons_resolution[i].draw(window);
	}
	for (int i = 0; i < buttons_diff.size(); i++)
	{
		buttons_diff[i].draw(window);
	}
	for (int i = 0; i < sliders_sound.size(); i++)
	{
		sliders_sound[i].draw(window);
	}
	for (int i = 0; i < yes_no_buttons.size(); i++)
	{
		yes_no_buttons[i].draw(window);
	}
	for (int i = 0; i < text_control.size(); i++)
	{
		text_control[i].draw(window);
	}
}

#include "Settings_page.hpp"

Settings_page::Settings_page(sf::RenderWindow& window)
{
	this->settings_sections_no = 5;
	this->settings_resolution = 3;
	this->settings_sound = 3;
	this->settings_dificult = 3;
	this->settings_control = 3;
	this->settings_summary = 2;
	this->background.loadFromFile("Textures/Credits/back.jpg");
	this->background_sprite.setTexture(background);
	this->basic.setSize(sf::Vector2f(window.getSize().x - 50, window.getSize().y - 50));
	this->basic.setPosition(window.getSize().x / 2 - basic.getGlobalBounds().width / 2, window.getSize().y / 2 - basic.getGlobalBounds().height / 2);
	this->basic.setFillColor(sf::Color(255, 255, 255, 0));

	this->button_font.loadFromFile("Fonts/flut.ttf");
	this->sec_font.loadFromFile("Fonts/beachday.ttf");

	this->button_color.loadFromFile("Textures/Settings/button_color.png");
	this->button_grey.loadFromFile("Textures/Settings/button_grey.png");

	this->slider_base.loadFromFile("Textures/Settings/slider.png");
	this->slider_black.loadFromFile("Textures/Settings/slider_black.png");
	this->slider_volume.loadFromFile("Textures/Settings/slider_bunny1.png");


	this->sections.push_back(Section(window, sections.size(), "RESOLUTION", settings_sections_no, basic, &sec_font));
	//Button_option::Button_option(sf::RenderWindow & window, sf::RectangleShape work_space sf::Texture * texture, sf::Font * font, std::string text_button, int how_many, int index)
	this->buttons_resolution.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "1280 X 1024", settings_resolution, buttons_resolution.size()));
	this->buttons_resolution.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "1600 X 900", settings_resolution, buttons_resolution.size()));
	this->buttons_resolution.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "1920 X 1080", settings_resolution, buttons_resolution.size()));

	this->sections.push_back(Section(window, sections.size(), "SOUND", settings_sections_no, basic, &sec_font));
	//Slider_option(sf::RenderWindow & window, sf::RectangleShape work_space, sf::Texture * slider, sf::Texture * slider_black_tex, sf::Texture * slider_bunny, sf::Font * font, int volume, int index);
	this->sliders_sound.push_back(Slider_option(window, sections[sections.size() - 1].shape(), &slider_base, &slider_black, &slider_volume, &sec_font, settings_sound, 0, "Volume"));

	this->sections.push_back(Section(window, sections.size(), "DIFFICULTY", settings_sections_no, basic, &sec_font));
	this->buttons_diff.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "EASY", settings_resolution, buttons_diff.size()));
	this->buttons_diff.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "NORMAL", settings_resolution, buttons_diff.size()));
	this->buttons_diff.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "HARD", settings_resolution, buttons_diff.size()));

	this->sections.push_back(Section(window, sections.size(), "CONTROL", settings_sections_no, basic, &sec_font));


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
}

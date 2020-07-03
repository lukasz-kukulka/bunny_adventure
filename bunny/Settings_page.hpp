#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Option.hpp"
#include "Section.hpp"
#include "Button_option.hpp"
#include "Slider_option.hpp"
#include "Yes_no_option.hpp"
#include "Text_settings.hpp"
#include "Files_operations.hpp"
#include "Text.hpp"
#include "Files_operations.hpp"
#include "Load_from_files.hpp"

class Settings_page :public Option, public Load_from_files
{
public:
	Settings_page(sf::RenderWindow&);

	int system(sf::RenderWindow& window, sf::Vector2i mouse);
	void load_settings();
	void settings_ini_button();
	void objects_ini(sf::RenderWindow& window);
	int resolution_load_width();
	int resolution_load_height();
	void settings(int volume);
	void draw(sf::RenderWindow& window);
	~Settings_page();

private:
	sf::Sprite background_sprite_settings;
	sf::RectangleShape basic;
	sf::RectangleShape save_back_rec;
	sf::Font sec_font, button_font, game_font, kids_font;
	sf::Time time_save, time_save_begin;
	sf::Clock clock_save;
	sf::SoundBuffer button_buffer, slider_buffer, save_buffer, buffer_choise;
	sf::Sound button_sound, slider_sound, save_sound, sound_choise;
	std::vector<Section>sections;
	std::vector<Button_option>buttons_resolution;
	std::vector<Button_option>buttons_diff;
	std::vector<Slider_option>sliders_sound;
	std::vector<Yes_no_option>yes_no_buttons;
	std::vector<Text_settings>text_control;
	std::vector<Button_option>buttons_save_back;
	std::vector<Text>texts;
	int settings_sections_no, settings_resolution, settings_sound, settings_dificult, settings_control_columns, settings_summary, max_row_control, settings_sound_save, press_save_back;
	bool save_button_press, play_click[3] = { 1, 1, 1 };
	Files_operations* settings_ini = new Files_operations();
	
	struct settings {
		int res;
		int vol;
		bool efect;
		bool music;
		int dif;
	} settings_deffault, user_settings, temp_settings;
	
	struct sections_settings {
		bool one;
		bool two;
		bool three;
	} res_settings, diff_settings;

};


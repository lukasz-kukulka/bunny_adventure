#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp> // ??
#include <SFML/Window.hpp> //??
#include "Option.hpp"
#include "Single_score_record.hpp"
#include "Slider_score.hpp"
#include "Button_option.hpp"
#include "Files_operations.hpp"
#include <stdio.h> // do usuniecia 
#include "Confirm_screen.hpp"
#include "Files_operations.hpp"

class Score_page :public Option
{
public:
	Score_page(sf::RenderWindow& window);
	int system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_ini(sf::RenderWindow& window);
	void settings(int volume);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture trash_tex, background_tex, down_slider, mid_slider, up_slider, back_button_tex, back_button_grey_tex, down_slider_grey, mid_slider_grey, up_slider_grey, 
		down_slider_press, mid_slider_press, up_slider_press;
	sf::Sprite background_sprite_bunny;
	sf::Font butler, button_font;
	sf::RectangleShape base_rec, size_no_extra_records;
	sf::Clock move_record_clock;
	sf::Time move_record_time;
	sf::SoundBuffer button_buffer, delete_buffer;
	sf::Sound button_sound, delete_sound;
	std::vector<Single_score_record>score_records;
	std::vector<Slider_score>slider;
	std::vector<Button_option>back_button;
	std::vector<Confirm_screen>screen_del;
	Files_operations score_operations;
	sf::Event event;
	int no_single_score, how_many_record_before, extra_record_number, unit_mid_slider, slider_mid_position, slider_mid_position_checked, score_to_delete, slider_index;
	bool detete_record_enagled, screen_delete_enabled;
};


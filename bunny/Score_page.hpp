#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> // ??
#include <SFML/Window.hpp> //??
#include "Option.hpp"
#include "Single_score_record.hpp"
#include "Slider_score.hpp"
#include "Button_option.hpp"
#include "Files_operations.hpp"
#include <stdio.h> // do usuniecia 

class Score_page :public Option
{
public:
	Score_page(sf::RenderWindow& window);
	int system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_ini(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture trash_tex, background_tex, down_slider, mid_slider, up_slider, back_button_tex, back_button_grey_tex, down_slider_grey, mid_slider_grey, up_slider_grey, 
		down_slider_press, mid_slider_press, up_slider_press;
	sf::Sprite background_sprite_bunny;
	sf::Font butler, button_font;
	sf::RectangleShape base_rec;
	std::vector<Single_score_record>score_records;
	std::vector<Slider_score>slider;
	std::vector<Button_option>back_button;
	Files_operations score_operations;
	int no_single_score;
};


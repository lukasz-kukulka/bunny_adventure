#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Option.hpp"
#include "Single_score_record.hpp"
#include "Slider_score.hpp"
#include "Button_option.hpp"

class Score_page :public Option
{
public:
	Score_page(sf::RenderWindow& window);
	int system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_ini(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture background_tex, down_slider, mid_slider, up_slider, back_button_tex, back_button_grey_tex;
	sf::Sprite background_sprite_bunny;
	sf::Texture trash_tex;
	sf::Font butler, button_font;
	sf::RectangleShape base_rec;
	std::vector<Single_score_record>score_records;
	std::vector<Slider_score>slider;
	std::vector<Button_option>back_button;
};


#include "Score_page.hpp"

Score_page::Score_page(sf::RenderWindow& window)
{
	this->no_single_score = score_operations.how_many_record_score();
	this->base_rec.setSize(sf::Vector2f(window.getSize().x - 154, window.getSize().y - 300));
	this->base_rec.setPosition(52, 50);
	this->base_rec.setFillColor(sf::Color(255, 255, 255, 55));

	this->background_tex.loadFromFile("Textures/Credits/back.jpg");
	this->trash_tex.loadFromFile("Textures/Score/trash.png");
	this->down_slider.loadFromFile("Textures/Score/down.png");
	this->up_slider.loadFromFile("Textures/Score/up.png");
	this->mid_slider.loadFromFile("Textures/Score/slider.png");
	this->back_button_tex.loadFromFile("Textures/Settings/control.png");
	this->back_button_grey_tex.loadFromFile("Textures/Settings/control_grey.png");

	this->button_font.loadFromFile("Fonts/flut.ttf");

	this->background_sprite_bunny.setTexture(background_tex);

	this->butler.loadFromFile("Fonts/butler.ttf");
	this->objects_ini(window);
	
}

int Score_page::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	for (int i = 0; i < back_button.size(); i++)
	{
		if (back_button[i].system(window, mouse) == 56)
			return 0;
	}
	return 2;
}

void Score_page::objects_ini(sf::RenderWindow& window)
{
	this->slider.push_back(Slider_score(window, base_rec, &up_slider, &mid_slider, &down_slider));
	for (int i = 0; i < 15; i++)
	{
		std::cout << i <<"\n";
		this->score_records.push_back(Single_score_record(window, &trash_tex, &butler, base_rec, score_records.size()));
	}
	this->back_button.push_back(Button_option(window, base_rec, &back_button_tex, &back_button_grey_tex, &button_font, "EXIT", 1, 55, false));
}

void Score_page::draw(sf::RenderWindow& window)
{
	window.draw(background_sprite_bunny);
	window.draw(base_rec);
	for (int i = 0; i < score_records.size(); i++)
	{
		score_records[i].draw(window);
	}
	for (int i = 0; i < slider.size(); i++)
	{
		slider[i].draw(window);
	}
	for (int i = 0; i < back_button.size(); i++)
	{
		back_button[i].draw(window);
	}
}

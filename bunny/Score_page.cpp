#include "Score_page.hpp"

Score_page::Score_page(sf::RenderWindow& window)
{
	this->base_rec.setSize(sf::Vector2f(window.getSize().x - 154, window.getSize().y - 300));
	this->base_rec.setPosition(52, 50);
	this->base_rec.setFillColor(sf::Color(255, 255, 255, 0));
	this->base_rec.setOutlineThickness(0);
	this->base_rec.setOutlineColor(sf::Color(0, 0, 0, 111));

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
	this->button_font.loadFromFile("Fonts/flut.ttf");
	this->butler.loadFromFile("Fonts/butler.ttf");
	this->objects_ini(window);
	
}

int Score_page::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	move_record_time = move_record_clock.getElapsedTime();
	for (int i = 0; i < back_button.size(); i++)
	{
		if (back_button[i].system(window, mouse) == 56)
			return 0;
	}
	for (int i = 0; i < slider.size(); i++)
	{
		
		if (slider[i].system(window, mouse) == 2 && score_records[0].visible_status() != true && move_record_time.asMilliseconds() >= 100) // down
		{
			for (int j = score_records.size() - 1; j >= 0 ; j--)
			{
				//std::cout<< j << " --------------------- CZY JEST TRUE\n";
				score_records[j].move_down(window);
				move_record_clock.restart();
			}
			//std::cout << "KONIEC\n";
		}
		else if (slider[i].system(window, mouse) == 1 && score_records[score_records.size() - 1].visible_status() != true && move_record_time.asMilliseconds() >= 100) // up
		{
			for (int j = 0; j < score_records.size(); j++)
			{
				score_records[j].move_up(window);
				move_record_clock.restart();
			}	
		}
		else if (slider[i].system(window, mouse) == 3) // mid
		{
			std::cout << "TEST" << std::endl;
		}
		else
		{

		}
	}
	
	for (int i = 0; i < score_records.size(); i++)
	{
		score_records[i].system(window, mouse);
	}
	return 2;
}

void Score_page::objects_ini(sf::RenderWindow& window)
{
	this->no_single_score = score_operations.how_many_record_score();
	this->background_sprite_bunny.setTexture(background_tex);
	
	if (no_single_score < 15)
	{
		this->slider.push_back(Slider_score(window, base_rec, &up_slider_grey, &mid_slider_grey, &down_slider_grey, &up_slider_press, &mid_slider_press, &down_slider_press, false));
	}
	else
	{
		this->slider.push_back(Slider_score(window, base_rec, &up_slider, &mid_slider, &down_slider, &up_slider_press, &mid_slider_press, &down_slider_press, true));
	}

	for (int i = 0; i < no_single_score; i++)
	{
		if(score_records.size() < 15)
			this->score_records.push_back(Single_score_record(window, &trash_tex, &butler, base_rec, score_records.size(), score_operations.load_score(i * 3 + 1), 
				score_operations.load_score(i * 3 + 2), score_operations.load_score(i * 3 + 3), true));
		else 
			this->score_records.push_back(Single_score_record(window, &trash_tex, &butler, base_rec, score_records.size(), score_operations.load_score(i * 3 + 1),
				score_operations.load_score(i * 3 + 2), score_operations.load_score(i * 3 + 3), false));
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

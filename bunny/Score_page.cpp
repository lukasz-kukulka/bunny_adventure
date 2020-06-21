#include "Score_page.hpp"

Score_page::Score_page(sf::RenderWindow& window)
{
	this->base_rec.setSize(sf::Vector2f(window.getSize().x - 150, window.getSize().y - 300));
	this->base_rec.setPosition(50, 50);
	this->base_rec.setFillColor(sf::Color(255, 255, 255, 55));

	this->background_tex.loadFromFile("Textures/Credits/back.jpg");
	this->trash_tex.loadFromFile("Textures/Score/trash.png");
	this->down_slider.loadFromFile("Textures/Score/down.png");
	this->up_slider.loadFromFile("Textures/Score/up.png");
	this->mid_slider.loadFromFile("Textures/Score/slider.png");

	this->background_sprite_bunny.setTexture(background_tex);

	this->butler.loadFromFile("Fonts/butler.ttf");
	this->objects_ini(window);
	
}

int Score_page::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	return 2;
}

void Score_page::objects_ini(sf::RenderWindow& window)
{

	
}

void Score_page::draw(sf::RenderWindow& window)
{
	window.draw(background_sprite_bunny);
	window.draw(base_rec);
	for (int i = 0; i < score_records.size(); i++)
	{
		score_records[i].draw(window);
	}
}

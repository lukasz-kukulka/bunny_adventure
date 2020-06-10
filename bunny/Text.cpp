#include "Text.hpp"

Text::Text(sf::RenderWindow& window, sf::Font* font, std::string text, int pos_x, int pos_y, int text_size, int type_sub, int index_objects)
{
	this->type_sub = type_sub;
	this->iterator = 0;
	this->text_size = text_size;
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->single_font = *font;
	this->temp_text = text;
	this->text.setFont(*font);
	//this->text.setString(text);
	this->text.setCharacterSize(text_size);
	this->text.setFillColor(sf::Color(255, 117, 111, 255));
	this->text.setOutlineThickness(2);
	this->text.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->text.setPosition(0,0);
	this->text.setOrigin(0, 0);
	if (type_sub == 2)
		this->pos_x = window.getSize().x / 2 - (temp_text.size() / 2 * text_size * 1.3);
	else if (type_sub == 1)
		this->pos_x = window.getSize().x / 2 - (temp_text.size() / 2 * text_size * 1.7);
}

void Text::create_single(sf::RenderWindow& window)
{
	if (singles.size() < temp_text.size())
	{
		singles.push_back(Single_text(window, &single_font, temp_text.substr(iterator, 1), pos_x, pos_y, iterator, text_size, type_sub));
		iterator++;
	}
}

void Text::reset()
{
	singles.erase(singles.begin(), singles.end());
	iterator = 0;
}



void Text::draw(sf::RenderWindow& window)
{
	window.draw(text);
	for (int i = 0; i < singles.size(); i++)
	{
		singles[i].draw(window);
	}

}

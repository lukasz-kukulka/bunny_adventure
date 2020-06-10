#include "Credits.hpp"

Credits::Credits(sf::RenderWindow& window)
{
	this->background_tex.loadFromFile("Textures/Credits/back.jpg");
	this->background_sprite.setTexture(background_tex);
	//this->background_sprite.setColor(sf::Color(188,188,188,188));

	this->cat_tex.loadFromFile("Textures/Credits/cat.png");
	this->leaf.loadFromFile("Textures/Menu/leaf.png");

	this->cat_font.loadFromFile("Fonts/flut.ttf");
	this->good_mor.loadFromFile("Fonts/good_mor.ttf");
	this->font_button.loadFromFile("Fonts/bongus.ttf");

	this->texts.push_back(Text(window, &good_mor, " - SCENARY - ", 0, window.getSize().y / 70 * 2, window.getSize().y / 30, 2, texts.size()));
	this->texts.push_back(Text(window, &cat_font, "LUKASZ KUKULKA", 0, window.getSize().y / 70 * 7, window.getSize().y / 70, 1, texts.size()));

	this->texts.push_back(Text(window, &good_mor, " - CODE - ", 0, window.getSize().y / 70 * 12, window.getSize().y / 30, 2, texts.size()));
	this->texts.push_back(Text(window, &cat_font, "LUKASZ KUKULKA", 0, window.getSize().y / 70 * 17, window.getSize().y / 70, 1, texts.size()));

	this->texts.push_back(Text(window, &good_mor, " - ANIMATION - ", 0, window.getSize().y / 70 * 22, window.getSize().y / 30, 2, texts.size()));
	this->texts.push_back(Text(window, &cat_font, "LUKASZ KUKULKA", 0, window.getSize().y / 70 * 27, window.getSize().y / 70, 1, texts.size()));

	this->texts.push_back(Text(window, &good_mor, " - TEXTURE - ", 0, window.getSize().y / 70 * 32, window.getSize().y / 30, 2, texts.size()));
	this->texts.push_back(Text(window, &cat_font, "OPENGAMEART.ORG AND PIXABAY.COM", 0, window.getSize().y / 70 * 37, window.getSize().y / 70, 1, texts.size()));

	this->texts.push_back(Text(window, &good_mor, " - DEDICATE - ", 0, window.getSize().y / 70 * 42, window.getSize().y / 30, 2, texts.size()));
	this->texts.push_back(Text(window, &cat_font, "THIS GAME IS DEDICATED TO MY BELOVED BELLA, ", 0, window.getSize().y / 70 * 47, window.getSize().y / 70, 1, texts.size()));
	this->texts.push_back(Text(window, &cat_font, "THANK YOU FOR SUPPORT AND BELIEVE ON ME", 0, window.getSize().y / 70 * 50, window.getSize().y / 70, 1, texts.size()));

	this->texts.push_back(Text(window, &good_mor, " -= THANKS =- ", 0, window.getSize().y / 70 * 57, window.getSize().y / 30, 2, texts.size()));
	this->texts.push_back(Text(window, &cat_font, "THANKS FOR SUPORT TO MY FRIENDS:", 0, window.getSize().y / 70 * 62, window.getSize().y / 70, 1, texts.size()));
	this->texts.push_back(Text(window, &cat_font, "MEDART, GOTRAN, ANIOL, VIX", 0, window.getSize().y / 70 * 65, window.getSize().y / 70, 1, texts.size()));


	buttons.push_back(Button(window, &leaf, &font_button, "BACK", 0, window.getSize().x, 300));
}

int Credits::system(sf::RenderWindow& window, sf::Vector2i mouse)
{

	for (int i = 0; i < texts.size(); i++)
	{
		texts[i].create_single(window);
	}

	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i].system(window, mouse) == 5)
		{
			for (int j = 0; j < texts.size(); j++)
			{
				texts[j].reset();
			}
			return 0;
		}
	}
	return 4;
}

void Credits::draw(sf::RenderWindow& window)
{
	window.draw(background_sprite);

	for (int i = 0; i < texts.size(); i++)
	{
		texts[i].draw(window);
	}

	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].draw(window);
	}
}

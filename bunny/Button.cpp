#include "Button.hpp"

Button::Button(sf::RenderWindow& window, sf::Texture* texture, sf::Font* font, std::string sub, int index, int pos_x, int pos_y)
{
	this->button_index = index + 1;

	this->button_sprite.setTexture(*texture);
	this->button_sprite.setScale(5.0 / 1920 * button_sprite.getGlobalBounds().width, 5.0 / 1920 * button_sprite.getGlobalBounds().width);
	this->button_sprite.setPosition(pos_x - button_sprite.getGlobalBounds().width * button_index, pos_y - button_sprite.getGlobalBounds().height);
	this->button_sprite.setColor(sf::Color(255, 255, 255, 255));
	this->button_sprite.setOrigin(0, 0);

	this->button_text.setFont(*font);
	this->button_text.setString(sub);
	this->button_text.setCharacterSize(window.getSize().y / 12);
	this->button_text.setFillColor(sf::Color(0, 255, 111, 33));
	this->button_text.setOutlineThickness(2);
	this->button_text.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->button_text.setPosition(button_sprite.getPosition().x + button_sprite.getGlobalBounds().width/2 - button_text.getGlobalBounds().width/2, 
		button_sprite.getPosition().y + button_sprite.getGlobalBounds().height / 2 - button_text.getGlobalBounds().height/2);
}

int Button::system(sf::RenderWindow& window, sf::Vector2i mouse)
{

	sf::Event event;
	if (mouse.x > button_sprite.getPosition().x && mouse.x < button_sprite.getPosition().x + button_sprite.getGlobalBounds().width &&
		mouse.y > button_sprite.getPosition().y && mouse.y < button_sprite.getPosition().y + button_sprite.getGlobalBounds().height)
	{
		this->button_sprite.setColor(sf::Color(111, 111, 111, 255));
		this->button_sprite.setRotation(5.0);
		this->button_text.setRotation(5.0);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonReleased)
			{

				if (event.mouseButton.button == sf::Mouse::Left && button_index == 1)
				{
					return 5;
				}
				if (event.mouseButton.button == sf::Mouse::Left && button_index == 2)
				{
					return 1;
				}
			}
		}

		//if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && button_index == 1)
		//{
		//	return 5;
		//}
		//else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && button_index == 2)
		//{
		//	return 1;
		//}
	}
	else
	{
		this->button_sprite.setColor(sf::Color(255, 255, 255, 255));
		this->button_sprite.setRotation(0.0);
		this->button_text.setRotation(0.0);
	}
	return 0;
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(button_sprite);
	window.draw(button_text);
}

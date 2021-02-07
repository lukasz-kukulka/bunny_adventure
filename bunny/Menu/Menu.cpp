#include <SFML/Graphics.hpp>
#include "Menu.hpp"

Menu::Menu(sf::RenderWindow& window, sf::Texture *texture_left, sf::Texture *texture_mid, sf::Texture *texture_right, sf::Texture* arrow_left, sf::Texture* arrow_right, sf::Font *font, uint8_t index, std::string sub)
{
	this->index_number = index;
	this->arrow_left = arrow_left;
	this->arrow_right = arrow_right;
	this->return_index = 0;

	this->button_sprite_left.setTexture(*texture_left);
	this->button_sprite_mid.setTexture(*texture_mid);
	this->button_sprite_right.setTexture(*texture_right);

	this->text_menu.setFont(*font);
	this->text_menu.setString(sub);
	this->text_menu.setCharacterSize(window.getSize().x / 15);
	this->text_menu.setFillColor(sf::Color(255, 117, 111, 255));
	this->text_menu.setOutlineThickness(2);
	this->text_menu.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->text_menu.setPosition(window.getSize().x / 3 - text_menu.getGlobalBounds().width / 2,
		50+ (25 * index_number) + (text_menu.getCharacterSize() * index_number));
	this->text_menu.setOrigin(0, window.getSize().x / 100);
	
	this->button_sprite_mid.setScale(1.0 / button_sprite_mid.getGlobalBounds().width * text_menu.getGlobalBounds().width, 1.0 / button_sprite_mid.getGlobalBounds().height * (text_menu.getCharacterSize()));
	this->button_sprite_left.setScale(button_sprite_mid.getScale().y, button_sprite_mid.getScale().y);
	this->button_sprite_right.setScale(button_sprite_mid.getScale().y, button_sprite_mid.getScale().y);

	this->button_sprite_mid.setPosition(text_menu.getPosition().x, text_menu.getPosition().y);
	this->button_sprite_left.setPosition(button_sprite_mid.getPosition().x - button_sprite_left.getGlobalBounds().width, button_sprite_mid.getPosition().y);
	this->button_sprite_right.setPosition(button_sprite_mid.getPosition().x + button_sprite_mid.getGlobalBounds().width, button_sprite_mid.getPosition().y);

	this->button_sprite_mid.setColor(sf::Color(255, 255, 255, 144));
	this->button_sprite_left.setColor(sf::Color(255, 255, 255, 144));
	this->button_sprite_right.setColor(sf::Color(255, 255, 255, 144));

	this->scale_mid_sprite_x = button_sprite_mid.getScale().x;
	this->scale_mid_sprite_x_mark = button_sprite_mid.getScale().x + 0.2;
}

uint8_t Menu::mark(sf::RenderWindow& window, sf::Vector2i mouse)
{
	

	if (mouse.x > button_sprite_left.getPosition().x && mouse.x < button_sprite_right.getPosition().x + button_sprite_right.getGlobalBounds().width &&
		mouse.y > button_sprite_left.getPosition().y && mouse.y < button_sprite_left.getPosition().y + button_sprite_left.getGlobalBounds().height)
	{
		this->button_sprite_mid.setScale(scale_mid_sprite_x_mark, button_sprite_mid.getScale().y);
		this->button_sprite_mid.setPosition(text_menu.getPosition().x + text_menu.getGlobalBounds().width / 2 - button_sprite_mid.getGlobalBounds().width / 2, text_menu.getPosition().y);
		this->button_sprite_left.setPosition(button_sprite_mid.getPosition().x - button_sprite_left.getGlobalBounds().width, button_sprite_mid.getPosition().y);
		this->button_sprite_right.setPosition(button_sprite_mid.getPosition().x + button_sprite_mid.getGlobalBounds().width, button_sprite_mid.getPosition().y);
		
		this->button_sprite_mid.setColor(sf::Color(255, 255, 255, 222));
		this->button_sprite_left.setColor(sf::Color(255, 255, 255, 222));
		this->button_sprite_right.setColor(sf::Color(255, 255, 255, 222));

		this->text_menu.setFillColor(sf::Color(255, 0, 0, 255));
		this->return_index = index_number + 10;
		if (arrows.size() == 0)
		{
			arrows.push_back(Arrow(arrow_right, button_sprite_right.getPosition().x + button_sprite_right.getGlobalBounds().width, button_sprite_left.getPosition().y, button_sprite_left.getScale().x, button_sprite_left.getScale().y));
			arrows.push_back(Arrow(arrow_left, button_sprite_left.getPosition().x - arrows[0].global_x(), button_sprite_left.getPosition().y, button_sprite_left.getScale().x, button_sprite_left.getScale().y));
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return_index = index_number + 1;
			return return_index;
		}
	}
	else
	{
		if (arrows.size() > 0)
		{
			arrows.erase(arrows.begin(), arrows.end());
		}
		this->button_sprite_mid.setScale(scale_mid_sprite_x, button_sprite_mid.getScale().y);
		this->button_sprite_mid.setPosition(text_menu.getPosition().x + text_menu.getGlobalBounds().width/2 - button_sprite_mid.getGlobalBounds().width/2, text_menu.getPosition().y);
		this->button_sprite_left.setPosition(button_sprite_mid.getPosition().x - button_sprite_left.getGlobalBounds().width, button_sprite_mid.getPosition().y);
		this->button_sprite_right.setPosition(button_sprite_mid.getPosition().x + button_sprite_mid.getGlobalBounds().width, button_sprite_mid.getPosition().y);

		this->button_sprite_mid.setColor(sf::Color(255, 255, 255, 144));
		this->button_sprite_left.setColor(sf::Color(255, 255, 255, 144));
		this->button_sprite_right.setColor(sf::Color(255, 255, 255, 144));

		this->text_menu.setFillColor(sf::Color(255, 117, 111, 255));
		return 0;
	}
	return return_index;
}

uint16_t Menu::begin_button_x()
{
	return button_sprite_left.getPosition().x;
}

uint16_t Menu::end_button_x()
{
	return button_sprite_right.getPosition().x + button_sprite_right.getGlobalBounds().width;
}

uint16_t Menu::begin_button_y()
{
	return button_sprite_left.getPosition().y;
}

float Menu::scale()
{
	return button_sprite_left.getScale().x;
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(button_sprite_left);
	window.draw(button_sprite_mid);
	window.draw(button_sprite_right);
	window.draw(text_menu);
	for (auto i : arrows)
		i.draw(window);
}

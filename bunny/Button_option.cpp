#include "Button_option.hpp"

Button_option::Button_option(sf::RenderWindow& window, sf::RectangleShape space_work, sf::Texture* texture_color, sf::Texture* texture_grey, sf::Font* font, std::string text_button, int how_many, int index)
{
	this->work_space = space_work;
	this->how_many = how_many;
	this->button_color = texture_color;
	this->button_grey = texture_grey;

	this->single_workspace.setSize(sf::Vector2f(work_space.getSize().x / how_many, work_space.getSize().y));
	this->single_workspace.setPosition(work_space.getPosition().x + single_workspace.getSize().x * index, work_space.getPosition().y);
	this->single_workspace.setFillColor(sf::Color(255, 255, 255, 44));
	this->single_workspace.setOutlineThickness(1);
	this->single_workspace.setOutlineColor(sf::Color(0, 0, 0, 11));

	this->button_sprite.setTexture(*texture_grey);
	this->button_sprite.setScale(single_workspace.getGlobalBounds().width / button_sprite.getGlobalBounds().width / 1.5, 
		single_workspace.getGlobalBounds().width / button_sprite.getGlobalBounds().width / 1.5);
	this->button_sprite.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width/2 - button_sprite.getGlobalBounds().width / 2, 
		single_workspace.getPosition().y + single_workspace.getGlobalBounds().height / 2 - button_sprite.getGlobalBounds().height / 2);

	this->button_text.setFont(*font);
	this->button_text.setString(text_button);
	this->button_text.setCharacterSize(button_sprite.getGlobalBounds().height / 40 * 5);
	this->button_text.setFillColor(sf::Color(255, 255, 0, 255));
	this->button_text.setOutlineThickness(1);
	this->button_text.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->button_text.setPosition(button_sprite.getPosition().x + button_sprite.getGlobalBounds().width / 2 - button_text.getGlobalBounds().width / 2,
		button_sprite.getPosition().y + button_sprite.getGlobalBounds().height / 5 * 3 - button_text.getGlobalBounds().height / 2);
}

int Button_option::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	if (mouse.x > button_sprite.getPosition().x && mouse.x < button_sprite.getPosition().x + button_sprite.getGlobalBounds().width &&
		mouse.y > button_sprite.getPosition().y && mouse.y < button_sprite.getPosition().y + button_sprite.getGlobalBounds().height)
	{
		this->button_sprite.setTexture(*button_color);
	}
	else
	{
		this->button_sprite.setTexture(*button_grey);
	}
	return 0;
}

void Button_option::draw(sf::RenderWindow& window)
{
	window.draw(single_workspace);
	window.draw(button_sprite);
	window.draw(button_text);
}

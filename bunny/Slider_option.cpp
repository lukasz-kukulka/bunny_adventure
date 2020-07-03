#include "Slider_option.hpp"

Slider_option::Slider_option(sf::RenderWindow& window, sf::RectangleShape work_space, sf::Texture* slider, sf::Texture* slider_black_tex, sf::Texture* slider_bunny, sf::Font* font, uint8_t units, uint8_t index, std::string text_title, uint8_t volume_index)
{
	this->volume_sound = volume_index;
	this->work_space = work_space;
	this->volume = units;
	this->single_workspace.setSize(sf::Vector2f(work_space.getSize().x / volume, work_space.getSize().y));
	this->single_workspace.setPosition(work_space.getPosition().x + single_workspace.getSize().x * index, work_space.getPosition().y);
	this->single_workspace.setFillColor(sf::Color(255, 255, 255, 0));
	this->single_workspace.setOutlineThickness(1);
	this->single_workspace.setOutlineColor(sf::Color(0, 0, 0, 0));

	this->slider_all.setTexture(*slider);
	this->slider_all.setScale(single_workspace.getGlobalBounds().width * 0.8 / slider_all.getGlobalBounds().width,
		single_workspace.getGlobalBounds().width * 0.8 / slider_all.getGlobalBounds().width);
	this->slider_all.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 2 - slider_all.getGlobalBounds().width / 2,
		single_workspace.getPosition().y + single_workspace.getGlobalBounds().height / 2 - slider_all.getGlobalBounds().height / 2);
	this->slider_all.setColor(sf::Color(55, 177, 255, 255));

	this->slider_black.setTexture(*slider_black_tex);
	this->slider_black.setScale(slider_all.getScale().x, slider_all.getScale().y);
	this->slider_black.setPosition(slider_all.getPosition().x + slider_all.getGlobalBounds().width / 2 - slider_black.getGlobalBounds().width / 2,
		slider_all.getPosition().y);

	this->slider_hand.setTexture(*slider_bunny);
	this->slider_hand.setScale(slider_all.getScale().x, slider_all.getScale().y);
	this->slider_hand.setPosition(slider_black.getPosition().x - slider_hand.getGlobalBounds().width / 2 + slider_black.getPosition().x / 100 * volume_sound,
		slider_black.getPosition().y + slider_black.getGlobalBounds().height / 3 - slider_hand.getGlobalBounds().height / 2);

	this->title.setFont(*font);
	this->title.setString(text_title);
	this->title.setCharacterSize(single_workspace.getGlobalBounds().height / 4);
	this->title.setFillColor(sf::Color(55, 177, 255, 255));
	this->title.setOutlineThickness(1);
	this->title.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->title.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 2 - title.getGlobalBounds().width / 2, single_workspace.getPosition().y);

	this->text_procets.setFont(*font);
	this->text_procets.setString(std::to_string(volume_sound) + " / 100");
	this->text_procets.setCharacterSize(single_workspace.getGlobalBounds().height / 5);
	this->text_procets.setFillColor(sf::Color(55, 177, 255, 255));
	this->text_procets.setOutlineThickness(1);
	this->text_procets.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->text_procets.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 2 - text_procets.getGlobalBounds().width / 2, 
		single_workspace.getPosition().y + single_workspace.getGlobalBounds().height / 3 * 2);
}

uint8_t Slider_option::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	if (mouse.x > slider_black.getPosition().x && mouse.x < slider_black.getPosition().x + slider_black.getGlobalBounds().width &&
		mouse.y > slider_black.getPosition().y && mouse.y < slider_black.getPosition().y + slider_black.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->slider_hand.setPosition(mouse.x - slider_hand.getGlobalBounds().width / 2, slider_hand.getPosition().y);
		this->volume_sound = (slider_hand.getPosition().x + slider_hand.getGlobalBounds().width / 2 - slider_black.getPosition().x) / slider_black.getGlobalBounds().width * 100;
		this->text_procets.setString(std::to_string(volume_sound) + " / 100");
	}
	return volume_sound;
}

void Slider_option::draw(sf::RenderWindow& window)
{
	window.draw(single_workspace);
	window.draw(slider_all);
	window.draw(slider_black);
	window.draw(slider_hand);
	window.draw(title);
	window.draw(text_procets);
}



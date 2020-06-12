#include "Text_settings.hpp"

Text_settings::Text_settings(sf::RenderWindow& window, sf::RectangleShape work_space, sf::Font* font, std::string text_control, int max_x, int max_y, int index_x, int index_y)
{
	this->work_space = work_space;

	this->single_workspace.setSize(sf::Vector2f(work_space.getSize().x / max_x, work_space.getSize().y));
	this->single_workspace.setPosition(work_space.getPosition().x + single_workspace.getSize().x * (index_x - 1), work_space.getPosition().y);
	this->single_workspace.setFillColor(sf::Color(255, 255, 255, 0));
	this->single_workspace.setOutlineThickness(1);
	this->single_workspace.setOutlineColor(sf::Color(0, 0, 0, 0));

	//this->back_control;

	this->control_text;
	this->control_text.setFont(*font);
	this->control_text.setString(text_control);
	this->control_text.setCharacterSize(single_workspace.getGlobalBounds().height / 3.5);
	this->control_text.setFillColor(sf::Color(0, 177, 255, 255));
	this->control_text.setOutlineThickness(1);
	this->control_text.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->control_text.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 2 - control_text.getGlobalBounds().width / 2,
		single_workspace.getPosition().y + (single_workspace.getGlobalBounds().height / 3 * (index_y - 1)));
}

int Text_settings::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	return 0;
}

void Text_settings::draw(sf::RenderWindow& window)
{
	window.draw(single_workspace);
	window.draw(control_text);
}

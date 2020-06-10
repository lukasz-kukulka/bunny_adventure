#include "Settings_page.hpp"

Settings_page::Settings_page(sf::RenderWindow& window)
{
	this->settings_sections_no = 5;
	this->background.loadFromFile("Textures/Credits/back.jpg");
	this->background_sprite.setTexture(background);
	this->basic.setSize(sf::Vector2f(window.getSize().x - 50, window.getSize().y - 50));
	this->basic.setPosition(window.getSize().x / 2 - basic.getGlobalBounds().width / 2, window.getSize().y / 2 - basic.getGlobalBounds().height / 2);
	this->basic.setFillColor(sf::Color(255, 255, 255, 0));

	this->sec_font.loadFromFile("Fonts/good_mor.ttf");

	this->sections.push_back(Section(window, sections.size(), "RESOLUTION", settings_sections_no, basic, &sec_font));
	this->sections.push_back(Section(window, sections.size(), "SOUND", settings_sections_no, basic, &sec_font));
	this->sections.push_back(Section(window, sections.size(), "DIFICULT", settings_sections_no, basic, &sec_font));
	this->sections.push_back(Section(window, sections.size(), "CONTROL", settings_sections_no, basic, &sec_font));
	this->sections.push_back(Section(window, sections.size(), "", settings_sections_no, basic, &sec_font));
}

int Settings_page::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	return 3;
}

void Settings_page::draw(sf::RenderWindow& window)
{
	window.draw(background_sprite);
	window.draw(basic);
	for (int i = 0; i < sections.size(); i++)
	{
		sections[i].draw(window);
	}
}

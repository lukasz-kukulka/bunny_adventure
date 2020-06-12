#include "Section.hpp"

Section::Section(sf::RenderWindow& window, int index_section, std::string title, int limit_section, sf::RectangleShape& basic, sf::Font* font)
{
	this->basic_rec = basic;
	this->section_rec.setSize(sf::Vector2f(basic.getSize().x, basic.getSize().y / limit_section));
	this->section_rec.setPosition(basic.getPosition().x, basic.getPosition().y + index_section * section_rec.getGlobalBounds().height);
	this->section_rec.setFillColor(sf::Color(255, 0, 0, 11));
	this->section_rec.setOutlineThickness(1);
	this->section_rec.setOutlineColor(sf::Color(0, 0, 0, 11));

	this->top_rec.setSize(sf::Vector2f(section_rec.getSize().x / 10 * 9, section_rec.getSize().y / 3));
	this->top_rec.setPosition(section_rec.getPosition().x + section_rec.getSize().x / 10, section_rec.getPosition().y);
	this->top_rec.setFillColor(sf::Color(255, 255, 255, 0));
	this->top_rec.setOutlineThickness(1);
	this->top_rec.setOutlineColor(sf::Color(0, 0, 0, 0));

	this->cursor_rec.setSize(sf::Vector2f(section_rec.getSize().x / 10, section_rec.getSize().y));
	this->cursor_rec.setPosition(section_rec.getPosition().x, section_rec.getPosition().y);
	this->cursor_rec.setFillColor(sf::Color(255, 255, 255, 0));
	this->cursor_rec.setOutlineThickness(1);
	this->cursor_rec.setOutlineColor(sf::Color(0, 0, 0, 0));

	this->funcion_rec.setSize(sf::Vector2f(section_rec.getSize().x / 10 * 9, section_rec.getSize().y / 3 * 2));
	this->funcion_rec.setPosition(section_rec.getPosition().x + cursor_rec.getSize().x, section_rec.getPosition().y + top_rec.getSize().y);
	this->funcion_rec.setFillColor(sf::Color(255, 255, 255, 0));
	this->funcion_rec.setOutlineThickness(1);
	this->funcion_rec.setOutlineColor(sf::Color(0, 0, 0, 0));

	this->title_section.setFont(*font);
	this->title_section.setString(title);
	this->title_section.setCharacterSize(top_rec.getSize().y);
	this->title_section.setFillColor(sf::Color(255, 0, 0, 255));
	this->title_section.setOutlineThickness(1);
	this->title_section.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->title_section.setPosition(top_rec.getPosition().x + top_rec.getGlobalBounds().width / 2 - title_section.getGlobalBounds().width / 2,
		top_rec.getPosition().y + top_rec.getGlobalBounds().height / 2  - title_section.getGlobalBounds().height);
}


int Section::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	return 0;
}

sf::RectangleShape Section::shape()
{
	return funcion_rec;
}

void Section::draw(sf::RenderWindow& window)
{
	window.draw(section_rec);
	window.draw(top_rec);
	window.draw(cursor_rec);
	window.draw(funcion_rec);
	window.draw(title_section);
}
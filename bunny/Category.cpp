#include "Category.hpp"

Category::Category(sf::RenderWindow& window, sf::Texture* texture, sf::Font* font, std::string name, int index)
{
	this->index_cat = index;
	this->category_sprite.setTexture(*texture);
	this->category_sprite.setScale(1.0 / 1920 * window.getSize().x, 1.0 / 1920 * window.getSize().x);
	this->category_sprite.setPosition(window.getSize().x / 2 - category_sprite.getGlobalBounds().width / 2, index_cat * (window.getSize().y / 10) + 50);
	

	this->text_category.setFont(*font);
	this->text_category.setString(name);
	this->text_category.setCharacterSize(category_sprite.getGlobalBounds().height/4);
	this->text_category.setFillColor(sf::Color(255, 0, 111, 255));
	this->text_category.setOutlineThickness(2);
	this->text_category.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->text_category.setPosition(category_sprite.getPosition().x + category_sprite.getGlobalBounds().width / 2 - text_category.getGlobalBounds().width / 2,
		category_sprite.getPosition().y + category_sprite.getGlobalBounds().height / 2 - text_category.getGlobalBounds().height / 2);
	this->text_category.setOrigin(0, -8);
}

int Category::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	return 0;
}

int Category::pos_y()
{
	return category_sprite.getPosition().y + category_sprite.getGlobalBounds().height;
}

void Category::draw(sf::RenderWindow& window)
{
	window.draw(category_sprite);
	window.draw(text_category);
}

#include "Single_score_record.hpp"

Single_score_record::Single_score_record(sf::RenderWindow& window, sf::Texture* trash_tex, sf::Font* font, sf::RectangleShape& base_rec, uint16_t index, 
	std::string name_load, std::string date_load, std::string score_load, bool visible_record)
{
	this->font = font;
	this->trash_tex = trash_tex;
	this->name_load = name_load;
	this->date_load = date_load;
	this->score_load = score_load;
	this->base_shape = base_rec;
	this->index = index;
	this->visible_score = visible_record;
	this->size_single_record = base_shape.getSize().y / 15;
	objects_ini(window);
}

uint8_t Single_score_record::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	if (all_record.getPosition().y + 10 < base_shape.getPosition().y || all_record.getPosition().y + 10 > base_shape.getPosition().y + base_shape.getSize().y)
	{
		objects_unvisible(window);
	}
	else
	{
		objects_visible(window);
	}
	if (mouse.x > trash.getPosition().x && mouse.x < trash.getPosition().x + trash.getGlobalBounds().width &&
		mouse.y > trash.getPosition().y && mouse.y < trash.getPosition().y + trash.getGlobalBounds().height)
	{
		this->trash.setFillColor(sf::Color(255, 255, 255, 222));
		this->trash_sprite.setScale(window.getSize().y / 1000.0, window.getSize().y / 1000.0);
		this->trash_sprite.setPosition(trash.getPosition().x + trash.getSize().x / 2 - trash_sprite.getGlobalBounds().width / 2,
			trash.getPosition().y + 2);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return 1;
		}

	}
	else
	{
		this->trash.setFillColor(sf::Color(255, 255, 255, 111));
		this->trash_sprite.setPosition(trash.getPosition().x + trash.getSize().x / 2 - trash_sprite.getGlobalBounds().width / 2,
			trash.getPosition().y + 2);

		return 0;
	}

	return 0;
}

void Single_score_record::objects_visible(sf::RenderWindow& window)
{
	this->all_record.setSize(sf::Vector2f(base_shape.getSize().x, size_single_record));
	this->all_record.setOutlineThickness(1);
	this->name.setSize(sf::Vector2f(all_record.getSize().x / 10 * 3, all_record.getSize().y));
	this->name.setOutlineThickness(1);
	this->name_text.setCharacterSize(window.getSize().y / 40);
	this->name_text.setOutlineThickness(1);
	this->date.setSize(sf::Vector2f(all_record.getSize().x / 10 * 3, all_record.getSize().y));
	this->date.setOutlineThickness(1);
	this->date_text.setCharacterSize(window.getSize().y / 40);
	this->date_text.setOutlineThickness(1);
	this->score.setSize(sf::Vector2f(all_record.getSize().x / 10 * 3, all_record.getSize().y));
	this->score.setOutlineThickness(1);
	this->score_text.setCharacterSize(window.getSize().y / 40);
	this->score_text.setOutlineThickness(1);
	this->trash.setSize(sf::Vector2f(all_record.getSize().x / 10 - 5, all_record.getSize().y));
	this->trash.setOutlineThickness(1);
	this->trash_sprite.setScale(window.getSize().y / 1500.0, window.getSize().y / 1500.0);
	this->delete_text.setCharacterSize(window.getSize().y / 80);
	this->visible_score = true;
}

void Single_score_record::objects_unvisible(sf::RenderWindow& window)
{
	this->all_record.setSize(sf::Vector2f(0,0));
	this->all_record.setOutlineThickness(0);
	this->name.setSize(sf::Vector2f(0,0));
	this->name.setOutlineThickness(0);
	this->name_text.setCharacterSize(0);
	this->name_text.setOutlineThickness(0);
	this->date.setSize(sf::Vector2f(0,0));
	this->date.setOutlineThickness(0);
	this->date_text.setCharacterSize(0);
	this->date_text.setOutlineThickness(0);
	this->score.setSize(sf::Vector2f(0,0));
	this->score.setOutlineThickness(0);
	this->score_text.setCharacterSize(0);
	this->score_text.setOutlineThickness(0);
	this->trash.setSize(sf::Vector2f(0,0));
	this->trash.setOutlineThickness(0);
	this->trash_sprite.setScale(0,0);
	this->delete_text.setCharacterSize(0);
	this->visible_score = false;
}

uint8_t Single_score_record::index_out()
{
	return index;
}

bool Single_score_record::visible_status()
{
	return visible_score;
}

void Single_score_record::move_up(sf::RenderWindow& window)
{
		objects_visible(window);
		this->all_record.setPosition(all_record.getPosition().x, all_record.getPosition().y - size_single_record);

		this->name.setPosition(all_record.getPosition().x, all_record.getPosition().y);
		this->name_text.setPosition(name.getPosition().x + name.getSize().x / 2 - name_text.getGlobalBounds().width / 2,
			name.getPosition().y + name.getSize().y / 2 - name_text.getGlobalBounds().height / 2);
		this->date.setPosition(name.getPosition().x + name.getSize().x, name.getPosition().y);
		this->date_text.setPosition(date.getPosition().x + date.getSize().x / 2 - date_text.getGlobalBounds().width / 2,
			date.getPosition().y + date.getSize().y / 2 - date_text.getGlobalBounds().height / 2);
		this->score.setPosition(date.getPosition().x + date.getSize().x, date.getPosition().y);
		this->score_text.setPosition(score.getPosition().x + score.getSize().x / 2 - score_text.getGlobalBounds().width / 2,
			score.getPosition().y + score.getSize().y / 2 - score_text.getGlobalBounds().height / 2);
		this->trash.setPosition(score.getPosition().x + score.getSize().x, score.getPosition().y);
		this->trash_sprite.setPosition(trash.getPosition().x + trash.getSize().x / 2 - trash_sprite.getGlobalBounds().width / 2,
			trash.getPosition().y + 2);
		this->delete_text.setPosition(trash.getPosition().x + trash.getSize().x / 2 - delete_text.getGlobalBounds().width / 2,
			trash_sprite.getPosition().y + trash_sprite.getGlobalBounds().height);
		objects_unvisible(window);
}

void Single_score_record::move_down(sf::RenderWindow& window)
{
		objects_visible(window);
		this->all_record.setPosition(all_record.getPosition().x, all_record.getPosition().y + size_single_record);
		this->name.setPosition(all_record.getPosition().x, all_record.getPosition().y);
		this->name_text.setPosition(name.getPosition().x + name.getSize().x / 2 - name_text.getGlobalBounds().width / 2,
			name.getPosition().y + name.getSize().y / 2 - name_text.getGlobalBounds().height / 2);
		this->date.setPosition(name.getPosition().x + name.getSize().x, name.getPosition().y);
		this->date_text.setPosition(date.getPosition().x + date.getSize().x / 2 - date_text.getGlobalBounds().width / 2,
			date.getPosition().y + date.getSize().y / 2 - date_text.getGlobalBounds().height / 2);
		this->score.setPosition(date.getPosition().x + date.getSize().x, date.getPosition().y);
		this->score_text.setPosition(score.getPosition().x + score.getSize().x / 2 - score_text.getGlobalBounds().width / 2,
			score.getPosition().y + score.getSize().y / 2 - score_text.getGlobalBounds().height / 2);
		this->trash.setPosition(score.getPosition().x + score.getSize().x, score.getPosition().y);
		this->trash_sprite.setPosition(trash.getPosition().x + trash.getSize().x / 2 - trash_sprite.getGlobalBounds().width / 2,
			trash.getPosition().y + 2);
		this->delete_text.setPosition(trash.getPosition().x + trash.getSize().x / 2 - delete_text.getGlobalBounds().width / 2,
			trash_sprite.getPosition().y + trash_sprite.getGlobalBounds().height);
		objects_unvisible(window);
}

void Single_score_record::objects_ini(sf::RenderWindow& window)
{
	this->all_record.setSize(sf::Vector2f(base_shape.getSize().x, size_single_record));
	this->all_record.setPosition(base_shape.getPosition().x, base_shape.getPosition().y + size_single_record * index);
	this->all_record.setFillColor(sf::Color(255, 255, 255, 0));
	this->all_record.setOutlineThickness(1);
	this->all_record.setOutlineColor(sf::Color(0, 0, 0, 111));

	this->name.setSize(sf::Vector2f(all_record.getSize().x / 10 * 3, all_record.getSize().y));
	this->name.setPosition(all_record.getPosition().x, all_record.getPosition().y);
	this->name.setFillColor(sf::Color(77, 255, 77, 199));
	this->name.setOutlineThickness(1);
	this->name.setOutlineColor(sf::Color(0, 0, 0, 111));

	this->name_text.setFont(*font);
	this->name_text.setString(name_load);
	this->name_text.setCharacterSize(window.getSize().y / 40);
	this->name_text.setFillColor(sf::Color(0, 77, 0, 255));
	this->name_text.setOutlineThickness(1);
	this->name_text.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->name_text.setPosition(name.getPosition().x + name.getSize().x / 2 - name_text.getGlobalBounds().width / 2,
		name.getPosition().y + name.getSize().y / 2 - name_text.getGlobalBounds().height / 2);

	this->date.setSize(sf::Vector2f(all_record.getSize().x / 10 * 3, all_record.getSize().y));
	this->date.setPosition(name.getPosition().x + name.getSize().x, name.getPosition().y);
	this->date.setFillColor(sf::Color(111, 111, 255, 199));
	this->date.setOutlineThickness(1);
	this->date.setOutlineColor(sf::Color(0, 0, 0, 111));

	this->date_text.setFont(*font);
	this->date_text.setString(date_load);
	this->date_text.setCharacterSize(window.getSize().y / 40);
	this->date_text.setFillColor(sf::Color(0, 0, 88, 255));
	this->date_text.setOutlineThickness(1);
	this->date_text.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->date_text.setPosition(date.getPosition().x + date.getSize().x / 2 - date_text.getGlobalBounds().width / 2,
		date.getPosition().y + date.getSize().y / 2 - date_text.getGlobalBounds().height / 2);

	this->score.setSize(sf::Vector2f(all_record.getSize().x / 10 * 3, all_record.getSize().y));
	this->score.setPosition(date.getPosition().x + date.getSize().x, date.getPosition().y);
	this->score.setFillColor(sf::Color(255, 111, 111, 199));
	this->score.setOutlineThickness(1);
	this->score.setOutlineColor(sf::Color(0, 0, 0, 111));

	this->score_text.setFont(*font);
	this->score_text.setString(score_load);
	this->score_text.setCharacterSize(window.getSize().y / 40);
	this->score_text.setFillColor(sf::Color(177, 0, 0, 255));
	this->score_text.setOutlineThickness(1);
	this->score_text.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->score_text.setPosition(score.getPosition().x + score.getSize().x / 2 - score_text.getGlobalBounds().width / 2,
		score.getPosition().y + score.getSize().y / 2 - score_text.getGlobalBounds().height / 2);

	this->trash.setSize(sf::Vector2f(all_record.getSize().x / 10 - 5, all_record.getSize().y));
	this->trash.setPosition(score.getPosition().x + score.getSize().x, score.getPosition().y);
	this->trash.setFillColor(sf::Color(255, 255, 255, 111));
	this->trash.setOutlineThickness(1);
	this->trash.setOutlineColor(sf::Color(0, 0, 0, 111));

	this->trash_sprite.setTexture(*trash_tex);
	this->trash_sprite.setScale(window.getSize().y / 1500.0, window.getSize().y / 1500.0);
	this->trash_sprite.setPosition(trash.getPosition().x + trash.getSize().x / 2 - trash_sprite.getGlobalBounds().width / 2,
		trash.getPosition().y + 2);

	this->delete_text.setFont(*font);
	this->delete_text.setString("Delete");
	this->delete_text.setCharacterSize(window.getSize().y / 80);
	this->delete_text.setFillColor(sf::Color(0, 0, 0, 255));
	this->delete_text.setPosition(trash.getPosition().x + trash.getSize().x / 2 - delete_text.getGlobalBounds().width / 2,
		trash_sprite.getPosition().y + trash_sprite.getGlobalBounds().height);
}

void Single_score_record::draw(sf::RenderWindow& window)
{
	window.draw(all_record);
	window.draw(name);
	window.draw(date);
	window.draw(score);
	window.draw(trash);
	window.draw(name_text);
	window.draw(score_text);
	window.draw(date_text);
	window.draw(delete_text);
	window.draw(trash_sprite);
}

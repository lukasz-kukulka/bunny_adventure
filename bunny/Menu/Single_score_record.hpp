#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Single_score_record
{
public:
	Single_score_record(sf::RenderWindow& window, sf::Texture* trash_tex, sf::Font* font, sf::RectangleShape& base_rec, uint16_t index, std::string name_load, std::string date_load, std::string score_load, bool visible_record);
	uint8_t system(sf::RenderWindow& window, sf::Vector2i mouse);
	void objects_visible(sf::RenderWindow& window);
	void objects_unvisible(sf::RenderWindow& window);
	uint8_t index_out();
	bool visible_status();
	void move_up(sf::RenderWindow& window);
	void move_down(sf::RenderWindow& window);
	void objects_ini(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape all_record, name, date, score, trash, base_shape;
	sf::Font* font;
	sf::Texture* trash_tex;
	sf::Sprite trash_sprite;
	sf::Clock move_record_clock;
	sf::Time move_record_time;
	sf::Text name_text, score_text, date_text, delete_text;
	std::string name_load, date_load, score_load;
	bool visible_score;
	uint8_t index, size_single_record;
};


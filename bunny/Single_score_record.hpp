#pragma once
#include <SFML/Graphics.hpp>
class Single_score_record
{
public:
	Single_score_record(sf::RenderWindow& window, sf::Texture* trash_tex, sf::Font* font, sf::RectangleShape& base_rec, uint16_t index, std::string name_load, std::string date_load, std::string score_load);
	int system(sf::RenderWindow& window, sf::Vector2i mouse);

	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape all_record, name, date, score, trash, base_shape;
	sf::Sprite trash_sprite;
	sf::Text name_text, score_text, date_text, delete_text;

	uint16_t index;
};


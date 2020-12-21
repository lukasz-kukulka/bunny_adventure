#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Bonus_extra_effect
{
public:
	Bonus_extra_effect(sf::RenderWindow& window, sf::Font* font, sf::Vector2f position, uint8_t type_of_bonus);
	uint8_t system(sf::View window);
	void can_delete_change(bool index);
	bool can_delete_out();
	void draw(sf::RenderWindow& window);

private:
	sf::Text bonus_text;
	sf::Vector2f position_text_bonus{ -100, -100 };
	uint8_t bonus_type{ 0 };
	bool can_delete{ false };

};


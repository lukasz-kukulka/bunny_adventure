#pragma once
#include <SFML/Graphics.hpp>
#include "../Pick_items_ini.hpp"
#include "../Choise_lvl_bonus.hpp"
#include "../Pick_items_ini.hpp"

class Pick_lvl_test : public Choise_lvl_bonus
{
public:
	Pick_lvl_test(sf::RenderWindow& window);
	uint8_t system();
	void initialize_pick_class(sf::RenderWindow& window);
	void initialize_singe_bonus_item(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
private:
	uint8_t bonus501, bonus502, bonus503, bonus504, bonus505, bonus506, bonus507, bonus508, bonus509, bonus510, bonus511, bonus512;
	std::vector<Pick_items_ini>bonus_ini;
};


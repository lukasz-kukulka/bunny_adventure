#include "Interface.hpp"

Interface::Interface(sf::RenderWindow& window)
{
	background_tex.loadFromFile("Textures/Menu/background1.jpg");
	background_sprite.setTexture(background_tex);
	background_sprite.setScale(1.0 / 1080.0 * window.getSize().y, 1.0 / 1080.0 * window.getSize().y);
	background_sprite.setPosition(window.getSize().x - background_sprite.getGlobalBounds().width, background_sprite.getPosition().y);

	menu_button_left.loadFromFile("Textures/Menu/left_button_blue.png");
	menu_button_mid.loadFromFile("Textures/Menu/mid_button_blue.png");
	menu_button_right.loadFromFile("Textures/Menu/right_button_blue.png");

	arrow_left.loadFromFile("Textures/Menu/arrow_left.png");
	arrow_right.loadFromFile("Textures/Menu/arrow_right.png");

	font_menu_button.loadFromFile("Fonts/avocado.ttf");
    //#include <random>
	//#include <chrono>
	//std::default_random_engine generator;
	//std::uniform_int_distribution<int> third_plan_tree_x{ 0, win_size_X };
	//std::uniform_int_distribution<int> third_plan_tree_y{ win_size_Y/ win_size_Y + 100 , win_size_Y-100};

	button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "New game"));
	button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "Best Score"));
	button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "Options"));
	button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "Credits"));
	button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "Exit"));

	//arrows.push_back(Arrow(&arrow_right, button_menu[0].begin_button_x(), button_menu[0].begin_button_y(), button_menu[0].scale(), button_menu[0].scale()));
	//arrows.push_back(Arrow(&arrow_left, button_sprite_left.getPosition().x - 138, button_sprite_left.getPosition().y, button_sprite_left.getScale().x, button_sprite_left.getScale().y));
}

int Interface::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	for (int i = 0; i < button_menu.size(); i++)
	{
		//std::cout << i << std::endl;
		//std::cout << i << " ----- " << button_menu[i].mark(window, mouse) << std::endl;
		if(button_menu[i].mark(window, mouse) != 0)
			return button_menu[i].mark(window, mouse);
		for (auto i : button_menu)
			i.mark(window, mouse);

		//else
			//button_menu[i].mark(window, mouse);
			
	}
	//for (auto i : button_menu)
		//i.mark(window, mouse);
		//return i.mark(window, mouse);;
	
	return 0;
}

void Interface::draw(sf::RenderWindow& window)
{
	window.draw(background_sprite);
	for (auto i : button_menu)
		i.draw(window);
	
	//for (auto i : tree)
		//i.draw(window);
	//for (auto i : green2)
		//i.draw(window);
}

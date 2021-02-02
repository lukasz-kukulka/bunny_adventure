#include "Interface.hpp"

Interface::Interface(sf::RenderWindow& window) 
{
	
	this->jaguar.loadFromFile("Menu/Textures/Menu/Jaguar.png");
	this->cloud.loadFromFile("Menu/Textures/Menu/cloud.png");
	this->forest.loadFromFile("Menu/Textures/Menu/forest1.png");
	this->leaf.loadFromFile("Menu/Textures/Menu/leaf.png");
	this->menu_button_left.loadFromFile("Menu/Textures/Menu/left_button_blue.png");
	this->menu_button_mid.loadFromFile("Menu/Textures/Menu/mid_button_blue.png");
	this->menu_button_right.loadFromFile("Menu/Textures/Menu/right_button_blue.png");
	this->arrow_left.loadFromFile("Menu/Textures/Menu/arrow_left.png");
	this->arrow_right.loadFromFile("Menu/Textures/Menu/arrow_right.png");
	this->background_base.loadFromFile("Menu/Textures/Menu/background1.jpg");
	this->buffer_menu.loadFromFile("Menu/Sound/Menu/click.wav");
	this->click_sound.setBuffer(buffer_menu);
	this->click_sound.setVolume(15.f);
	this->buffer_menu_choise.loadFromFile("Menu/Sound/Menu/choise.wav");
	this->choise_sound.setBuffer(buffer_menu_choise);
	this->choise_sound.setVolume(15.f);
	this->font_menu_button.loadFromFile("Menu/Fonts/avocado.ttf");
	this->button_confirm_font.loadFromFile("Menu/Fonts/bongus.ttf");

	this->end_animation = false;
	this->background_sprite.setTexture(background_base);
	this->background_sprite.setScale(1.0 / 1080.0 * window.getSize().y, 1.0 / 1080.0 * window.getSize().y);
	this->background_sprite.setPosition(window.getSize().x - background_sprite.getGlobalBounds().width, background_sprite.getPosition().y);

	this->button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "New game"));
	this->button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "Best Score"));
	this->button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "Settings"));
	this->button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "Credits"));
	this->button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "Exit"));

	this->exit_objects.push_back(Exit(window, &jaguar, &cloud, &forest, &font_menu_button));
}

uint8_t Interface::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	if (end_animation == true)
	{
		for (uint8_t i = 0; i < exit_objects.size(); i++)
		{
			if (exit_objects[i].system(window, mouse) == 5)
			{
				for (uint8_t j = 0; j < exit_objects.size(); j++)
				{
					exit_objects[j].sub();
					if (buttons.size() <= 1)
					{
						buttons.push_back(Button(window, &leaf, &button_confirm_font, "YES", buttons.size(), exit_objects[0].fox_pos_X_out(), exit_objects[0].fox_pos_Y_out()));
						buttons.push_back(Button(window, &leaf, &button_confirm_font, "NO", buttons.size(), exit_objects[0].fox_pos_X_out(), exit_objects[0].fox_pos_Y_out()));
					}
					for (uint8_t x = 0; x < buttons.size(); x++)
					{
						button_answer = buttons[x].system(window, mouse);
						if (button_answer == 5)
						{
							return 5;
						}
						else if (button_answer == 1)
						{
							choise_sound.play();
							buttons.erase(buttons.begin(), buttons.end());
							exit_objects[0].no_exit();
							end_animation = false;
							return 0;
						}
					}
					
				}
			}
		}
		return 0;
	}

	else
	{
		for (uint8_t i = 0; i < button_menu.size(); i++)
		{
			if (button_menu[i].mark(window, mouse) >= 10 && play_click[i] == true)
			{
				this->click_sound.play();
				for (uint8_t j = 0; j < button_menu.size(); j++)
				{
					if (j == i)
						this->play_click[j] = false;
					else
						this->play_click[j] = true;
				}					
			}
			if (button_menu[i].mark(window, mouse) > 0 && button_menu[i].mark(window, mouse) < 5)
			{
				choise_sound.play();
				return button_menu[i].mark(window, mouse);
			}
			else if (button_menu[i].mark(window, mouse) == 5)
			{
				choise_sound.play();
				end_animation = true;
			}
			for (auto i : button_menu)
				i.mark(window, mouse);
		}
		return 0;
	}

}

void Interface::settings(uint8_t volume)
{
	click_sound.setVolume(15.f / 100 * volume);
	choise_sound.setVolume(15.f / 100 * volume);
}

void Interface::draw(sf::RenderWindow& window)
{
	window.draw(background_sprite);
	for (auto i : button_menu)
		i.draw(window);
	for (auto i : exit_objects)
		i.draw(window);
	for (auto i : buttons)
		i.draw(window);
}

#include "Interface.hpp"

Interface::Interface(sf::RenderWindow& window) : Load_from_files(window)
{
	this->end_animation = false;
	background_sprite.setTexture(background_base);
	background_sprite.setScale(1.0 / 1080.0 * window.getSize().y, 1.0 / 1080.0 * window.getSize().y);
	background_sprite.setPosition(window.getSize().x - background_sprite.getGlobalBounds().width, background_sprite.getPosition().y);

	arrow_left.loadFromFile("Textures/Menu/arrow_left.png");
	arrow_right.loadFromFile("Textures/Menu/arrow_right.png");

	font_menu_button.loadFromFile("Fonts/avocado.ttf");
	button_confirm_font.loadFromFile("Fonts/bongus.ttf");

	buffer_menu.loadFromFile("Sound/Menu/click.wav");
	click_sound.setBuffer(buffer_menu);
	click_sound.setVolume(15.f);
	buffer_menu_choise.loadFromFile("Sound/Menu/choise.wav");
	choise_sound.setBuffer(buffer_menu_choise);
	choise_sound.setVolume(15.f);

	button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "New game"));
	button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "Best Score"));
	button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "Settings"));
	button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "Credits"));
	button_menu.push_back(Menu(window, &menu_button_left, &menu_button_mid, &menu_button_right, &arrow_left, &arrow_right, &font_menu_button, button_menu.size(), "Exit"));

	exit_objects.push_back(Exit(window, &jaguar, &cloud, &forest, &font_menu_button));
}

int Interface::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	if (end_animation == true)
	{
		for (int i = 0; i < exit_objects.size(); i++)
		{
			if (exit_objects[i].system(window, mouse) == 5)
			{
				for (int j = 0; j < exit_objects.size(); j++)
				{
					exit_objects[j].sub();
					if (buttons.size() <= 1)
					{
						buttons.push_back(Button(window, &leaf, &button_confirm_font, "YES", buttons.size(), exit_objects[0].fox_pos_X_out(), exit_objects[0].fox_pos_Y_out()));
						buttons.push_back(Button(window, &leaf, &button_confirm_font, "NO", buttons.size(), exit_objects[0].fox_pos_X_out(), exit_objects[0].fox_pos_Y_out()));
					}
					for (int x = 0; x < buttons.size(); x++)
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
		for (int i = 0; i < button_menu.size(); i++)
		{
			if (button_menu[i].mark(window, mouse) >= 10 && play_click[i] == true)
			{
				this->click_sound.play();
				for (int j = 0; j < button_menu.size(); j++)
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

void Interface::settings(int volume)
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

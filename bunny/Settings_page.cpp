#include "Settings_page.hpp"

Settings_page::Settings_page(sf::RenderWindow& window): Load_from_files(window)
{
	this->settings_sections_no = 5;
	this->settings_resolution = 3;
	this->settings_sound = 3;
	this->settings_dificult = 3;
	this->settings_control_columns = 3;
	this->max_row_control = 3;
	this->settings_summary = 3;
	this->time_save_begin = sf::seconds(3.0f);
	this->temp_settings = settings_deffault = { 1, 10, true, true, 1 };
	this->res_settings = diff_settings = { false, false, false };
	//this->background.loadFromFile("Textures/Credits/back.jpg");
	//this->button_color.loadFromFile("Textures/Settings/button_color.png");
	//this->button_grey.loadFromFile("Textures/Settings/button_grey.png");
	//this->cursor_section.loadFromFile("Textures/Settings/id_rec.png");
	//this->save_exit_button.loadFromFile("Textures/Settings/control.png");
	//this->save_exit_button_grey.loadFromFile("Textures/Settings/control_grey.png");
	//this->slider_base.loadFromFile("Textures/Settings/slider.png");
	//this->slider_black.loadFromFile("Textures/Settings/slider_black.png");
	//this->slider_volume.loadFromFile("Textures/Settings/slider_bunny1.png");
	//this->yes_color.loadFromFile("Textures/Settings/yes.png");
	//this->yes_grey.loadFromFile("Textures/Settings/yes_grey.png");


	this->background_sprite_settings.setTexture(background_tex);
	this->basic.setSize(sf::Vector2f(window.getSize().x - 50, window.getSize().y - 50));
	this->basic.setPosition(window.getSize().x / 2 - basic.getGlobalBounds().width / 2, window.getSize().y / 2 - basic.getGlobalBounds().height / 2);
	this->basic.setFillColor(sf::Color(255, 255, 255, 0));

	this->save_back_rec.setSize(sf::Vector2f(0, 0));
	this->save_back_rec.setPosition(0, 0);
	this->save_back_rec.setFillColor(sf::Color(0, 0, 0, 200));

	this->button_font.loadFromFile("Fonts/flut.ttf");
	this->sec_font.loadFromFile("Fonts/beachday.ttf");
	this->game_font.loadFromFile("Fonts/game.ttf");
	this->kids_font.loadFromFile("Fonts/kids.ttf"); 
	
	this->load_settings();
	this->settings_ini_button();
	this->objects_ini(window);

	this->button_buffer.loadFromFile("Sound/Menu/options_button.wav");
	this->button_sound.setBuffer(button_buffer);
	this->button_sound.setVolume(15.f);
	this->slider_buffer.loadFromFile("Sound/Menu/slider.wav");
	this->slider_sound.setBuffer(slider_buffer);
	this->slider_sound.setVolume(15.f);
	this->save_buffer.loadFromFile("Sound/Menu/save_file.wav");
	this->save_sound.setBuffer(save_buffer);
	this->save_sound.setVolume(15.f);
	this->buffer_choise.loadFromFile("Sound/Menu/choise.wav");
	this->sound_choise.setBuffer(buffer_choise);
	this->sound_choise.setVolume(15.f);
}

int Settings_page::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	time_save = time_save_begin + clock_save.getElapsedTime();
	for (int i = 0; i < sections.size(); i++)
	{
		sections[i].system(window, mouse);
	}
	for (int i = 0; i < buttons_resolution.size(); i++)
	{
		temp_settings.res = buttons_resolution[i].system(window, mouse);
		if (temp_settings.res != 0)
		{
			button_sound.play();

			for (int j = 0; j < buttons_resolution.size(); j++)
			{
				user_settings.res = temp_settings.res;
				buttons_resolution[j].changing_status(user_settings.res);
			}
		}
	}
	
	for (int i = 0; i < buttons_diff.size(); i++)
	{
		temp_settings.dif = buttons_diff[i].system(window, mouse);
		if (temp_settings.dif != 0)
		{
			button_sound.play();
			for (int j = 0; j < buttons_diff.size(); j++)
			{
				user_settings.dif = temp_settings.dif;
				buttons_diff[j].changing_status(user_settings.dif);
			}
		}
	}
	for (int i = 0; i < sliders_sound.size(); i++)
	{
		if (user_settings.vol != sliders_sound[i].system(window, mouse))
		{
			this->user_settings.vol = sliders_sound[i].system(window, mouse);
			this->slider_sound.play();
			this->slider_sound.setVolume(15.f / 100 * user_settings.vol);
			this->button_sound.setVolume(15.f / 100 * user_settings.vol);
			this->save_sound.setVolume(15.f / 100 * user_settings.vol);
			this->sound_choise.setVolume(15.f / 100 * user_settings.vol);
		}
		
	}
	for (int i = 0; i < yes_no_buttons.size(); i++)
	{
		
		settings_sound_save = yes_no_buttons[i].system(window, mouse);
		if (settings_sound_save >= 1 && settings_sound_save <= 4)
		{
			button_sound.play();
		}
		if (settings_sound_save == 1)
		{
			user_settings.efect = false;
		}
		else if (settings_sound_save == 2)
		{
			user_settings.efect = true;
		}	
		else if (settings_sound_save == 3)
		{
			user_settings.music = false;
		}
		else if (settings_sound_save == 4)
		{
			user_settings.music = true;
		}
	}
	for (int i = 0; i < buttons_save_back.size(); i++)
	{
		press_save_back = buttons_save_back[i].system(window, mouse);
		if (press_save_back >= 10 && play_click[i] == true)
		{
			this->button_sound.play();
			for (int j = 0; j < buttons_save_back.size(); j++)
			{
				if (j == i)
					this->play_click[j] = false;
				else
					this->play_click[j] = true;
			}
		}
		else if (press_save_back == 1)
		{
			sound_choise.play();
			this->settings_ini->save_settings(user_settings.res, user_settings.vol, user_settings.efect, user_settings.music, user_settings.dif);
			this->save_button_press = true;
			this->clock_save.restart();
			this->time_save_begin = sf::seconds(0.0f);
			this->save_back_rec.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
		}
		else if (press_save_back == 2)
		{
			sound_choise.play();
			user_settings = settings_deffault;
			settings_ini_button();
			objects_ini(window);
		}
		else if (press_save_back == 3)
		{
			sound_choise.play();
			load_settings();
			settings_ini_button();
			objects_ini(window);
			return 0;
		}
	}

	if (time_save.asSeconds() < 4 && save_button_press == true)
	{
		if (time_save.asSeconds() <= 2)
		{
			this->texts.push_back(Text(window, &sec_font, "SETTING SAVED", window.getSize().x / 2, window.getSize().y / 10 * 4, window.getSize().y / 20, 3));
			this->texts.push_back(Text(window, &sec_font, "SOME SETTING NEED RESTART PROGRAM", window.getSize().x / 2, window.getSize().y / 10 * 5, window.getSize().y / 30, 3));
		}
		else if(time_save.asSeconds() > 2)
		{
			this->save_back_rec.setSize(sf::Vector2f(0, 0));
			this->texts.erase(texts.begin(), texts.end());
			this->save_button_press = false;
			this->save_sound.play();
			return 3;
		}	
	}
		
	return 3;
}

void Settings_page::load_settings()
{
	this->user_settings.res = settings_ini->load_from_settings(1);
	this->user_settings.vol = settings_ini->load_from_settings(2);
	this->user_settings.efect = settings_ini->load_from_settings(3);
	this->user_settings.music = settings_ini->load_from_settings(4);
	this->user_settings.dif = settings_ini->load_from_settings(5);
}

void Settings_page::settings_ini_button()
{
	if (this->user_settings.res == 1)
	{
		this->res_settings.one = true;
		this->res_settings.two = false;
		this->res_settings.three = false;
	}
	else if (this->user_settings.res == 2)
	{
		this->res_settings.one = false;
		this->res_settings.two = true;
		this->res_settings.three = false;
	}
	else if (this->user_settings.res == 3)
	{
		this->res_settings.one = false;
		this->res_settings.two = false;
		this->res_settings.three = true;
	}

	if (this->user_settings.dif == 1)
	{
		this->diff_settings.one = true;
		this->diff_settings.two = false;
		this->diff_settings.three = false;
	}
	else if (this->user_settings.dif == 2)
	{
		this->diff_settings.one = false;
		this->diff_settings.two = true;
		this->diff_settings.three = false;
	}
	else if (this->user_settings.dif == 3)
	{
		this->diff_settings.one = false;
		this->diff_settings.two = false;
		this->diff_settings.three = true;
	}
}

void Settings_page::objects_ini(sf::RenderWindow& window)
{
	for (int i = 0; i < sections.size(); i++)
	{
		sections.erase(sections.begin(), sections.end());
	}
	for (int i = 0; i < buttons_resolution.size(); i++)
	{
		buttons_resolution.erase(buttons_resolution.begin(), buttons_resolution.end());
	}
	for (int i = 0; i < buttons_diff.size(); i++)
	{
		buttons_diff.erase(buttons_diff.begin(), buttons_diff.end());
	}
	for (int i = 0; i < sliders_sound.size(); i++)
	{
		sliders_sound.erase(sliders_sound.begin(), sliders_sound.end());
	}
	for (int i = 0; i < yes_no_buttons.size(); i++)
	{
		yes_no_buttons.erase(yes_no_buttons.begin(), yes_no_buttons.end());
	}
	for (int i = 0; i < text_control.size(); i++)
	{
		text_control.erase(text_control.begin(), text_control.end());
	}
	for (int i = 0; i < buttons_save_back.size(); i++)
	{
		buttons_save_back.erase(buttons_save_back.begin(), buttons_save_back.end());
	}

	this->sections.push_back(Section(window, sections.size(), "RESOLUTION", settings_sections_no, basic, &sec_font, &cursor_section));
	this->buttons_resolution.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "1280 X 1024", settings_resolution, buttons_resolution.size(), res_settings.one));
	this->buttons_resolution.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "1600 X 900", settings_resolution, buttons_resolution.size(), res_settings.two));
	this->buttons_resolution.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "1920 X 1080", settings_resolution, buttons_resolution.size(), res_settings.three));

	this->sections.push_back(Section(window, sections.size(), "SOUND", settings_sections_no, basic, &sec_font, &cursor_section));
	this->sliders_sound.push_back(Slider_option(window, sections[sections.size() - 1].shape(), &slider_base, &slider_black, &slider_volume, &sec_font, settings_sound, 0, "Volume", user_settings.vol));
	this->yes_no_buttons.push_back(Yes_no_option(window, sections[sections.size() - 1].shape(), &yes_color, &yes_grey, &sec_font, settings_sound, 1, "EFECTS", user_settings.efect));
	this->yes_no_buttons.push_back(Yes_no_option(window, sections[sections.size() - 1].shape(), &yes_color, &yes_grey, &sec_font, settings_sound, 2, "MUSIC", user_settings.music));

	this->sections.push_back(Section(window, sections.size(), "DIFFICULTY", settings_sections_no, basic, &sec_font, &cursor_section));
	this->buttons_diff.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "EASY", settings_resolution, buttons_diff.size(), diff_settings.one));
	this->buttons_diff.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "NORMAL", settings_resolution, buttons_diff.size(), diff_settings.two));
	this->buttons_diff.push_back(Button_option(window, sections[sections.size() - 1].shape(), &button_color, &button_grey, &button_font, "HARD", settings_resolution, buttons_diff.size(), diff_settings.three));

	this->sections.push_back(Section(window, sections.size(), "CONTROL", settings_sections_no, basic, &sec_font, &cursor_section));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "space - jump", settings_control_columns, max_row_control, 1, 1));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control_columns, max_row_control, 1, 2));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control_columns, max_row_control, 1, 3));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control_columns, max_row_control, 2, 1));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control_columns, max_row_control, 2, 2));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control_columns, max_row_control, 2, 3));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control_columns, max_row_control, 3, 1));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control_columns, max_row_control, 3, 2));
	this->text_control.push_back(Text_settings(window, sections[sections.size() - 1].shape(), &game_font, "empty - empty", settings_control_columns, max_row_control, 3, 3));

	this->sections.push_back(Section(window, sections.size(), "", settings_sections_no, basic, &sec_font, &cursor_section));
	this->buttons_save_back.push_back(Button_option(window, sections[sections.size() - 1].shape(), &save_exit_button, &save_exit_button_grey, &button_font, "SAVE", settings_summary, buttons_save_back.size(), false));
	this->buttons_save_back.push_back(Button_option(window, sections[sections.size() - 1].shape(), &save_exit_button, &save_exit_button_grey, &button_font, "DEFAULT", settings_summary, buttons_save_back.size(), false));
	this->buttons_save_back.push_back(Button_option(window, sections[sections.size() - 1].shape(), &save_exit_button, &save_exit_button_grey, &button_font, "EXIT", settings_summary, buttons_save_back.size(), false));
}

int Settings_page::resolution_load_width()
{
	if(user_settings.res == 1)
		return 1280;
	else if (user_settings.res == 2)
		return 1600;
	else if (user_settings.res == 3)
		return 1920;
}

int Settings_page::resolution_load_height()
{
	if (user_settings.res == 1)
		return 1024;
	else if (user_settings.res == 2)
		return 900;
	else if (user_settings.res == 3)
		return 1080;
}

void Settings_page::settings(int volume)
{
	this->slider_sound.setVolume(15.f / 100 * volume);
	this->button_sound.setVolume(15.f / 100 * volume);
	this->save_sound.setVolume(15.f / 100 * volume);
	this->sound_choise.setVolume(15.f / 100 * volume);
}

void Settings_page::draw(sf::RenderWindow& window)
{
	window.draw(background_sprite_settings);
	window.draw(basic);
	for (int i = 0; i < sections.size(); i++)
	{
		sections[i].draw(window);
	}
	for (int i = 0; i < buttons_resolution.size(); i++)
	{
		buttons_resolution[i].draw(window);
	}
	for (int i = 0; i < buttons_diff.size(); i++)
	{
		buttons_diff[i].draw(window);
	}
	for (int i = 0; i < sliders_sound.size(); i++)
	{
		sliders_sound[i].draw(window);
	}
	for (int i = 0; i < yes_no_buttons.size(); i++)
	{
		yes_no_buttons[i].draw(window);
	}
	for (int i = 0; i < text_control.size(); i++)
	{
		text_control[i].draw(window);
	}
	for (int i = 0; i < buttons_save_back.size(); i++)
	{
		buttons_save_back[i].draw(window);
	}

	window.draw(save_back_rec);

	for (int i = 0; i < texts.size(); i++)
	{
		texts[i].draw(window);
	}
}

Settings_page::~Settings_page()
{
	delete settings_ini;
	settings_ini = nullptr;
}

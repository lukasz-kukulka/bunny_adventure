#include "Slider_score.hpp"

Slider_score::Slider_score(sf::RenderWindow& window, sf::RectangleShape& base, sf::Texture* up_texture, sf::Texture* mid_texture, sf::Texture* down_texture,
	sf::Texture* up_texture_press, sf::Texture* mid_texture_press, sf::Texture* down_texture_press, bool enable_slider)
{
	this->up_tex_press = up_texture_press;
	this->mid_tex_press = mid_texture_press;
	this->down_tex_press = down_texture_press;
	this->rec_base = base;
	this->up_tex = up_texture;
	this->mid_tex = mid_texture;
	this->down_tex = down_texture;
	this->slider_on_off = enable_slider;
	this->return_index = 0;
	this->objects_ini(window);
}

uint8_t Slider_score::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::MouseWheelMoved)
		{
			if (event.mouseWheel.delta < 0)
			{
				return 1;
			}
			else if (event.mouseWheel.delta > 0)
			{
				return 2;
			}
		}
		if (event.type == sf::Event::MouseWheelScrolled)
		{
			if (event.mouseWheel.delta < 0)
			{
				return 1;
			}
			else if (event.mouseWheel.delta > 0)
			{
				return 2;
			}

		}		
	}
		this->slider_shape.setOutlineThickness(2);
		if (mouse.x > slider_down.getPosition().x && mouse.x < slider_down.getPosition().x + slider_down.getGlobalBounds().width &&
			mouse.y > slider_down.getPosition().y && mouse.y < slider_down.getPosition().y + slider_down.getGlobalBounds().height &&
			sf::Mouse::isButtonPressed(sf::Mouse::Left) && slider_on_off == true && event.type != sf::Event::MouseButtonReleased)
		{
			this->slider_down.setTexture(*down_tex_press);
			return 1;
		}
		
		else if (mouse.x > slider_up.getPosition().x && mouse.x < slider_up.getPosition().x + slider_up.getGlobalBounds().width &&
			mouse.y > slider_up.getPosition().y && mouse.y < slider_up.getPosition().y + slider_up.getGlobalBounds().height &&
			sf::Mouse::isButtonPressed(sf::Mouse::Left) && slider_on_off == true)
		{
			this->slider_up.setTexture(*up_tex_press);
			return 2;
		}
		else if (mouse.x > slider_mid.getPosition().x && mouse.x < slider_mid.getPosition().x + slider_mid.getGlobalBounds().width &&
			mouse.y > slider_mid.getPosition().y && mouse.y < slider_mid.getPosition().y + slider_mid.getGlobalBounds().height &&
			sf::Mouse::isButtonPressed(sf::Mouse::Left) && slider_on_off == true)
		{
			this->slider_mid.setTexture(*mid_tex_press);
			this->slider_mid.setPosition(slider_mid.getPosition().x, mouse.y - slider_mid.getGlobalBounds().height / 2);
			if (slider_mid.getPosition().y + slider_mid.getGlobalBounds().height > move_slider_shape.getPosition().y + move_slider_shape.getGlobalBounds().height)
			{
				this->slider_mid.setPosition(slider_mid.getPosition().x, move_slider_shape.getPosition().y + move_slider_shape.getGlobalBounds().height - slider_mid.getGlobalBounds().height);
			}
			if (slider_mid.getPosition().y < move_slider_shape.getPosition().y)
			{
				this->slider_mid.setPosition(slider_mid.getPosition().x, move_slider_shape.getPosition().y);
			}
			return 3;
		}
		else
		{
			event.type == sf::Event::MouseButtonReleased;
			this->slider_mid.setTexture(*mid_tex);
			this->slider_down.setTexture(*down_tex);
			this->slider_up.setTexture(*up_tex);
			return 0;
		}
}

sf::RectangleShape Slider_score::position_mid_slider()
{
	return animation_space_single;
}

uint16_t Slider_score::slider_mid_position()
{
	return slider_mid.getPosition().y + slider_mid.getGlobalBounds().height / 2 - animation_space_single.getPosition().y;
}

void Slider_score::change_position_mid_slider(uint16_t pos_y)
{
	this->slider_mid.setPosition(slider_mid.getPosition().x, move_slider_shape.getPosition().y + pos_y);
}

void Slider_score::objects_ini(sf::RenderWindow& window)
{
	this->slider_shape.setSize(sf::Vector2f(52, rec_base.getSize().y - 4));
	this->slider_shape.setPosition(rec_base.getPosition().x + rec_base.getGlobalBounds().width, rec_base.getPosition().y);
	this->slider_shape.setFillColor(sf::Color(255, 255, 255, 88));
	this->slider_shape.setOutlineThickness(1);
	this->slider_shape.setOutlineColor(sf::Color(0, 0, 0, 111));

	this->slider_up.setTexture(*up_tex);
	this->slider_up.setPosition(slider_shape.getPosition().x, slider_shape.getPosition().y);

	this->slider_mid.setTexture(*mid_tex);
	this->slider_mid.setPosition(slider_up.getPosition().x, slider_shape.getPosition().y + slider_up.getGlobalBounds().height);

	this->slider_down.setTexture(*down_tex);
	this->slider_down.setPosition(slider_shape.getPosition().x, slider_shape.getPosition().y + slider_shape.getGlobalBounds().height - slider_down.getGlobalBounds().height - 2);

	this->move_slider_shape.setSize(sf::Vector2f(slider_shape.getSize().x, slider_down.getPosition().y - slider_up.getPosition().y - slider_up.getGlobalBounds().height));
	this->move_slider_shape.setPosition(slider_shape.getPosition().x, slider_up.getPosition().y + slider_up.getGlobalBounds().height);
	this->move_slider_shape.setFillColor(sf::Color(0, 0, 0, 0));
	this->move_slider_shape.setOutlineThickness(0);
	this->move_slider_shape.setOutlineColor(sf::Color(0, 0, 0, 255));

	this->animation_space_single.setSize(sf::Vector2f(move_slider_shape.getSize().x, move_slider_shape.getSize().y - slider_mid.getGlobalBounds().height));
	this->animation_space_single.setPosition(slider_shape.getPosition().x, slider_up.getPosition().y + slider_up.getGlobalBounds().height + slider_mid.getGlobalBounds().height / 2);
	this->animation_space_single.setFillColor(sf::Color(0, 0, 0, 0));
}


void Slider_score::draw(sf::RenderWindow& window)
{
	window.draw(slider_shape);
	window.draw(slider_down);
	window.draw(slider_mid);
	window.draw(slider_up);
	window.draw(rec_base);
	window.draw(move_slider_shape);
	window.draw(animation_space_single);
}

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
	this->objects_ini(window);
}

int Slider_score::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		/*if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
			}
		}*/
		if (mouse.x > slider_shape.getPosition().x && mouse.x < slider_shape.getPosition().x + slider_shape.getGlobalBounds().width &&
			mouse.y > slider_shape.getPosition().y && mouse.y < slider_shape.getPosition().y + slider_shape.getGlobalBounds().height)
		{
			this->slider_shape.setOutlineThickness(2);
			if (mouse.x > slider_down.getPosition().x && mouse.x < slider_down.getPosition().x + slider_down.getGlobalBounds().width &&
				mouse.y > slider_down.getPosition().y && mouse.y < slider_down.getPosition().y + slider_down.getGlobalBounds().height)
			{
				if (event.type == sf::Event::MouseButtonPressed && slider_on_off == true)
				{
					this->slider_down.setTexture(*down_tex_press);
					return 1;
				}
				if (event.type == sf::Event::MouseButtonReleased && slider_on_off == true)
				{
					objects_ini(window);
				}
			}
			if (mouse.x > slider_up.getPosition().x && mouse.x < slider_up.getPosition().x + slider_up.getGlobalBounds().width &&
				mouse.y > slider_up.getPosition().y && mouse.y < slider_up.getPosition().y + slider_up.getGlobalBounds().height)
			{
				if (event.type == sf::Event::MouseButtonPressed && slider_on_off == true)
				{
					this->slider_up.setTexture(*up_tex_press);
					return 2;
				}
				if (event.type == sf::Event::MouseButtonReleased && slider_on_off == true)
				{
					objects_ini(window);
				}
			}
			if (mouse.x > slider_mid.getPosition().x && mouse.x < slider_mid.getPosition().x + slider_mid.getGlobalBounds().width &&
				mouse.y > slider_mid.getPosition().y && mouse.y < slider_mid.getPosition().y + slider_mid.getGlobalBounds().height)
			{
				if (event.type == sf::Event::MouseButtonPressed && slider_on_off == true)
				{
					this->slider_mid.setTexture(*mid_tex_press);
					return 3;
				}
				if (event.type == sf::Event::MouseButtonReleased && slider_on_off == true)
				{
					objects_ini(window);
				}
			}
			if (event.type == sf::Event::MouseButtonReleased && slider_on_off == true)
			{
				objects_ini(window);
			}
		}
		else
		{
			objects_ini(window);
		}
	}
	return 0;
}

void Slider_score::objects_ini(sf::RenderWindow& window)
{
	this->slider_shape.setSize(sf::Vector2f(52, rec_base.getSize().y));
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
}

void Slider_score::draw(sf::RenderWindow& window)
{
	window.draw(slider_shape);
	window.draw(slider_down);
	window.draw(slider_mid);
	window.draw(slider_up);
	window.draw(rec_base);
	
}

#include "Yes_no_option.hpp"

Yes_no_option::Yes_no_option(sf::RenderWindow& window, sf::RectangleShape work_space, sf::Texture* yes_tex, sf::Texture* no_tex, sf::Font* font, int volume, int index, std::string text_title)
{
	this->work_space = work_space;
	this->yes_button_bool = true;
	this->no_button_bool = false;
	this->yes_tex = yes_tex;
	this->no_tex = no_tex;
	this->single_workspace.setSize(sf::Vector2f(work_space.getSize().x / volume, work_space.getSize().y));
	this->single_workspace.setPosition(work_space.getPosition().x + single_workspace.getSize().x * index, work_space.getPosition().y);
	this->single_workspace.setFillColor(sf::Color(255, 255, 255, 0));
	this->single_workspace.setOutlineThickness(1);
	this->single_workspace.setOutlineColor(sf::Color(0, 0, 0, 0));

	this->yes_button.setTexture(*yes_tex);
	this->yes_button.setScale(single_workspace.getGlobalBounds().width * 0.12 / yes_button.getGlobalBounds().width,
		single_workspace.getGlobalBounds().width * 0.12 / yes_button.getGlobalBounds().height);
	this->yes_button.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 4 - yes_button.getGlobalBounds().width / 2,
		single_workspace.getPosition().y + single_workspace.getGlobalBounds().height / 2 - yes_button.getGlobalBounds().height / 2);
	this->yes_button.setColor(sf::Color(255, 255, 255, 255));

	this->no_button.setTexture(*no_tex);
	this->no_button.setScale(single_workspace.getGlobalBounds().width * 0.12 / no_button.getGlobalBounds().width,
		single_workspace.getGlobalBounds().width * 0.12 / no_button.getGlobalBounds().height);
	this->no_button.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 4 * 3 - no_button.getGlobalBounds().width / 2,
		single_workspace.getPosition().y + single_workspace.getGlobalBounds().height / 2 - no_button.getGlobalBounds().height / 2);
	this->no_button.setColor(sf::Color(255, 255, 255, 255));

	this->on_text.setFont(*font);
	this->on_text.setString("ON");
	this->on_text.setCharacterSize(single_workspace.getGlobalBounds().height / 5);
	this->on_text.setFillColor(sf::Color(55, 177, 255, 255));
	this->on_text.setOutlineThickness(1);
	this->on_text.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 4 - on_text.getGlobalBounds().width / 2,
		single_workspace.getPosition().y + single_workspace.getGlobalBounds().height / 4 * 3 - on_text.getGlobalBounds().height / 2);

	this->off_text.setFont(*font);
	this->off_text.setString("OFF");
	this->off_text.setCharacterSize(single_workspace.getGlobalBounds().height / 5);
	this->off_text.setFillColor(sf::Color(55, 177, 255, 255));
	this->off_text.setOutlineThickness(1);
	this->off_text.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 4 * 3 - on_text.getGlobalBounds().width / 2,
		single_workspace.getPosition().y + single_workspace.getGlobalBounds().height / 4 * 3 - off_text.getGlobalBounds().height / 2);

	this->title.setFont(*font);
	this->title.setString(text_title);
	this->title.setCharacterSize(single_workspace.getGlobalBounds().height / 4);
	this->title.setFillColor(sf::Color(55, 177, 255, 255));
	this->title.setOutlineThickness(1);
	this->title.setOutlineColor(sf::Color(0, 0, 0, 255));
	this->title.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 2 - title.getGlobalBounds().width / 2, single_workspace.getPosition().y);
}

int Yes_no_option::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	if (mouse.x > yes_button.getPosition().x && mouse.x <  yes_button.getPosition().x + yes_button.getGlobalBounds().width &&
		mouse.y >  yes_button.getPosition().y && mouse.y < yes_button.getPosition().y + yes_button.getGlobalBounds().height)
	{
		this->on_text.setCharacterSize(single_workspace.getGlobalBounds().height / 3);
		this->on_text.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 4 - on_text.getGlobalBounds().width / 2,
			single_workspace.getPosition().y + single_workspace.getGlobalBounds().height / 4 * 3 - on_text.getGlobalBounds().height / 2);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (yes_button_bool == false)
			{
				this->yes_button.setTexture(*yes_tex);
				this->no_button.setTexture(*no_tex);
				this->yes_button_bool = true;
				this->no_button_bool = false;
			}
		}
	}
	else
	{
		this->on_text.setCharacterSize(single_workspace.getGlobalBounds().height / 5);
		this->on_text.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 4 - on_text.getGlobalBounds().width / 2,
			single_workspace.getPosition().y + single_workspace.getGlobalBounds().height / 4 * 3 - on_text.getGlobalBounds().height / 2);
	}

	if (mouse.x > no_button.getPosition().x && mouse.x <  no_button.getPosition().x + no_button.getGlobalBounds().width &&
				mouse.y >  no_button.getPosition().y && mouse.y < no_button.getPosition().y + no_button.getGlobalBounds().height)
	{
		this->off_text.setCharacterSize(single_workspace.getGlobalBounds().height / 3);
		this->off_text.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 4 * 3 - off_text.getGlobalBounds().width / 2,
			single_workspace.getPosition().y + single_workspace.getGlobalBounds().height / 4 * 3 - off_text.getGlobalBounds().height / 2);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (no_button_bool == false)
			{
				this->yes_button.setTexture(*no_tex);
				this->no_button.setTexture(*yes_tex);
				this->yes_button_bool = false;
				this->no_button_bool = true;
			}
		}
	}
	else
	{
		this->off_text.setCharacterSize(single_workspace.getGlobalBounds().height / 5);
		this->off_text.setPosition(single_workspace.getPosition().x + single_workspace.getGlobalBounds().width / 4 * 3 - off_text.getGlobalBounds().width / 2,
			single_workspace.getPosition().y + single_workspace.getGlobalBounds().height / 4 * 3 - off_text.getGlobalBounds().height / 2);
	}
		

	return 0;
}

void Yes_no_option::draw(sf::RenderWindow& window)
{
	window.draw(single_workspace);
	window.draw(yes_button);
	window.draw(no_button);
	window.draw(title);
	window.draw(on_text);
	window.draw(off_text);
}

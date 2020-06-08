#include "Exit.hpp"

Exit::Exit(sf::RenderWindow& window, sf::Texture* texture_bunny, sf::Texture* texture_cloud, sf::Texture* forest, sf::Font* font)
{
	this->transparent = 0;
	this->full_ask = "You are sure\nYou wanna close\nthis aplication?";
	this->single_ask = "";

	this->forest_tex.setTexture(*forest);
	this->forest_tex.setColor(sf::Color(188, 255, 255, transparent));
	this->forest_tex.setScale(window.getSize().x / forest_tex.getGlobalBounds().width,
		window.getSize().y / forest_tex.getGlobalBounds().height);
	this->forest_tex.setPosition(window.getSize().x / 2 - forest_tex.getGlobalBounds().width / 2, window.getSize().y / 2 - forest_tex.getGlobalBounds().height / 2);

	this->bunny_sprite.setTexture(*texture_bunny);
	this->bunny_sprite.setScale((forest_tex.getGlobalBounds().height / 2) / bunny_sprite.getGlobalBounds().height,
		(forest_tex.getGlobalBounds().height / 2) / bunny_sprite.getGlobalBounds().height);
	this->bunny_sprite.setPosition(forest_tex.getPosition().x + forest_tex.getGlobalBounds().width - bunny_sprite.getGlobalBounds().width,
		forest_tex.getPosition().y + forest_tex.getGlobalBounds().height - bunny_sprite.getGlobalBounds().height);
	this->bunny_sprite.setColor(sf::Color(188, 255, 255, transparent));
	
	this->cloud_sprite.setTexture(*texture_cloud);
	this->cloud_sprite.setScale((forest_tex.getGlobalBounds().height / 2) / cloud_sprite.getGlobalBounds().height,
		(forest_tex.getGlobalBounds().height / 2) / cloud_sprite.getGlobalBounds().height);
	this->cloud_sprite.setPosition(bunny_sprite.getPosition().x - cloud_sprite.getGlobalBounds().width, bunny_sprite.getPosition().y - cloud_sprite.getGlobalBounds().height);
	this->cloud_sprite.setColor(sf::Color(255, 255, 255, transparent));

	this->ask.setFont(*font);
	this->ask.setString(single_ask);
	this->ask.setCharacterSize(window.getSize().y / 23);
	this->ask.setPosition(cloud_sprite.getPosition().x + cloud_sprite.getGlobalBounds().width / 4, cloud_sprite.getPosition().y + cloud_sprite.getGlobalBounds().width / 5);
	this->ask.setFillColor(sf::Color(0, 0, 0, 255));
}

int Exit::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	if (transparent <= 251)
	{
		transparent = transparent + 4;
		this->cloud_sprite.setColor(sf::Color(255, 255, 255, transparent));
		this->bunny_sprite.setColor(sf::Color(188, 255, 255, transparent));
		this->forest_tex.setColor(sf::Color(188, 255, 255, transparent));
		return 0;
	}
	else
	{
		this->cloud_sprite.setColor(sf::Color(255, 255, 255, 255));
		this->bunny_sprite.setColor(sf::Color(188, 255, 255, 255));
		this->forest_tex.setColor(sf::Color(188, 255, 255, 255));
		return 5;
	}
}

int Exit::sub()
{
	single_ask = full_ask.substr(0, single_ask.size() + 1);
	this->ask.setString(single_ask);
	
	return 5;
}

int Exit::fox_pos_X_out()
{
	return bunny_sprite.getPosition().x;
}

int Exit::fox_pos_Y_out()
{
	return bunny_sprite.getPosition().y + bunny_sprite.getGlobalBounds().height/3*2;
}

void Exit::no_exit()
{
	this->transparent = 0;
	this->single_ask = " ";
	this->ask.setString(single_ask);
	this->cloud_sprite.setColor(sf::Color(255, 255, 255, transparent));
	this->bunny_sprite.setColor(sf::Color(188, 255, 255, transparent));
	this->forest_tex.setColor(sf::Color(188, 255, 255, transparent));
}

void Exit::draw(sf::RenderWindow& window)
{
	window.draw(forest_tex);
	window.draw(bunny_sprite);
	window.draw(cloud_sprite);
	window.draw(ask);
}


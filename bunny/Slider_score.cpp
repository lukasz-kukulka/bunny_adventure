#include "Slider_score.hpp"

Slider_score::Slider_score(sf::RenderWindow& window, sf::RectangleShape& base, sf::Texture* up, sf::Texture* mid, sf::Texture* down)
{

}

int Slider_score::system(sf::RenderWindow& window, sf::Vector2i mouse)
{
	return 0;
}

void Slider_score::objects_ini(sf::RenderWindow& window)
{
}

void Slider_score::draw(sf::RenderWindow& window)
{
	window.draw(slider_down);
	window.draw(slider_mid);
	window.draw(slider_up);
	window.draw(rec_base);
}

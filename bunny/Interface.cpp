#include "Interface.hpp"

Interface::Interface(sf::RenderWindow& window)
{
	background_tex.loadFromFile("Textures/Menu/background.jpg");
	tree_tex.loadFromFile("Textures/Menu/tree.png");
	small_tree_tex.loadFromFile("Textures/Menu/small_tree.png");
	green1_tex.loadFromFile("Textures/Menu/green1.png");
	green2_tex.loadFromFile("Textures/Menu/green2.png");
	green3_tex.loadFromFile("Textures/Menu/green3.png");
	house_tex.loadFromFile("Textures/Menu/house.png");
	rock_tex.loadFromFile("Textures/Menu/rock.png");
	road_tex.loadFromFile("Textures/Menu/road.png");
	dan_tex.loadFromFile("Textures/Menu/dan.png");
	
	//unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	win_size_X = window.getSize().x;
	win_size_Y = window.getSize().y / 2;
	std::uniform_int_distribution<int> third_plan_tree_x{ 100, win_size_X - 200 };
	std::uniform_int_distribution<int> third_plan_tree_y{ win_size_Y - 100, win_size_Y + 100 };

	background.push_back(Interface_elements(&background_tex, 0, 0, 1.0 / 1920 * window.getSize().x, 1.0 / 1920 * window.getSize().x));
	for (int i = 0; i < 25; i++)
	{
		tree.push_back(Interface_elements(&tree_tex, third_plan_tree_x(generator), third_plan_tree_y(generator), 1.0 / 1920 * window.getSize().x / 9, 1.0 / 1920 * window.getSize().x / 9));
	}
	

}

void Interface::draw(sf::RenderWindow& window)
{
	for (auto i : background)
		i.draw(window);
	for (auto i : tree)
		i.draw(window);
		
	
}

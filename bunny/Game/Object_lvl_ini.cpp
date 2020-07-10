#include "Object_lvl_ini.hpp"

Object_lvl_ini::Object_lvl_ini(sf::RenderWindow& window)
{
	this->tex001.loadFromFile("Game/Textures/Levels/001.png");
	this->tex002.loadFromFile("Game/Textures/Levels/002.png");
	this->tex003.loadFromFile("Game/Textures/Levels/003.png");
	this->tex004.loadFromFile("Game/Textures/Levels/004.png");
	this->tex005.loadFromFile("Game/Textures/Levels/005.png");
	this->tex006.loadFromFile("Game/Textures/Levels/006.png");
	this->tex007.loadFromFile("Game/Textures/Levels/007.png");
	this->tex008.loadFromFile("Game/Textures/Levels/008.png");
	this->tex009.loadFromFile("Game/Textures/Levels/009.png");
	this->tex010.loadFromFile("Game/Textures/Levels/010.png");
	this->tex011.loadFromFile("Game/Textures/Levels/011.png");
	this->tex012.loadFromFile("Game/Textures/Levels/012.png");
	this->tex013.loadFromFile("Game/Textures/Levels/013.png");
	this->tex014.loadFromFile("Game/Textures/Levels/014.png");
	this->tex015.loadFromFile("Game/Textures/Levels/015.png");
	this->tex016.loadFromFile("Game/Textures/Levels/016.png");
	this->tex017.loadFromFile("Game/Textures/Levels/017.png");
	this->tex018.loadFromFile("Game/Textures/Levels/018.png");
	this->tex020.loadFromFile("Game/Textures/Levels/020.png");
	this->tex021.loadFromFile("Game/Textures/Levels/021.png");
	this->tex022.loadFromFile("Game/Textures/Levels/022.png");
	this->tex023.loadFromFile("Game/Textures/Levels/023.png");
	this->tex024.loadFromFile("Game/Textures/Levels/024.png");
	this->tex101.loadFromFile("Game/Textures/Levels/101.png");
	this->tex102.loadFromFile("Game/Textures/Levels/102.png");
	this->tex103.loadFromFile("Game/Textures/Levels/103.png");
	this->tex104.loadFromFile("Game/Textures/Levels/104.png");
	this->tex105.loadFromFile("Game/Textures/Levels/105.png");
	this->tex106.loadFromFile("Game/Textures/Levels/106.png");
	this->tex107.loadFromFile("Game/Textures/Levels/107.png");
	this->tex108.loadFromFile("Game/Textures/Levels/108.png");
}

void Object_lvl_ini::create_objects(std::string path_lvl)
{
	no_line = 1;
	std::string line;
	std::fstream file;
	//std::cout << path_lvl << std::endl;
	file.open(path_lvl, std::ios::in);
	if (file.good() == false)
	{
		std::cout << "File not exist" << std::endl;
		exit(0);
	}
	while (getline(file, line))
	{
		if (no_line == 1)
		{
			std::cout << line << std::endl;
		}
		no_line++;
	}
	file.close();
}

void Object_lvl_ini::objects_ini(sf::RenderWindow& window)
{
}

#include "Object_lvl_ini.hpp"

Object_lvl_ini::Object_lvl_ini(sf::RenderWindow& window)
{
	this->add_bonus = true;
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
	this->tex111.loadFromFile("Game/Textures/Levels/111.png");
}

void Object_lvl_ini::create_objects(sf::RenderWindow& window, std::string path_lvl, sf::Vector2f size_board)
{
	no_line = 1;
	std::fstream file;
	file.open(path_lvl, std::ios::in);
	if (file.good() == false)
	{
		std::cout << "File not exist" << std::endl;
		exit(0);
	}
	while (getline(file, line))
	{
		no_tiles_row = 0;
			for (int i = 0; i < line.size(); i++)
			{
				if (line[i] != ',')
				{
					temp = line[i];
					temp.append(line, i+1 , 2);
					if (temp == "000")
					{
						no_tiles_row++;
					}
					if (temp == "001")
					{
						tiles_tex.push_back(Single_tile(window, &tex001, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "002")
					{
						tiles_tex.push_back(Single_tile(window, &tex002, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}						
					}
					else if (temp == "003")
					{
						tiles_tex.push_back(Single_tile(window, &tex003, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "004")
					{
						tiles_tex.push_back(Single_tile(window, &tex004, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "005")
					{
						tiles_tex.push_back(Single_tile(window, &tex005, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "006")
					{
						tiles_tex.push_back(Single_tile(window, &tex006, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "007")
					{
						tiles_tex.push_back(Single_tile(window, &tex007, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "008")
					{
						tiles_tex.push_back(Single_tile(window, &tex008, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "009")
					{
						tiles_tex.push_back(Single_tile(window, &tex009, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "010")
					{
						tiles_tex.push_back(Single_tile(window, &tex010, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "011")
					{
						tiles_tex.push_back(Single_tile(window, &tex011, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "012")
					{
						tiles_tex.push_back(Single_tile(window, &tex012, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "013")
					{
						tiles_tex.push_back(Single_tile(window, &tex013, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "014")
					{
						tiles_tex.push_back(Single_tile(window, &tex014, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "015")
					{
						tiles_tex.push_back(Single_tile(window, &tex015, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "016")
					{
						tiles_tex.push_back(Single_tile(window, &tex016, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "017")
					{
						tiles_tex.push_back(Single_tile(window, &tex017, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "018")
					{
						tiles_tex.push_back(Single_tile(window, &tex018, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
						if (checking_colistion_bonus_with_tile() == true)
						{
							initialization_structure(temp, tiles_tex[tiles_tex.size() - 1].position_tile());
						}
						else
						{
							this->add_bonus = true;
						}
					}
					else if (temp == "020")
					{
						tiles_tex.push_back(Single_tile(window, &tex020, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "021")
					{
						tiles_tex.push_back(Single_tile(window, &tex021, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "022")
					{
						tiles_tex.push_back(Single_tile(window, &tex022, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "023")
					{
						tiles_tex.push_back(Single_tile(window, &tex023, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "024")
					{
						tiles_tex.push_back(Single_tile(window, &tex024, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "101")
					{
						tiles_tex.push_back(Single_tile(window, &tex101, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "102")
					{
						tiles_tex.push_back(Single_tile(window, &tex102, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "103")
					{
						tiles_tex.push_back(Single_tile(window, &tex103, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "104")
					{
						tiles_tex.push_back(Single_tile(window, &tex104, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "105")
					{
						tiles_tex.push_back(Single_tile(window, &tex105, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "106")
					{
						tiles_tex.push_back(Single_tile(window, &tex106, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "107")
					{
						tiles_tex.push_back(Single_tile(window, &tex107, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "108")
					{
						tiles_tex.push_back(Single_tile(window, &tex108, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					else if (temp == "111")
					{
						tiles_tex.push_back(Single_tile(window, &tex111, sf::Vector2f(no_tiles_row * 100.0f, window.getSize().y - size_board.y + no_line * 100.0f), temp));
						no_tiles_row++;
					}
					i += 2;
				}
			}
		no_line++;
	}
	file.close();

}

sf::Sprite* Object_lvl_ini::shape(uint32_t index)
{
	return tiles_tex[index].shape_sprite();
}

void Object_lvl_ini::initialization_structure(std::string type, sf::Vector2i position_tile)
{
	struct_bonus_out.push_back(single_tile_out_for_bonus());
	struct_bonus_out[struct_bonus_out.size() - 1].id = struct_bonus_out.size() - 1;
	struct_bonus_out[struct_bonus_out.size() - 1].type = stoi(temp);
	struct_bonus_out[struct_bonus_out.size() - 1].x_position = position_tile.x;
	struct_bonus_out[struct_bonus_out.size() - 1].y_position = position_tile.y;
}

uint16_t Object_lvl_ini::no_tiles()
{
	return tiles_tex.size();
}

single_tile_out_for_bonus Object_lvl_ini::tiles_setings_to_bonus(uint16_t index)
{
	return struct_bonus_out[index];
}

bool Object_lvl_ini::checking_colistion_bonus_with_tile()
{
	for (uint16_t i = 0; i < tiles_tex.size(); i++)
	{
		if (tiles_tex[i].position_tile().x == tiles_tex[tiles_tex.size() - 1].position_tile().x && tiles_tex[i].position_tile().y == tiles_tex[tiles_tex.size() - 1].position_tile().y - 100)
		{
			this->add_bonus = false;
		}
	}
	return add_bonus;
}

uint16_t Object_lvl_ini::no_bonuses()
{
	return struct_bonus_out.size();
}

uint16_t Object_lvl_ini::tiles_type(uint16_t index)
{
	return tiles_tex[index].return_type_tile();
}

void Object_lvl_ini::draw(sf::RenderWindow& window)
{
	for (auto i : tiles_tex)
		i.draw(window);
}

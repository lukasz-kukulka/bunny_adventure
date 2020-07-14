#include "Test_LVL.hpp"

Test_LVL::Test_LVL(sf::RenderWindow& window) :lvl0(window)
{
    this->size_lvl.x = 10000;
    this->size_lvl.y = 2000;
    this->file_name = "Game/Textures/Levels/lvl0.txt";
    this->ini_object_true = true;
}

uint8_t Test_LVL::system()
{
    return 0;
}

void Test_LVL::objects_ini(sf::RenderWindow& window, sf::Vector2f size_board)
{
    if (ini_object_true == true)
    {
        lvl0.create_objects(window, file_name, sf::Vector2f(size_board));
        ini_object_true = false;
    }
}

sf::Vector2i Test_LVL::level_size()
{
    return sf::Vector2i(size_lvl);
}

void Test_LVL::draw(sf::RenderWindow& window)
{
    lvl0.draw(window);
}

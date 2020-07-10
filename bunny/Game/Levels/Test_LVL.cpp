#include "Test_LVL.hpp"

Test_LVL::Test_LVL(sf::RenderWindow& window) :lvl0(window)
{
    this->size_lvl.x = 10000;
    this->size_lvl.y = 2000;
    this->one_tile = 100;
    this->file_name = "Game/Textures/Levels/lvl0.txt";
    this->ini_object_true = true;
}

uint8_t Test_LVL::system()
{
    return 0;
}

void Test_LVL::objects_ini()
{
    if (ini_object_true == true)
    {
        this->lvl0.create_objects(file_name);
        ini_object_true = false;
    }
}

void Test_LVL::draw(sf::RenderWindow& window)
{

}

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

void Test_LVL::objects_ini(sf::RenderWindow& window, sf::Vector2i size_board)
{
    if (ini_object_true == true)
    {
        lvl0.create_objects(window, file_name, sf::Vector2f(size_board));
        ini_object_true = false;
    }
}

sf::Sprite* Test_LVL::tiles(uint32_t index)
{
   
    return lvl0.shape(index);
}

uint16_t Test_LVL::no_til()
{
    return lvl0.no_tiles();
}

single_tile_out_for_bonus Test_LVL::bonus_parameters(uint16_t index)
{
    return lvl0.tiles_setings_to_bonus(index);
}

uint16_t Test_LVL::bonus_size()
{
    return lvl0.no_bonuses();
}

uint16_t Test_LVL::tiles_type(uint16_t index)
{
    return lvl0.tiles_type(index);
}

void Test_LVL::draw(sf::RenderWindow& window)
{
    lvl0.draw(window);
}

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
    //std::cout << lvl0.no_tiles() << std::endl;
    
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

//uint8_t Test_LVL::bonus_size(uint8_t index)
//{
//    if (index == 1)
//    {
//        return bonus501;
//    }
//    else if (index == 2)
//    {
//        return bonus502;
//    }
//    else if (index == 3)
//    {
//        return bonus503;
//    }
//    else if (index == 4)
//    {
//        return bonus504;
//    }
//    else if (index == 5)
//    {
//        return bonus505;
//    }
//    else if (index == 6)
//    {
//        return bonus506;
//    }
//    else if (index == 7)
//    {
//        return bonus507;
//    }
//    else if (index == 8)
//    {
//        return bonus508;
//    }
//    else if (index == 9)
//    {
//        return bonus509;
//    }
//    else if (index == 10)
//    {
//        return bonus510;
//    }
//    else if (index == 11)
//    {
//        return bonus511;
//    }
//    else if (index == 12)
//    {
//        return bonus512;
//    }
//    else
//    {
//        return 0;
//    }
//}

void Test_LVL::draw(sf::RenderWindow& window)
{
    lvl0.draw(window);
}

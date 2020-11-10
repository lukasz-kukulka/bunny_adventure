#include "Pick_lvl_test.hpp"

Pick_lvl_test::Pick_lvl_test(sf::RenderWindow& window)
{
    this->bonus501 = 0; // widogrona wisz¹ce !!!!!!!!!!!! musi byc u góry
    this->bonus502 = 0; // burak
    this->bonus503 = 0; // kolko - lisc zielony
    this->bonus504 = 0; // marchewka
    this->bonus505 = 0; // grzyb
    this->bonus506 = 0; // kolko - spirala
    this->bonus507 = 0; // kolko - lisc rozowy
    this->bonus508 = 0; // kolko - kropla
    this->bonus509 = 0; // kolko - ogien
    this->bonus510 = 0; // kolko - trybik
    this->bonus511 = 0; // ziemniak
    this->bonus512 = 0; // kociolek

    //this->no_tiles = 0;
}

uint8_t Pick_lvl_test::system()
{
    return 0;
}

void Pick_lvl_test::initialize_pick_class(sf::RenderWindow& window)
{
    bonus_ini.push_back(Pick_items_ini(window));
}

void Pick_lvl_test::initialize_singe_bonus_item(sf::RenderWindow& window)
{
    for (uint8_t i = bonus501; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 1);
    }
    for (uint8_t i = bonus502; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 2);
    }
    for (uint8_t i = bonus503; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 3);
    }
    for (uint8_t i = bonus504; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 4);
    }
    for (uint8_t i = bonus505; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 5);
    }
    for (uint8_t i = bonus506; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 6);
    }
    for (uint8_t i = bonus507; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 7);
    }
    for (uint8_t i = bonus508; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 8);
    }
    for (uint8_t i = bonus509; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 9);
    }
    for (uint8_t i = bonus510; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 10);
    }
    for (uint8_t i = bonus511; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 11);
    }
    for (uint8_t i = bonus512; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 12);
    }
}

void Pick_lvl_test::bonus_parameters_ini(single_tile_out_for_bonus index)
{
    bonus_ini[0].bonus_parameters_ini(index);
}

//single_tile_out_for_bonus Pick_lvl_test::bonus_parameters_ini(uint16_t index)
//{
//    return single_tile_out_for_bonus();
//}

void Pick_lvl_test::draw(sf::RenderWindow& window)
{
    for (uint8_t i = 0; bonus_ini.size() > i; i++)
    {
        bonus_ini[i].draw(window);
    }
    //for (auto i : bonus_ini)
    //    i.draw(window);
}


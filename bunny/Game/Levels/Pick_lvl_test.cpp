#include "Pick_lvl_test.hpp"

Pick_lvl_test::Pick_lvl_test(sf::RenderWindow& window)
{
    this->bonus501 = 0; // widogrona wisz¹ce !!!!!!!!!!!! musi byc u góry
    this->bonus502 = 10; // burak 
    this->bonus503 = 10; // kolko - lisc zielony
    this->bonus504 = 10; // marchewka
    this->bonus505 = 10; // grzyb 
    this->bonus506 = 10; // kolko - spirala
    this->bonus507 = 10; // kolko - lisc rozowy
    this->bonus508 = 10; // kolko - kropla
    this->bonus509 = 10; // kolko - ogien
    this->bonus510 = 10; // kolko - trybik
    this->bonus511 = 10; // ziemniak
    this->bonus512 = 10; // kociolek
    this->bonus_quantity = bonus501 + bonus502 + bonus503 + bonus504 + bonus505 + bonus506 + bonus507 + bonus508 + bonus509 + bonus510 + bonus511 + bonus512;
    //this->no_tiles = 0;
}

uint8_t Pick_lvl_test::system(sf::RenderWindow& window)
{
    bonus_ini[0].system(window);
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
        bonus_ini[0].single_pick_items_ini(window, 1, "You pick up grapes");
    }
    for (uint8_t i = bonus502; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 2, "You pick up beetroot");
    }
    for (uint8_t i = bonus503; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 3, "You pick up green leaf");
    }
    for (uint8_t i = bonus504; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 4, "You pick up carrot");
    }
    for (uint8_t i = bonus505; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 5, "You pick up mushroom");
    }
    for (uint8_t i = bonus506; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 6, "You pick up helix");
    }
    for (uint8_t i = bonus507; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 7, "You pick up pink leaf");
    }
    for (uint8_t i = bonus508; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 8, "You pick up drop");
    }
    for (uint8_t i = bonus509; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 9, "You pick up fire");
    }
    for (uint8_t i = bonus510; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 10, "You pick up pinion");
    }
    for (uint8_t i = bonus511; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 11, "You pick up potato");
    }
    for (uint8_t i = bonus512; i > 0; i--)
    {
        bonus_ini[0].single_pick_items_ini(window, 12, "You pick up pot");
    }

    bonus_ini[0].bonus_quantity_in(bonus_quantity);
}

void Pick_lvl_test::bonus_parameters_ini(single_tile_out_for_bonus index)
{
    bonus_ini[0].bonus_parameters_ini(index);
}

void Pick_lvl_test::no_of_tiles(uint16_t index)
{
    bonus_ini[0].no_of_tiles_in(index);
    //std::cout << index + 1000 << std::endl;
}

sf::Sprite Pick_lvl_test::bonus_sprite_out(uint16_t index)
{
    return bonus_ini[0].bonus_sprite_out(index);
}

void Pick_lvl_test::player_mid_position(sf::Sprite* player)
{
    bonus_ini[0].player_mid_position(player);
}

uint16_t Pick_lvl_test::no_of_bonus_out()
{
    return bonus_ini[0].no_of_bonus_out();
}

void Pick_lvl_test::delete_bonus_elements(uint16_t element_index)
{
    bonus_ini[0].delete_bonus_ele(element_index);
    //std::cout << "test_level PICK        " << element_index << std::endl;
}

uint8_t Pick_lvl_test::type_item_bonus_out(uint16_t index)
{
    return bonus_ini[0].type_item_bonus_out(index);
}

bool Pick_lvl_test::confirm_bonus_delete()
{
    return bonus_ini[0].confirm_bonus_delete();
}

void Pick_lvl_test::view_ini(sf::View& view)
{
    bonus_ini[0].view_ini(view);
}

void Pick_lvl_test::delete_bonus_item_confirm(uint16_t index)
{
    bonus_ini[0].delete_bonus_item_confirm(index);
}

bool Pick_lvl_test::delete_bonus_item_confirm_out(uint16_t index)
{
    return bonus_ini[0].delete_bonus_item_confirm_out(index);
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


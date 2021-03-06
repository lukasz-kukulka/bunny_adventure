#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Menu/Option.hpp"
#include "Menu/Interface.hpp"
#include "Menu/Exit.hpp"
#include "Menu/Credits.hpp"
#include "Menu/Settings_page.hpp"
#include "Menu/Files_operations.hpp"
#include "Menu/Score_page.hpp"
#include "Game/Game_ini.hpp"
#include <stdlib.h>
#include <time.h> 

extern sf::Vector2i mouse;

int main()
{
    enum menu_option_enum
    {
        interface_menu_option = 0,
        game_option = 1,
        high_score_option = 2,
        setting_option = 3,
        credits_option = 4,
        close_option = 5,
    } menu_option;
    menu_option = interface_menu_option;

    int menu_option_temp;
    Files_operations res_load;
    uint16_t res_width = 1280, res_height = 1024;
    int8_t enabled_indicator = 99;
    bool music_play = true;
    if (res_load.load_from_settings(1) == 1)
    {
        res_width = 1280;
        res_height = 1024;
    }
    else if (res_load.load_from_settings(1) == 2)
    {
        res_width = 1600;
        res_height = 900;
    }
    else if (res_load.load_from_settings(1) == 3)
    {
        res_width = 1920;
        res_height = 1080;
    }

    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(res_width, res_height), "Bunny adventure");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
    sf::Texture texture;
    texture.loadFromFile("Menu/Textures/cursor.png");
    sf::Sprite sprite(texture);
    sf::Music music;
    music.openFromFile("Menu/Sound/Menu/music_menu.wav");
    music.setLoop(true);
    music.setVolume(10);
    Interface interface_option(window);
    Game_ini game_ini(window);
    Credits credits(window);
    Settings_page settings_page(window);
    Score_page score_page(window);
    Option* go_to_option{ nullptr };
    while (window.isOpen())
    {
        sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        music.setVolume(10.0f / 100 * res_load.load_from_settings(2));
        switch (menu_option)
        {
            case interface_menu_option:
            {
                if (enabled_indicator != 0)
                {
                    go_to_option = &interface_option;
                    enabled_indicator = 0;
                }
                break;
            }
        
            case game_option:
            {
                music.pause();
                if (enabled_indicator != 1)
                {
                    go_to_option = &game_ini;
                    enabled_indicator = 1;
                }
                sprite.setScale(0, 0);
                break;
                if (music.getVolume() <= 1)
                {
                    music.pause();
                }
                else
                {
                    music.setVolume(music.getVolume() - 0.4);
                }
                break;
            }

            case high_score_option:
            {
                if (enabled_indicator != 2)
                {
                    go_to_option = &score_page;
                    enabled_indicator = 2;
                }   
                break;
            }

            case setting_option:
            {
                if (enabled_indicator != 3)
                {
                    go_to_option = &settings_page;
                    enabled_indicator = 3;
                }
                break;
            }

            case credits_option:
            {
                if (enabled_indicator != 4)
                {
                    go_to_option = &credits;
                    enabled_indicator = 4;
                }
                break;
            }

            case close_option:
            {
                window.close();
                break;
            }

            default:
                break;
        }
        go_to_option->settings(res_load.load_from_settings(2));
        menu_option = menu_option_enum(go_to_option->system(window, mouse));
        
        if (res_load.load_from_settings(4) == true && music_play == true)
        {
            music.play();
            music_play = false;
        }
        else if (res_load.load_from_settings(4) == false)
        {
            music.pause();
            music_play = true;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        go_to_option->draw(window);
        window.draw(sprite);
        window.display();
    }
    go_to_option = nullptr;
    return 0;
}
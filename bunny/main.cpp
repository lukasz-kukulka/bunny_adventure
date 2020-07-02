#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Option.hpp"
#include "Interface.hpp"
#include "Exit.hpp"
#include "Credits.hpp"
#include "Settings_page.hpp"
#include "Files_operations.hpp"
#include "Score_page.hpp"
#include <stdlib.h>
#include <time.h> 
extern sf::Vector2i mouse;

int main()
{
    Files_operations res_load;
    int menu_option = 0, res_width = 1280, res_height = 1024;
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

    //Files_operations *res_load_new;
    //res_load_new = &res_load
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(res_width, res_height), "Bunny adventure");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
    sf::Texture texture;
    texture.loadFromFile("Textures/cursor.png");
    sf::Sprite sprite(texture);
    sf::Music music;
    music.openFromFile("Sound/Menu/music_menu.wav");
    music.setLoop(true);
    music.setVolume(10);
    Interface inter(window);
    Credits credits(window);
    Settings_page settings_page(window);
    Score_page score_page(window);
    Option* go_to_option = &inter;
    while (window.isOpen())
    {
        sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        music.setVolume(10.0f / 100 * res_load.load_from_settings(2));
        //std::cout << music.getVolume() << "\n";
        switch (menu_option)
        {
            case 0: //menu interface
            {
                go_to_option = &inter;
                menu_option = go_to_option->system(window, mouse);
                break;
            }
        
            case 1: //Game
            {
                if (music.getVolume() <= 1) //zwiekszy� volume
                {
                    music.pause();
                }
                else
                {
                    music.setVolume(music.getVolume() - 0.4);
                }
                break;
            }

            case 2: //High score
            {
                go_to_option = &score_page;
                menu_option = go_to_option->system(window, mouse);
                break;
            }

            case 3: //Settings
            {
                go_to_option = &settings_page;
                menu_option = go_to_option->system(window, mouse);
                break;
            }

            case 4: //Credits
            {
                go_to_option = &credits;
                menu_option = go_to_option->system(window, mouse);
                break;
            }

            case 5://Close
            {
                window.close();
                break;
            }

            default:
                break;
        }

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
        // Clear screen
        window.clear();
        go_to_option->draw(window);
        window.draw(sprite);
        window.display();
    }
    return 0;
}
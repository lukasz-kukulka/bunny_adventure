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

    Interface inter(window);
    Credits credits(window);
    Settings_page settings_page(window);
    Score_page score_page(window);
    Option* go_to_option = &inter;
    
    while (window.isOpen())
    {
        sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        //std::cout << menu_option << "  -  ";
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

        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        go_to_option->draw(window);
        //inter.draw(window);
        // Update the window
        window.draw(sprite);
        window.display();
    }
    return 0;
}
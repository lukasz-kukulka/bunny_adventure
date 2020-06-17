#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Option.hpp"
#include "Interface.hpp"
#include "Exit.hpp"
#include "Credits.hpp"
#include "Settings_page.hpp"
#include <stdlib.h>
#include <time.h> 
extern sf::Vector2i mouse;

int main()
{
    int menu_option = 0;
    srand(time(NULL));
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1800, 1080), "Bunny adventure");
    // Limit the framerate to 60 frames per second
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    sf::Texture texture;
    texture.loadFromFile("Textures/cursor.png");
    sf::Sprite sprite(texture);

    Interface inter(window);
    Credits credits(window);
    Settings_page settings_page(window);
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
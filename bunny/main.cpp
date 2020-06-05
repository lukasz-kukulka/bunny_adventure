#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Option.hpp"
#include "Interface.hpp"
extern sf::Vector2i mouse;

int main()
{
    unsigned __int8 menu_option = 0;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1280, 1000), "Bunny adventure");
    // Limit the framerate to 60 frames per second
    window.setFramerateLimit(60);
    
    Interface inter(window);
    Option* go_to_option = &inter;
    while (window.isOpen())
    {
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
   
        switch (menu_option)
        {
        case 0:
        {
            go_to_option = &inter;
            go_to_option->system(window, mouse);
            break;
        }
            
        default:
            break;
        }
        // Process events
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
        window.display();
    }
    return EXIT_SUCCESS;
}
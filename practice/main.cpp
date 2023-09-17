#include <SFML/Graphics.hpp>
#include "variables.h"


int main()
{
     // Create an instance of the TextureManager class
    TextureManager textureManager;

    // Access a texture by identifier
    sf::Texture& supplyTexture = textureManager.getTexture("new_supply");

    // Access a sprite by identifier
    sf::Sprite mainMenuSprite = textureManager.getSprite("main_menu");

    // Create a window
    sf::RenderWindow window(sf::VideoMode(1680, 1050), "Practice");
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw the main_menu sprite
        window.draw(mainMenuSprite);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
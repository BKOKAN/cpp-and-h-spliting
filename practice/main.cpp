#include <SFML/Graphics.hpp>
#include "variables.h"

int main()
{
    system("cd");
    // Create an instance of the TextureManager class
    TextureManager TM;

    TM.Manager();

    // Access a texture by identifier
    sf::Texture& main_menu_texture = TM.GetTexture(TextureID::MainMenu);

    // Access a sprite by identifier
    sf::Sprite main_menu_sprite = TM.GetSprite(TextureID::MainMenu);

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
        window.draw(main_menu_sprite);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
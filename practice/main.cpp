#include <SFML/Graphics.hpp>
#include "variables.h"

int main()
{

    system("cd");
    // Create an instance of the TextureManager class
    TextureManager TM;

    TM.Manager();
	static bool move_down = false;
	static bool move_up = false;
    
	// Access a texture by identifier
    sf::Texture main_menu_texture = TM.GetTexture("main_menu");
    sf::Texture select_ui_texture = TM.GetTexture("select_ui");

    // Access a sprite by identifier
    sf::Sprite main_menu_sprite = TM.GetSprite("main_menu");
    sf::Sprite select_ui_sprite = TM.GetSprite("select_ui");

	if (move_up == true)
	{
		// Handle moving up
		TM.GetSprite("select_ui").move(0, -50);
	}
	if (move_down == true)
	{
		// Handle moving down
		TM.GetSprite("select_ui").move(0, 50);
    }

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
            //controls(event, TM);

            if (event.type == sf::Event::EventType::KeyPressed)
                if (sf::Keyboard::Up)
                    move_up = true;
                else if (sf::Keyboard::Down)
                    move_down = true;
            
            if (event.type == sf::Event::EventType::KeyReleased)
                if (sf::Keyboard::Up)
                    move_up = false;
                else if (sf::Keyboard::Down)
                    move_down = false;
            
        }
        // Clear the window
        window.clear();

        // Draw the main_menu sprite
        window.draw(main_menu_sprite);
        window.draw(select_ui_sprite);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
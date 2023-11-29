#include <iostream>
#include <SFML/Graphics.hpp>
#include "variables.h"

int main()
{
    enum menu_state
    {
        begining,
        new_worker,
        existing_workers,
        janitor,
        finance,
        warehouse_manager,
        business_stats,
        income,
        expense,
        profit,
        overall_profit,
        new_supply,
        supply_list,
        wood,
        furniture
    };

    system("cd");
    // Create an instance of the TextureManager class
    TextureManager TM;

    TM.Manager();
   
	// Access a texture by identifier
    sf::Texture main_menu_texture = TM.GetTexture("main_menu");
    sf::Texture select_ui_texture = TM.GetTexture("select_ui");
    sf::Texture add_new_worker_texture = TM.GetTexture("add_new_worker");

    // Access a sprite by identifier
    sf::Sprite main_menu_sprite = TM.GetSprite("main_menu");
    sf::Sprite select_ui_sprite = TM.GetSprite("select_ui");
    sf::Sprite add_new_worker_sprite = TM.GetSprite("add_new_worker");

    bool moveup = false;
    bool movedown = false;
    bool confirm = false;
    bool goback = false;
      
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
            if (moveup)
            {
                // Handle moving up  
                float positionY = 200;
                select_ui_sprite.getPosition();
            if (select_ui_sprite.getPosition().y <= positionY)
                select_ui_sprite.setPosition(500, 600);
            else if (select_ui_sprite.getPosition().y > positionY) 
            
                    select_ui_sprite.move(0, -80);
            }
            else if (movedown)
            {
                float positionY = 500;
                // Handle moving down
             if (select_ui_sprite.getPosition().y >= positionY)
                select_ui_sprite.setPosition(500, 200);
             else if (select_ui_sprite.getPosition().y < positionY)
                     select_ui_sprite.move(0, +80);
            }
            if (event.type == sf::Event::EventType::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    // Handle moving up
                    moveup = true;
                    break;
               
                case sf::Keyboard::Down:
                    // Handle moving down
                    movedown = true;
                    break;
                case sf::Keyboard::Enter:
                    // Handle path comfrimmation
                    confirm = true;
                    break;
                case sf::Keyboard::Escape:
                    // Handle reversing path comfirmation
                    goback = true;
                    break;
                }
                

            }
            else if (event.type == sf::Event::EventType::KeyReleased)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    moveup = false;
                    break;

                case sf::Keyboard::Down:
                    movedown = false;
                    break;
                }
            }
        }
        // Clear the window
        window.clear();

        // Draw the main_menu sprite
        window.draw(main_menu_sprite);
        window.draw(select_ui_sprite);
        if (select_ui_sprite.getPosition().y == 200 && confirm)
           {
            window.draw(add_new_worker_sprite);
           if (goback) 
           {   
           window.draw(main_menu_sprite); 
           // window.draw(select_ui_sprite);
           // state machina
           }
           //else if()
           }

        // Display the contents of the window
        window.display();
    }

    return 0;
}
#include <iostream>
#include <SFML/Graphics.hpp>
#include "variables.h"

int main()
{
    enum menu_state
    {
        begining,
        new_worker_type,
        new_worker_type_reverse,
        new_worker_type_1,
        new_worker_type_1_reverse,
        new_worker_check,
        new_worker_check_1,
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
    
    int menu_state = 0;
    float positionY;

    system("cd");
    // Create an instance of the TextureManager class
    TextureManager TM;

    TM.Manager();
   
	// Access a texture by identifier
    sf::Texture main_menu_texture = TM.GetTexture("main_menu");
    sf::Texture select_ui_texture = TM.GetTexture("select_ui");
    sf::Texture select_ui_1_texture = TM.GetTexture("select_ui_1");
    sf::Texture add_new_worker_texture = TM.GetTexture("add_new_worker");
    sf::Texture check_mark_texture = TM.GetTexture("check_mark");
    sf::Texture check_mark_1_texture = TM.GetTexture("check_mark_1");

    // Access a sprite by identifier
    sf::Sprite main_menu_sprite = TM.GetSprite("main_menu");
    sf::Sprite select_ui_sprite= TM.GetSprite("select_ui");
    sf::Sprite select_ui_1_sprite = TM.GetSprite("select_ui_1");
    sf::Sprite add_new_worker_sprite = TM.GetSprite("add_new_worker");
    sf::Sprite check_mark_sprite = TM.GetSprite("check_mark");
    sf::Sprite check_mark_1_sprite = TM.GetSprite("check_mark_1");

    bool start = true;
    bool moveup = false;
    bool movedown = false;
    bool confirm = false;
    bool goback = false;
    bool confirm_type = false;
    bool confirm_type_1 = false;
    bool confirm_check = false;
    bool confirm_check_1 = false;
    bool confirm_mark_checker = false;
    bool confirm_mark_checker_1 = false;
      
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
                if(menu_state == begining)
                {
                    float positionY = 200;
                    select_ui_sprite.getPosition();
                    if (select_ui_sprite.getPosition().y <= 200)
                        select_ui_sprite.setPosition(500, 600);
                    else if (select_ui_sprite.getPosition().y > 200)
                        select_ui_sprite.move(0, -80);
                }
                else if (menu_state == new_worker_type)
                {
                  if (select_ui_1_sprite.getPosition().y < 235)
                      select_ui_1_sprite.move(0, -60);
                }
                else if (menu_state == new_worker_check)
                {
                    if (check_mark_sprite.getPosition().y <= 535)
                        check_mark_sprite.move(0, -40);
                }
                else if (menu_state == new_worker_type_1)
                {
                    if (select_ui_1_sprite.getPosition().y == 535)
                    {
                        select_ui_1_sprite.move(0, -60);
                        menu_state = new_worker_check_1;
                    }
                }
                else if (menu_state == new_worker_check_1)
                {
                    if (check_mark_1_sprite.getPosition().y == 720)
                    check_mark_1_sprite.move(0, -30);
                }
            }
            else if (movedown)
            {
                // Handle moving down
                if (menu_state == begining)
                {
                    if (select_ui_sprite.getPosition().y >= 600)
                        select_ui_sprite.setPosition(500, 200);
                    else if (select_ui_sprite.getPosition().y <= 600)
                             select_ui_sprite.move(0, +80);                    
                }
                else if (menu_state == new_worker_type)
                {
                    if (select_ui_1_sprite.getPosition().y <= 235)
                        select_ui_1_sprite.move(0, +60);
                }
                else if (menu_state == new_worker_check)
                {
                    if (check_mark_sprite.getPosition().y <= 535)
                        check_mark_sprite.move(0, +40);
                }
                else if (menu_state == new_worker_type_1)
                {
                    if (select_ui_1_sprite.getPosition().y == 535)
                    {
                        select_ui_1_sprite.move(0, +60);
                        menu_state = new_worker_check_1;
                    }
                }
                else if (menu_state == new_worker_check_1)
                {
                        if (check_mark_1_sprite.getPosition().y >= 660)
                        check_mark_1_sprite.move(0, +30);
                }
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
                    if (menu_state == new_worker_check && confirm)
                    {
                        confirm_check = true;
                        confirm_mark_checker = true;
                    }
                    if (menu_state == new_worker_check_1 && confirm)
                    {
                        confirm_check_1 = true;
                        confirm_mark_checker_1 = true;
                    }
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
                case sf::Keyboard::Enter:
                    confirm = false;
                    if (confirm_mark_checker_1)
                    {
                        confirm_check_1 = false;
                    }
                    if (confirm_mark_checker)
                    {
                        confirm_check = false;
                    }
                    break;
                case sf::Keyboard::Escape:                    
                    goback = false;
                    break;
                }
            }
        }
        // Clear the window
        window.clear();
        
        switch (menu_state)
        {
        case begining:
            window.clear();
            // Draw the main_menu sprite
            window.draw(main_menu_sprite);
            window.draw(select_ui_sprite);
            if (confirm && select_ui_sprite.getPosition().y == 200)
            {
                select_ui_1_sprite.setPosition(650, 175);
                menu_state = new_worker_type;
            }
            break;
        case new_worker_type:
            confirm = false;
            window.clear();
            window.draw(add_new_worker_sprite); 
            window.draw(select_ui_1_sprite);
            if (confirm_mark_checker)
                window.draw(check_mark_sprite);
            if (confirm_mark_checker && select_ui_1_sprite.getPosition().y > 235)
            {
                select_ui_1_sprite.setPosition(650, 535);
                window.draw(check_mark_sprite);
                menu_state = new_worker_type_1;
            }
            if (confirm_mark_checker_1)
                window.draw(check_mark_1_sprite);
            if (goback)
                menu_state = begining;
            else if (confirm && select_ui_1_sprite.getPosition().y == 175)
            {
                check_mark_sprite.setPosition(555, 395);
                confirm_type = true;
                menu_state = new_worker_check;
            }
            else if (confirm && select_ui_1_sprite.getPosition().y == 235)
            {
                check_mark_sprite.setPosition(555, 395);
                confirm_type = true;
                menu_state = new_worker_check;
            }
            else if (select_ui_1_sprite.getPosition().y > 235)
            {
                check_mark_sprite.setPosition(555,395);
                menu_state = new_worker_check;
            }
            else if (select_ui_1_sprite.getPosition().y < 175)
            {
                check_mark_1_sprite.setPosition(555, 720);
                menu_state = new_worker_type_reverse;
            }
            break;
        case new_worker_check:
            confirm = false;
            window.draw(add_new_worker_sprite);
            window.draw(check_mark_sprite);
            if (goback)
                menu_state = begining;
            if (confirm_mark_checker)
            {
                window.draw(check_mark_sprite);
                select_ui_1_sprite.setPosition(650, 535);
                menu_state = new_worker_type_1;
            }
            if (confirm_mark_checker_1)
            {
                window.draw(check_mark_1_sprite);
                select_ui_1_sprite.setPosition(650, 535);
                menu_state = new_worker_type_1;;
            }
            if (check_mark_sprite.getPosition().y > 535)
            {
                window.draw(check_mark_sprite);
                select_ui_1_sprite.setPosition(650, 535);
                menu_state = new_worker_type_1;
            }
            if (check_mark_sprite.getPosition().y == 535 && confirm_check)
            {                
                window.draw(check_mark_sprite);
                select_ui_1_sprite.setPosition(650, 535);
                menu_state = new_worker_type_1;
            }
            break;
        case new_worker_type_1:
            confirm = false;
            window.draw(add_new_worker_sprite);
            window.draw(select_ui_1_sprite);
            if (goback)
                menu_state = begining;
            if (confirm_mark_checker)
                window.draw(check_mark_sprite);
            if (confirm_mark_checker_1)
                window.draw(check_mark_1_sprite);   
            if (select_ui_1_sprite.getPosition().y == 535 && confirm)
            {
                check_mark_1_sprite.setPosition(555, 660);
                menu_state = new_worker_check_1;
            }
            if (select_ui_1_sprite.getPosition().y > 535)
            {
                check_mark_1_sprite.setPosition(555, 660);
                menu_state = new_worker_check_1;
            }
            break;
        case new_worker_check_1:
            confirm = false;
            window.draw(add_new_worker_sprite);
            if (confirm_mark_checker)
            {
                window.draw(check_mark_sprite);
            }
            window.draw(check_mark_1_sprite);
            if (goback)
                menu_state = begining;
            if (check_mark_1_sprite.getPosition().y > 720)
            {
                select_ui_1_sprite.setPosition(650, 175);
                menu_state = new_worker_type;
            }
            break;
        case new_worker_type_reverse:
            //reverse from new_worker_type to new_worker_check_1 and if moveup go from bottom screen upwords
            window.draw(add_new_worker_sprite);
            window.draw(check_mark_1_sprite);
            break;
        }

        // Display the contents of the window
        window.display();
    }

    return 0;
}
#include <iostream>
#include <Window.hpp>
#include <Graphics.hpp>
#include <Graphics/RenderWindow.hpp>
#include <cstdlib>
#include <ctime>
#include "variables.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(1680,1050), "Practice");
	window.setFramerateLimit(144);
	window.setActive();
	while (window.isOpen())

	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			{
				void textures(sf::Texture, sf::Sprite);
				void controls(sf::Event event);
				window.draw(sprite_main_menu);
			}
		}
	}
}
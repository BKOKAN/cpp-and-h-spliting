#include <iostream>
#include <Graphics.hpp>
#include <Graphics/RenderWindow.hpp>

void textures(sf::Texture, sf::Sprite)
{
	sf::Texture texture_main_menu;
	sf::Texture texture_add_new_worker;
	sf::Texture texture_existing_workers;
	sf::Texture texture_worker_options;
	sf::Texture texture_stats;
	sf::Texture texture_supply_storage;
	sf::Texture texture_exit;

	std::string projectFolderPath = "./";
	std::string main_menu_path = projectFolderPath + "resources/main_menu.png";
	texture_main_menu.loadFromFile(main_menu_path);
	std::string add_new_worker_path = projectFolderPath + "resources/texture_add_new_worker";
	texture_add_new_worker.loadFromFile(add_new_worker_path);
	std::string existing_workers_path = projectFolderPath + "resources/texture_existing_workers";
	texture_existing_workers.loadFromFile(existing_workers_path);
	std::string worker_options_path = projectFolderPath + "resources/texture_worker_options";
	texture_worker_options.loadFromFile(worker_options_path);
	std::string stats_path = projectFolderPath + "resources/texture_stats";
	texture_stats.loadFromFile(stats_path);
	std::string supply_storage_path = projectFolderPath + "resources/texture_supply_storage";
	texture_supply_storage.loadFromFile(supply_storage_path);
	std::string exit_path = projectFolderPath + "resources/texture_exit";
	texture_exit.loadFromFile(exit_path);

	sf::Sprite sprite_main_menu;
	sf::Sprite sprite_add_new_member;
	sf::Sprite sprite_existing_workers;
	sf::Sprite sprite_worker_options;
	sf::Sprite sprite_stats;
	sf::Sprite sprite_supply_storage;
	sf::Sprite sprite_exit;

	sprite_main_menu.setTexture(texture_main_menu);
	sprite_main_menu.setPosition(0, 0);
	sprite_add_new_member.setTexture(texture_add_new_worker);
	sprite_add_new_member.setPosition(0, 0);
	sprite_existing_workers.setTexture(texture_existing_workers);
	sprite_existing_workers.setPosition(0, 0);
	sprite_worker_options.setTexture(texture_worker_options);
	sprite_stats.setTexture(texture_stats);
	sprite_supply_storage.setTexture(texture_supply_storage);
	sprite_exit.setTexture(texture_exit);

}

void controls(sf::Event event)
{
	bool move_down = false;
	bool move_up = false;

	if (move_up)
	{

	}
	if (move_down)
	{

	}

	if (event.type == event.KeyPressed)
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
		{
		move_up = true;
		}
		break;
		case sf::Keyboard::Down:
		{
		move_down = true;
		}
		break;
		}
}

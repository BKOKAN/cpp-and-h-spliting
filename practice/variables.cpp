#include <iostream>
#include <Graphics.hpp>
#include <Graphics/RenderWindow.hpp>

class TextureManager
{
private:
	std::vector<sf::Texture> textures;
	std::map<sf::String, sf::Sprite> sprites;

public:
	void LoadTexture()
	{
		sf::Texture texture_select_ui;
		textures.push_back(texture_select_ui);
		sf::Texture texture_main_menu;
		textures.push_back(texture_main_menu);
		sf::Texture texture_add_new_worker;
		textures.push_back(texture_add_new_worker);
		sf::Texture texture_existing_workers;
		textures.push_back(texture_existing_workers);
		sf::Texture texture_worker_options;
		textures.push_back(texture_worker_options);
		sf::Texture texture_stats;
		textures.push_back(texture_stats);
		sf::Texture texture_add_new_supply;
		textures.push_back(texture_add_new_supply);
		sf::Texture texture_supply_storage;
		textures.push_back(texture_supply_storage);
		
		std::string projectFolderPath = "./";
		std::string resourcesfolder = projectFolderPath + "/resources";
		std::string select_ui_path = projectFolderPath + "resources/select_ui.png";
		texture_select_ui.loadFromFile(select_ui_path);
		std::string main_menu_path = projectFolderPath + "resources/main_menu.png";
		texture_main_menu.loadFromFile(main_menu_path);
		std::string add_new_worker_path = projectFolderPath + "resources/texture_add_new_worker.png";
		texture_add_new_worker.loadFromFile(add_new_worker_path);
		std::string existing_workers_path = projectFolderPath + "resources/texture_existing_workers.png";
		texture_existing_workers.loadFromFile(existing_workers_path);
		std::string worker_options_path = projectFolderPath + "resources/texture_worker_options.png";
		texture_worker_options.loadFromFile(worker_options_path);
		std::string stats_path = projectFolderPath + "resources/texture_stats.png";
		texture_stats.loadFromFile(stats_path);
		std::string supply_storage_path = projectFolderPath + "resources/texture_supply_storage.png";
		texture_supply_storage.loadFromFile(supply_storage_path);
		std::string add_new_supply_path = projectFolderPath + "resources/add_new_supply.png";
		texture_add_new_supply.loadFromFile(add_new_supply_path);
		
		sf::Sprite sprite_select_ui;
		sf::Sprite sprite_main_menu;
		sf::Sprite sprite_add_new_worker;
		sf::Sprite sprite_existing_workers;
		sf::Sprite sprite_worker_options;
		sf::Sprite sprite_stats;
		sf::Sprite sprite_supply_storage;
		sf::Sprite sprite_add_new_supply;

		sprite_select_ui.setTexture(texture_select_ui);
		sprite_select_ui.setPosition(0, 0);
		sprite_main_menu.setTexture(texture_main_menu);
		sprite_main_menu.setPosition(0, 0);
		sprite_add_new_worker.setTexture(texture_add_new_worker);
		sprite_add_new_worker.setPosition(0, 0);
		sprite_existing_workers.setTexture(texture_existing_workers);
		sprite_existing_workers.setPosition(0, 0);
		sprite_worker_options.setTexture(texture_worker_options);
		sprite_worker_options.setPosition(0, 0);
		sprite_stats.setTexture(texture_stats);
		sprite_stats.setPosition(0, 0);
		sprite_supply_storage.setTexture(texture_supply_storage);
		sprite_supply_storage.setPosition(0, 0);
		sprite_add_new_supply.setTexture(texture_add_new_supply);
		sprite_add_new_supply.setPosition(0, 0);
				
		sprites["select_ui"] = sprite_select_ui;
		sprites["main_menu"] = sprite_main_menu;
		sprites["add_new_worker"] = sprite_add_new_worker;
		sprites["existing_workers"] = sprite_existing_workers;
		sprites["worker_options"] = sprite_worker_options;
		sprites["worker_stats"] = sprite_stats;
		sprites["supply_storage"] = sprite_supply_storage;
		sprites["new_supply"] = sprite_add_new_supply;
		}
};
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

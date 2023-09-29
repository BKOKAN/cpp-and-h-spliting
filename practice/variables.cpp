#include "variables.h"
#include <string>
#include <iostream>
#include <Graphics.hpp>
#include <vector>

TextureManager::TextureManager() {
	// Initialize member variables or perform setup here

	sf::Texture texture_select_ui;
	texture_select_ui.loadFromFile("select_ui_path");
	textures.push_back(texture_select_ui);
    sf::Sprite sprite_select_ui;
	sprite_select_ui.setTexture(texture_select_ui);
	sprites["select_ui"] = sprite_select_ui;

	sf::Texture texture_main_menu;
	texture_main_menu.loadFromFile("main_menu_path");
	textures.push_back(texture_main_menu);
	sf::Sprite sprite_main_menu;
	sprite_main_menu.setTexture(texture_main_menu);
	sprites["main_menu"] = sprite_main_menu;
}

void TextureManager::Manager()
{
	
	// Set name for textures
	sf::Texture texture_select_ui;
	sf::Texture texture_main_menu;
	sf::Texture texture_add_new_worker;
	sf::Texture texture_existing_workers;
	sf::Texture texture_worker_options;
	sf::Texture texture_stats;
	sf::Texture texture_add_new_supply;
	sf::Texture texture_supply_storage;

	// Push those texture out of the function
	textures.push_back(texture_select_ui);
	textures.push_back(texture_main_menu);
	textures.push_back(texture_add_new_worker);
	textures.push_back(texture_existing_workers);
	textures.push_back(texture_worker_options);
	textures.push_back(texture_stats);
	textures.push_back(texture_add_new_supply);
	textures.push_back(texture_supply_storage);

	std::string projectFolderPath = "./"; // Direct path to the project file
	std::string ResourcesFolder = projectFolderPath + "/resources";
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

	sf::Sprite sprite_select_ui; // Sprite name
	sf::Sprite sprite_main_menu;
	sf::Sprite sprite_add_new_worker;
	sf::Sprite sprite_existing_workers;
	sf::Sprite sprite_worker_options;
	sf::Sprite sprite_stats;
	sf::Sprite sprite_supply_storage;
	sf::Sprite sprite_add_new_supply;

	// Setting textures for sprites and position
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

	// Set the sprites in the map so its survives out side of the function
	sprites["select_ui"] = sprite_select_ui;
	sprites["main_menu"] = sprite_main_menu;
	sprites["add_new_worker"] = sprite_add_new_worker;
	sprites["existing_workers"] = sprite_existing_workers;
	sprites["worker_options"] = sprite_worker_options;
	sprites["worker_stats"] = sprite_stats;
	sprites["supply_storage"] = sprite_supply_storage;
	sprites["new_supply"] = sprite_add_new_supply;
	
};

sf::Texture& TextureManager::GetTexture(TextureID identifier)
{
	
	int index = static_cast<int>(identifier);
	if (index >= 0 && index < textures.size())
	{
		return textures[index];
	}

	// Handle error: Return a default texture (main_menu)
	return textures[1];
	
};

sf::Sprite& TextureManager::GetSprite(TextureID identifier)
{
	
	std::string identifierStr;

	switch (identifier)
	{
	case TextureID::SelectUI:
		identifierStr = "select_ui";
		break;
	case TextureID::MainMenu:
		identifierStr = "main_menu";
		break;
	case TextureID::AddNewWorker:
		identifierStr = "add_new_worker";
		break;
	case TextureID::ExistingWorkers:
		identifierStr = "existing_workers";
		break;
	case TextureID::WorkerOptions:
		identifierStr = "worker_options";
		break;
	case TextureID::Stats:
		identifierStr = "worker_stats";
		break;
	case TextureID::SupplyStorage:
		identifierStr = "supply_storage";
		break;
	case TextureID::NewSupply:
		identifierStr = "new_supply";
		break;
	}

	if (sprites.find(identifierStr) != sprites.end())
	{
		return sprites[identifierStr];
	}

	static sf::Sprite sprite_main_menu;
	return sprite_main_menu;
	
};
/*
void controls(sf::Event event, TextureManager& textureManager) {
	static bool move_down = false;
	static bool move_up = false;

	if (move_up) {
		// Handle moving up
	}
	if (move_down) {
		// Handle moving down
	}

	if (event.type == sf::Event::EventType::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::Up:
			move_up = true;
			break;
		case sf::Keyboard::Down:
			move_down = true;
			break;
		}
	}
}
*/



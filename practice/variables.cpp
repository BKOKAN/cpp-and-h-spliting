#include "variables.h"
#include <string>
#include <iostream>
#include <Graphics.hpp>
#include <vector>
#include <map>

std::string projectFolderPath = "./"; // Direct path to the project file
std::string ResourcesFolder = projectFolderPath + "resources";

TextureManager::TextureManager() {
	// Initialize member variables or perform setup here

	// Load and store textures
	LoadTexture("select_ui", ResourcesFolder + "/select_ui.png");
	LoadTexture("main_menu", ResourcesFolder + "/main_menu.png");
	// Add more textures here as needed
}

void TextureManager::LoadTexture(const std::string& identifier, const std::string& filePath) {
	sf::Texture texture;
	if (texture.loadFromFile(filePath)) {
		textures[identifier] = texture;
	}
	else {
		std::cerr << "Failed to load texture: " << filePath << std::endl;
	}
}

sf::Texture& TextureManager::GetTexture(const std::string& identifier) {
	if (textures.find(identifier) != textures.end()) {
		return textures[identifier];
	}

	// Handle error: Return a default texture (e.g., main_menu)
	return textures["main_menu"];
}

sf::Sprite& TextureManager::GetSprite(const std::string& identifier) {
	if (sprites.find(identifier) != sprites.end()) {
		return sprites[identifier];
	}

	// Handle error: Return a default sprite (e.g., main_menu)
	return sprites["main_menu"];
}

// Call this function to initialize and manage textures and sprites
void TextureManager::Manager() {
	// Load additional textures and set sprites here
	LoadTexture("add_new_worker", projectFolderPath + "resources/texture_add_new_worker.png");
	LoadTexture("existing_workers", projectFolderPath + "resources/texture_existing_workers.png");
	LoadTexture("worker_options", projectFolderPath + "resources/texture_worker_options.png");
	LoadTexture("stats", projectFolderPath + "resources/texture_stats.png");
	LoadTexture("supply_storage", projectFolderPath + "resources/texture_supply_storage.png");
	LoadTexture("new_supply", projectFolderPath + "resources/add_new_supply.png");

	// Create and set sprites for the newly loaded textures
	SetSprite("add_new_worker", "add_new_worker", 0, 0);
	SetSprite("existing_workers", "existing_workers", 0, 0);
	SetSprite("worker_options", "worker_options", 0, 0);
	SetSprite("stats", "worker_stats", 0, 0);
	SetSprite("supply_storage", "supply_storage", 0, 0);
	SetSprite("new_supply", "new_supply", 0, 0);
}

void TextureManager::SetSprite(const std::string& identifier, const std::string& textureIdentifier, float x, float y) {
	if (textures.find(textureIdentifier) != textures.end()) {
		sf::Sprite sprite;
		sprite.setTexture(textures[textureIdentifier]);
		sprite.setPosition(x, y);
		sprites[identifier] = sprite;
	}
	else {
		std::cerr << "Texture not found: " << textureIdentifier << std::endl;
	}
}
/*
TextureManager::TextureManager() {
	// Initialize member variables or perform setup here
	std::string projectFolderPath = "./"; // Direct path to the project file
	std::string ResourcesFolder = projectFolderPath + "resources";
	
	sf::Texture texture_select_ui;
	texture_select_ui.loadFromFile(ResourcesFolder + "/select_ui.png");
	textures.push_back(texture_select_ui);
    sf::Sprite sprite_select_ui;
	sprite_select_ui.setTexture(texture_select_ui);
	sprites["select_ui"] = sprite_select_ui;

	sf::Texture texture_main_menu;
	texture_main_menu.loadFromFile(ResourcesFolder + "/main_menu.png" );
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
	std::string ResourcesFolder = projectFolderPath + "resources";
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



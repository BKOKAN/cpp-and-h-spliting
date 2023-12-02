#include "variables.h"
#include <string>
#include <iostream>
#include <Graphics.hpp>
#include <vector>
#include <map>

enum identifier 
{
	select_ui,
	main_menu,
	add_new_worker,
	existing_worker,
	worker_options,
	stats,
	supply_storage,
	new_supply,
	check_mark,
	check_mark_1
};

TextureManager::TextureManager() 
{
	std::string projectFolderPath = "./"; // Direct path to the project file
	std::string ResourcesFolder = projectFolderPath + "resources";
	// Load and store textures
	LoadTexture("select_ui", ResourcesFolder + "/select_ui.png");
	LoadTexture("select_ui_1", ResourcesFolder + "/select_ui_1.png");
	LoadTexture("main_menu", ResourcesFolder + "/main_menu.png");
	LoadTexture("add_new_worker", ResourcesFolder + "/add_new_worker.png");
	LoadTexture("existing_workers", ResourcesFolder + "/existing_workers.png");
	LoadTexture("worker_options", ResourcesFolder + "/worker_options.png");
	LoadTexture("stats", ResourcesFolder + "/stats.png");
	LoadTexture("supply_storage", ResourcesFolder + "/supply_storage.png");
	LoadTexture("new_supply", ResourcesFolder + "/new_supply.png");
	LoadTexture("check_mark", ResourcesFolder + "/check_mark.png");
	LoadTexture("check_mark_1", ResourcesFolder + "/check_mark.png");
	// Add more textures here as needed
}

void TextureManager::LoadTexture(const std::string& identifier, const std::string& filePath) 
{
	sf::Texture texture;
	if (texture.loadFromFile(filePath)) 
	{
		textures[identifier] = texture;
	}
	else 
	{
		std::cerr << "Failed to load texture: " << filePath << std::endl;
	}
}

sf::Texture& TextureManager::GetTexture(const std::string& identifier) 
{
	if (textures.find(identifier) != textures.end()) 
	{
		return textures[identifier];
	}

	// Handle error: Return a default texture (e.g., main_menu)
	return textures[identifier];
}

sf::Sprite& TextureManager::GetSprite(const std::string& identifier) 
{
	if (sprites.find(identifier) != sprites.end()) 
	{
		return sprites[identifier];
	}

	// Handle error: Return a default sprite (e.g., main_menu)
	return sprites[identifier];
}

// Call this function to initialize and manage textures and sprites
void TextureManager::Manager() 
{
	std::string projectFolderPath = "./"; // Direct path to the project file
	std::string ResourcesFolder = projectFolderPath + "resources"; // Direct path to the resource folder
	// Load additional textures and set sprites here
	LoadTexture("select_ui", projectFolderPath + "resources/select_ui.png");
	LoadTexture("select_ui_1", projectFolderPath + "resources/select_ui_1.png");
	LoadTexture("add_new_worker", projectFolderPath + "resources/add_new_worker.png");
	LoadTexture("existing_workers", projectFolderPath + "resources/existing_workers.png");
	LoadTexture("worker_options", projectFolderPath + "resources/worker_options.png");
	LoadTexture("stats", projectFolderPath + "resources/stats.png");
	LoadTexture("supply_storage", projectFolderPath + "resources/supply_storage.png");
	LoadTexture("new_supply", projectFolderPath + "resources/add_new_supply.png");
	LoadTexture("main_menu", projectFolderPath + "resources/main_menu.png");
	LoadTexture("check_mark", projectFolderPath + "resources/check_mark.png");
	LoadTexture("check_mark_1", projectFolderPath + "resources/check_mark.png");

	// Create and set sprites for the newly loaded textures ex. SetSprite("Sprite", "Sprite", PositionX, PositionY, ScaleX, ScaleY)
	SetSprite("select_ui", "select_ui", 500, 200, 0.35, 0.1);
	SetSprite("select_ui_1", "select_ui_1", 650, 175, 0.3, 0.05);
	SetSprite("add_new_worker", "add_new_worker", 0, 0, 1, 1);
	SetSprite("existing_workers", "existing_workers", 0, 0, 1 ,1);
	SetSprite("worker_options", "worker_options", 0, 0, 1 ,1);
	SetSprite("stats", "stats", 0, 0, 1, 1);
	SetSprite("supply_storage", "supply_storage", 0, 0, 1, 1);
	SetSprite("new_supply", "new_supply", 0, 0, 1, 1);
	SetSprite("main_menu", "main_menu", 0, 0, 1, 1);
	SetSprite("check_mark", "check_mark", 555, 395 ,1, 1);
	SetSprite("check_mark_1", "check_mark_1", 555, 660, 1, 1);
}

void TextureManager::SetSprite(const std::string& identifier, const std::string& textureIdentifier, float positionX, float positionY, float scaleX, float scaleY) 
{
	if (textures.find(textureIdentifier) != textures.end()) {
		sf::Sprite sprite;
		sprite.setTexture(textures[textureIdentifier]);
		sprite.setPosition(positionX, positionY);
		sprite.setScale(scaleX, scaleY); // Set scale for the sprite
		sprites[identifier] = sprite;
	}
	else {
		std::cerr << "Texture not found: " << textureIdentifier << std::endl;
	}
}

/*
void controls(sf::Event event, TextureManager& Manager)
{
	bool moveup = false;
	bool movedown = false;
	if (moveup)
	{
		// Handle moving up
		Manager.GetSprite("select_ui").move( + 0,  - 50);
	}
	if (movedown)
	{
		// Handle moving down
		Manager.GetSprite("select_ui").move( + 0,  + 50);
	}
    if(event.type == sf::Event::EventType::KeyPressed) 
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
*/

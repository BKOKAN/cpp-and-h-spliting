#include <iostream>
#include <Graphics.hpp>
#include <Graphics/RenderWindow.hpp>

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

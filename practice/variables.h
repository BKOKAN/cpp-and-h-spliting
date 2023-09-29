#ifndef VARIABLES_H
#define VARIABLES_H

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

enum TextureID {
    SelectUI,
    MainMenu,
    AddNewWorker,
    ExistingWorkers,
    WorkerOptions,
    Stats,
    SupplyStorage,
    NewSupply
};

class TextureManager {
private:
    std::vector<sf::Texture> textures;
    std::map<std::string, sf::Sprite> sprites;

public:
    TextureManager(); // Constructor
    void Manager();
    sf::Texture& GetTexture(TextureID identifier);
    sf::Sprite& GetSprite(TextureID identifier);
};

#endif

#ifndef VARIABLES_H
#define VARIABLES_H

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

enum TextureID {};

class TextureManager {
private:

    std::map<std::string, sf::Sprite> sprites;
    std::map<std::string, sf::Texture> textures;

public:
    TextureManager(); // Constructor
    void LoadTexture(const std::string& identifier, const std::string& filePath);
    void Manager();
    sf::Texture& GetTexture(const std::string& identifier);
    sf::Sprite& GetSprite(const std::string& identifier);
    void SetSprite(const std::string& identifier, const std::string& textureIdentifier, float positionX, float positionY, float scaleX, float scaleY);
};

/*
void controls(sf::Event event, TextureManager& textureManager);
*/
#endif

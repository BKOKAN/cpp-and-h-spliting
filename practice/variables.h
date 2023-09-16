#ifndef VARIABLES_H
#define VARIABLES_H

#include <SFML/Graphics.hpp>

class TextureManager {
private:
    std::vector<sf::Texture> textures;
    std::map<sf::String, sf::Sprite> sprites;

public: 
    // Function to load textures and create sprites
    void Manager();

    // Get a texture by identifier
    sf::Texture& getTexture(const sf::String& identifier);

    // Get a sprite by identifier
    sf::Sprite& getSprite(const sf::String& identifier);
};

void controls(sf::Event event, TextureManager& textureManager);

#endif

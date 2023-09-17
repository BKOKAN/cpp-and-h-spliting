#ifndef VARIABLES_H
#define VARIABLES_H

#include <SFML/Graphics.hpp>

class TextureManager {
private:
    std::vector<sf::Texture> textures;
    std::map<std::string, sf::Sprite> sprites;

public:
    void Manager();
	sf::Texture& GetTexture(TextureID identifier);
	sf::Sprite& GetSprite(TextureID identifier);
};

void controls(sf::Event event, TextureManager& textureManager);


#endif

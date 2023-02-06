#include <SFML/Graphics.hpp>
#include <iostream>

class Background {
    sf::Texture texture;
public:
    sf::Sprite sprite;
    Background(const std::string filePath) {
        if (!texture.loadFromFile(filePath)) {
            std::cout << "FAILED TO LOAD [PLAYER] FROM FILE" << std::endl;
        }
        sprite.setTexture(texture);
    }
};
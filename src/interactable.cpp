#include <SFML/Graphics.hpp>
#include <iostream>
class Interactable {
    public:
    sf::Sprite sprite;
    sf::Texture texture;
    
    Interactable(const std::string& texturePath) {
        if (!texture.loadFromFile(texturePath)) {
            std::cout << "failed to load [INTERACTABLE]" << std::endl;
        }
        sprite.setTexture(texture);
    }
    Interactable(const std::string& texturePath, sf::Vector2f position) {
        if (!texture.loadFromFile(texturePath)) {
            std::cout << "failed to load [INTERACTABLE]" << std::endl;
        }
        sprite.setTexture(texture);
        sprite.setPosition(position);
    }

    void isClicked(float mousePosX, float mousPosY) {
        sf::FloatRect boundbox = sprite.getGlobalBounds();
        if (boundbox.contains(mousePosX, mousPosY)) {
            std::cout << "Sprite was clicked" << std::endl;
        }
    }
};
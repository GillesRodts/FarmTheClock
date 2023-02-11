class Player {
    sf::Texture texture;
public:
    float speed = 3;
    sf::Sprite sprite;
    Player(const std::string& filePath) {
        if (!texture.loadFromFile(filePath)) {
            std::cout << "FAILED TO LOAD [PLAYER] FROM FILE" << std::endl;
        }
        sprite.setTexture(texture);
    }

    void update() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            sprite.move(-7, 0);
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            sprite.move(7, 0);
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            sprite.move(0, -7);
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            sprite.move(0, 7);
        }
    }
};
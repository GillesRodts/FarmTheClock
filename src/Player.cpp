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
        sf::Vector2f position = sprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (position.x > 0) {
                sprite.move(-7, 0);
            }
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (position.x < 1856) {
                sprite.move(7, 0);
            }
            
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (position.y > 0) {
                sprite.move(0, -7);
            }
            
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (position.y < 832) {
                sprite.move(0, 7);
            }
            
        }
    }
};
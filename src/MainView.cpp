#include <SFML/Graphics.hpp>
class NewView {
public:
    NewView(const int width, const int heigth, float zoom)
    {
        view.setSize(width, heigth);
        view.setCenter(width/2, heigth/2);
        view.zoom(zoom);
    }

    sf::View view;
    
    void update(float deltatime) {
        sf::Vector2f position = view.getCenter();
        int centerx = view.getCenter().x;
        int centery = view.getCenter().y;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            centerx -= 7;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            centerx += 7;
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            centery -= 7;
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            centery +=7;
        }
        view.setCenter(centerx, centery);
    }
};
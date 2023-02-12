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
    
    void update() {
        sf::Vector2f position = view.getCenter();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (position.x > 484) {
                view.move(-7, 0);
            }
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (position.x < 1436) {
                view.move(7, 0);
            }
            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (position.y > 230) {
                view.move(0, -7);
            }
            
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (position.y < 672) {
                view.move(0, 7);
            }
            
        }
    }
};
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            view.move(-7, 0);
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            view.move(7, 0);
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            view.move(0, -7);
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            view.move(0, 7);
        }
    }
};
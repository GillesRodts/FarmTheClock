#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tilemap.cpp"
#include "level.cpp"
#include "MainView.cpp"
#include "interactable.cpp"

const int SIZE = 64;
const int WIDTH = SIZE * 30;
const int HEIGTH = SIZE * 14;

int main()
{
    // placing the window, full-screen disabled!
    sf::RenderWindow window(sf::VideoMode(960, 448), "Farm The Clock | Alfa 1.0", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    // setting window in the middle of the screen.
    window.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width - window.getSize().x) / 2, (sf::VideoMode::getDesktopMode().height - window.getSize().y) / 2));

    //setting a view
    NewView view(WIDTH, HEIGTH, 0.5);

    TileMap map;
    if (!map.load("assets/tilemap.png", sf::Vector2u(64,64), background, 30, 14)) {
        std::cout << "FAILED TO LOAD FILEMAP" << std::endl;
        return -1;
    };

    Interactable den("assets/den1.png", sf::Vector2f(64.f,64.f));
    Interactable inventory_button("assets/inv_button.png");

    //TIMING
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time delta_time = clock.restart();
        float delta_timeAsSeconds = delta_time.asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
                
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                den.isClicked(mousePos.x, mousePos.y);

            }
        }

        sf::Vector2f windowPos = window.mapPixelToCoords(sf::Vector2i(892, 380));

        window.clear();

        view.update(delta_timeAsSeconds);
        window.setView(view.view);
        inventory_button.sprite.setPosition(windowPos);
        
        window.draw(map);
        window.draw(inventory_button.sprite);
        window.draw(den.sprite);
        
        window.display();
    }

    return 0;
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.cpp"
#include "Background.cpp"

const int CRAD = 32;
const int WIDTH = CRAD * 32;
const int HEIGTH = CRAD * 16;

int xGridToCord(int gridX) {
    return gridX*CRAD;
}

int yGridToCord(int gridY) {
    return gridY*CRAD;
}

int main()
{
    // placing the window, full-screen disabled!
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGTH), "Farm The Clock | Alfa 1.0", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    // placing window on the middle of the screen
    short int swidth = sf::VideoMode::getDesktopMode().width;
    short int sheight = sf::VideoMode::getDesktopMode().height;
    short int wposx = swidth/2 - (WIDTH/2);
    short int wposy = sheight/2 - (HEIGTH/2)+50;
    window.setPosition(sf::Vector2i(wposx, wposy));

    Player player("assets/textures/farmer-static.png");
    Background background("assets/textures/background.png");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.update();

        window.clear();
        window.draw(background.sprite);
        window.draw(player.sprite);
        window.display();
    }

    return 0;
}
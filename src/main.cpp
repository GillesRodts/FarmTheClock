#include <SFML/Graphics.hpp>

const int cubeCountx = 16;
const int cubeCoutY = 8;

int main()
{
    sf::RenderWindow window(sf::VideoMode(cubeCountx*64, cubeCoutY*64), "FarmTheClock", sf::Style::Close);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // draw everything here...

        // end the current frame
        window.display();
    }

    return 0;
}
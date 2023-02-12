#include <SFML/Graphics.hpp>

const int cubeCountx = 16;
const int cubeCoutY = 8;

int main()
{
    // window-size = (16*64,8*64)
    sf::RenderWindow window(sf::VideoMode(1024, 512), "FarmTheClock", sf::Style::Close);
    sf::Clock clock;
    while (window.isOpen())
    {
        // initializing deltaTime:
        float delta_time = clock.restart().asSeconds();

        // events:

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            
            default:
                break;
            }
        }

        // drawing, clearing and displaying:

        window.clear(sf::Color::Black);

        window.display();
    }

    return 0;
}
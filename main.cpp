#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "data.hpp"

int main()
{
    sf::RenderWindow    window(sf::VideoMode(WIDTH,HEIGHT), "SFML");
    sf::CircleShape     shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
        {
            sf::Event   event;

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(shape);
            window.display();
        }
    return 0;
}

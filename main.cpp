

#include "data.hpp"
#include "back.hpp"
#include "ACharacter.hpp"
#include "Humain.hpp"

int main()
{
    sf::RenderWindow    window(sf::VideoMode(WIDTH,HEIGHT), "SFML");
    Background          back1("ressources/background.png", "ressources/ground.png", sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f(WIDTH, 64), 0);
    Background          back2("ressources/background.png", "ressources/ground.png", sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f(WIDTH, 64), WIDTH);
    ACharacter *humain = new Humain();
    sf::Time time;
    sf::Clock frameClock;
    window.setFramerateLimit(60);
    while (window.isOpen())
        {
            time = frameClock.restart();
            sf::Event   event;

           while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            back1.update(window);
            back2.update(window);
            humain->move(ACharacter::RIGHT, sf::Vector2f(0, 0), time);
            window.draw(humain->getAnimatedSprite());
            window.display();
        }
    return 0;
}

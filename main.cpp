#include "data.hpp"
#include "back.hpp"
#include "ACharacter.hpp"
#include "Humain.hpp"
#include "PowerEvent.hpp"
#include "Hulk.hpp"
#include "Captain.hpp"
#include <ctime>

int main()
{
    sf::RenderWindow    window(sf::VideoMode(WIDTH,HEIGHT), "SFML");
    Background          back1("ressources/background.png", "ressources/ground.png", sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f(WIDTH, 64), 0);
    Background          back2("ressources/background.png", "ressources/ground.png", sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f(WIDTH, 64), WIDTH);
    PowerEvent          events;
    ACharacter *humain = new Captain();
    sf::Time timee;
    sf::Clock frameClock;
    window.setFramerateLimit(60);

    srand(time(NULL));
    while (window.isOpen())
	{
	    timee = frameClock.restart();
	    sf::Event   event;

	   while (window.pollEvent(event))
	    {
		if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
		    window.close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E)
		    events.newEvent();
	    }
	    window.clear();
	    back1.update(window);
	    back2.update(window);
	    events.update(0, window);
	    humain->move(ACharacter::RIGHT, sf::Vector2f(0, 0), timee);
	    window.draw(humain->getAnimatedSprite());
	    window.display();
	}
    return 0;
}

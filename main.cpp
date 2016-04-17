#include "data.hpp"
#include "back.hpp"
#include "ACharacter.hpp"
#include "Humain.hpp"
#include "Rabbit.hpp"
#include "PowerEvent.hpp"
#include "Hulk.hpp"
#include "Captain.hpp"
#include "JumpObstacle.hpp"
#include "JumpRabbitObstacle.hpp"
#include "Duck.hpp"
#include <ctime>
#include <SFML/Audio.hpp>
#include "DestructibleObstacle.hpp"

int handleEvents(ACharacter *character, const sf::Time& frameTime, Background &back1, Background &back2)
{
    sf::Vector2f movement(0.f, 0.f);
    static int jumped;

    if (character->getAnimatedSprite().getPosition().y < character->getJumpHeight())
	jumped = 1;
    else if (jumped != 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && character->getAnimatedSprite().getPosition().y > character->getJumpHeight())
    {
	movement.y -= character->getSpeed();
	character->move(ACharacter::UP, movement, frameTime, back1.getGround(), back2.getGround());
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        jumped = 1;
    if (character->collide(back1.getGround(), back2.getGround()) == true)
        jumped = 0;
    return (0);
}

int main()
{
  sf::RenderWindow    window(sf::VideoMode(WIDTH,HEIGHT), "Endless Shifter");
  std::string		score = "";
  sf::Font		font;
  sf::Text		scoreText;
  float			scoreint = 0;
  if (!font.loadFromFile("ressources/talldark.ttf"))
      return (-1);
  scoreText.setFont(font);
  scoreText.setStyle(sf::Text::Bold);
  scoreText.setColor(sf::Color::Yellow);
  scoreText.setCharacterSize(34);
  start:
  Background          back1("ressources/background.png", "ressources/ground.png", sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f(WIDTH, 64), 0);
  Background          back2("ressources/background.png", "ressources/ground.png", sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f(WIDTH, 64), WIDTH);
  PowerEvent          events;
  //AObstacle		*obstacle = new DestructibleObstacle(1200, 120, "ressources/WallExplosion3.png");
 // AObstacle		*obstacle = new JumpRabbitObstacle(1000, 200, "ressources/Avengers.png");
  AObstacle *obstacle = new JumpObstacle(120, 120, "ressources/Fire2.png");
  ACharacter	*humain = new Humain();
  ACharacter	*rabbit = new Rabbit();
  ACharacter	*hulk = new Hulk();
  ACharacter	*duck = new Duck();
  ACharacter	*current = humain;
  sf::Time timee;
  sf::Clock   total;
  sf::Clock frameClock;
  sf::SoundBuffer buffer;
  sf::Sound sound;
  CHARTYPE   transformation;

  int last_time = 500000;
  window.setFramerateLimit(60);
  srand(time(NULL));
  if (!buffer.loadFromFile("ressources/Avengers.wav"))
    return -1;
  obstacle->init();
  sound.setBuffer(buffer);
  sound.setLoop(true);
  sound.play();
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
	  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
	    current = humain;
	  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T)
	    current = rabbit;
	  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Y)
	    current = hulk;
	  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::U)
	    current = duck;
	  if (events.getDisplay())
	    {
	      if (event.type == sf::Event::KeyPressed)
		{
		  if (event.key.code == sf::Keyboard::Num1)
		    transformation = events.getBlockType(1);
		  else if (event.key.code == sf::Keyboard::Num2)
		    transformation = events.getBlockType(2);
		  else if (event.key.code == sf::Keyboard::Num3)
		    transformation = events.getBlockType(3);
		  else if (event.key.code == sf::Keyboard::Num4)
		    transformation = events.getBlockType(4);

		  switch ((int)transformation)
		    {
		      case 0:
		      current = humain;
		      break;
		      case 1:
		      current = hulk;
		      break;
		      case 2:
		      current = rabbit;
		      break;
		      case 3:
		      current = duck;
		      break;
		    }
		}
	    }
	}
	    handleEvents(current, timee, back1, back2);
	    if (total.getElapsedTime().asMicroseconds() - last_time > 6000000 && !events.getDisplay())
	      {
		events.newEvent();
		last_time = total.getElapsedTime().asMicroseconds();
	      }
      window.clear();
      back1.update(window);
      back2.update(window);
      obstacle->update(window, timee);
      if (obstacle->checkPlayerCollision(*current) == true)
        goto start;
	//exit(0);
      score = "Score  " + patch::to_string((int)scoreint);
      scoreText.setString(score);
      window.draw(scoreText);
      events.update(total.getElapsedTime().asMicroseconds(), window);
      current->move(ACharacter::RIGHT, sf::Vector2f(0, 0), timee, back1.getGround(), back2.getGround());
      window.draw(current->getAnimatedSprite());
      window.display();
      scoreint += 0.2;
    }
    return 0;
}

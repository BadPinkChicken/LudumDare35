#include "Rabbit.hpp"
#include "data.hpp"

Rabbit::Rabbit() : ACharacter()
{
  this->_texture = new sf::Texture();
  this->_texture->loadFromFile("ressources//rabbit.png");
  this->_texture->setSmooth(true);
  sf::Vector2i screenDimensions(200, HEIGHT - 120);
  this->_animate = new AnimatedSprite(sf::seconds(0.1), true, false);
  (*this->_animations)[RIGHT].setSpriteSheet(*this->_texture);
  this->setFrames(RIGHT,134,100, 21, 4, 0);
  this->_x = 0;
  this->_y = 0;
  this->_speed = 1200;
  this->_jumpHeight = 100;
  this->_current = &((*this->_animations)[RIGHT]);
  this->_animate->setPosition(sf::Vector2f(screenDimensions));
  this->_animate->play(*this->_current);
  this->_animate->setOrigin(48, 39);
}

#include "Humain.hpp"
#include "data.hpp"

Humain::Humain() : ACharacter()
{
  this->_texture = new sf::Texture();
  this->_texture->loadFromFile("ressources//humain.png");
  this->_texture->setSmooth(true);
  sf::Vector2i screenDimensions(HEIGHT, WIDTH);
  this->_animate = new AnimatedSprite(sf::seconds(0.1), true, false);
  (*this->_animations)[RIGHT].setSpriteSheet(*this->_texture);
  this->setFrames(RIGHT, 300, 250, 0, 6, 0);
  this->_x = 0;
  this->_y = 0;
  this->_speed = 100;
}

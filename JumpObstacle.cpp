#include "JumpObstacle.hpp"
#include <iostream>
#include "data.hpp"

JumpObstacle::JumpObstacle(int sizeX, int sizeY, std::string const &texture) : AObstacle()
{
  this->_type = JUMP;
  this->_isDestructible = false;
  if (!this->_texture.loadFromFile(texture))
      std::cout << texture <<": texture loading error" << std::endl;
  this->_shape = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));
  this->_shape->setPosition(sf::Vector2f(-1, -1));
  this->_shape->setTexture(&this->_texture);
  _sizeX = sizeX;
  _sizeY = sizeY;
}

void JumpObstacle::init()
{
  this->_shape->setPosition(sf::Vector2f(WIDTH, HEIGHT - 180));
}

JumpObstacle::~JumpObstacle()
{

}

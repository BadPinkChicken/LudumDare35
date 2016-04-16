#include "JumpObstacle.hpp"
#include <iostream>
#include "data.hpp"

JumpObstacle::JumpObstacle(int sizeX, int sizeY) : AObstacle()
{
  this->_type = JUMP;
  this->_isDestructible = false;
  this->_shape = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));
  this->_shape->setPosition(sf::Vector2f(-1, -1));
  _sizeX = sizeX;
  _sizeY = sizeY;
}

void JumpObstacle::init()
{
  this->_shape->setPosition(sf::Vector2f(WIDTH, HEIGHT - 165));
}

JumpObstacle::~JumpObstacle()
{

}

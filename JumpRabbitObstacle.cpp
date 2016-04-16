#include "JumpRabbitObstacle.hpp"
#include <iostream>
#include "data.hpp"

JumpRabbitObstacle::JumpRabbitObstacle(int sizeX, int sizeY, std::string const &texture) : AObstacle()
{
  if ((this->_texture.loadFromFile(texture)) == false)
    std::cout << "texture loading error" << std::endl;
  this->_type = JUMP;
  this->_isDestructible = false;
  this->_shape = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));
  this->_shape->setPosition(sf::Vector2f(-1, -1));
  this->_shape->setTexture(&this->_texture);
  _sizeX = sizeX;
  _sizeY = sizeY;
}

void JumpRabbitObstacle::init()
{
  this->_shape->setPosition(sf::Vector2f(WIDTH, HEIGHT - 365));
}

JumpRabbitObstacle::~JumpRabbitObstacle()
{

}

#include "JumpObstacle.hpp"

JumpObstacle::JumpObstacle() : AObstacle()
{
  this->_type = JUMP;
  this->_isDestructible = false;
  this->_texture = new sf::Texture();
  this->_texture->loadFromFile("ressources//Wall.png");
  this->_texture->setSmooth(true);
  this->_x = 0;
  this->_y = 0;
  this->_speed = 100;
}

JumpObstacle::~JumpObstacle()
{

}

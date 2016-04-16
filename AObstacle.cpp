#include "AObstacle.hpp"

AObstacle::AObstacle()
{

}

AObstacle::~AObstacle()
{

}

bool AObstacle::getDestructible() const
{
  return (this->_isDestructible);
}

sf::Vector2f AObstacle::getVector() const
{
  return (this->_vector2f);
}

TYPE_OBSTACLE AObstacle::getType() const
{
  return (this->_type);
}

void AObstacle::setDestructible(bool x)
{
  this->_isDestructible = x;
}

void AObstacle::setType(TYPE_OBSTACLE x)
{
  this->_type = x;
}

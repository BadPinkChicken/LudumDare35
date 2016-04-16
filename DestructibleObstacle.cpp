#include "DestructibleObstacle.hpp"

DestructibleObstacle::DestructibleObstacle() : AObstacle()
{
  this->_type = DESTRUCTIBLE;
  this->_isDestructible = true;
}

DestructibleObstacle::~DestructibleObstacle()
{

}

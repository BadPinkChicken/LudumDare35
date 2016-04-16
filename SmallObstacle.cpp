#include "SmallObstacle.hpp"

SmallObstacle::SmallObstacle() : AObstacle()
{
  this->_type = SMALL;
  this->_isDestructible = false;
}

SmallObstacle::~SmallObstacle()
{

}

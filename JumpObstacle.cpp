#include "JumpObstacle.hpp"

JumpObstacle::JumpObstacle() : AObstacle()
{
  this->_type = JUMP;
  this->_isDestructible = false;
}

JumpObstacle::~JumpObstacle()
{

}

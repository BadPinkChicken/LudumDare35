#ifndef JUMP_OBSTACLE_HPP
#define JUMP_OBSTACLE_HPP

#include <SFML/System.hpp>
#include "AObstacle.hpp"

class JumpObstacle : public AObstacle
{
public:
  JumpObstacle(int x ,int y);
  virtual void init();
  ~JumpObstacle();
};

#endif

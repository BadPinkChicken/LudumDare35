#ifndef DESTRUCTIBLE_OBSTACLE_HPP
#define DESTRUCTIBLE_OBSTACLE_HPP

#include <SFML/System.hpp>
#include "AObstacle.hpp"

class DestructibleObstacle : public AObstacle
{
public:
  DestructibleObstacle();
  ~DestructibleObstacle();
};

#endif

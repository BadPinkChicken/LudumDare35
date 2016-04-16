#ifndef AOBSTACLE_HPP
#define AOBSTACLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

enum TYPE_OBSTACLE
{
  SMALL,
  JUMP,
  DESTRUCTIBLE
};

class AObstacle
{
public:
  AObstacle();
  ~AObstacle();
  bool getDestructible() const;
  TYPE_OBSTACLE getType() const;
  void setDestructible(bool x);
  void setType(TYPE_OBSTACLE x);
  sf::Vector2f getVector() const;

protected:
  sf::Vector2f _vector2f;
  bool _isDestructible;
  TYPE_OBSTACLE _type;
  sf::Shape *shape;
};

#endif

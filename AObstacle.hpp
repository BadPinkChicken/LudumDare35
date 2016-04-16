#ifndef AOBSTACLE_HPP
#define AOBSTACLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ACharacter.hpp"

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
  sf::Shape &getShape();
  virtual void init() = 0;
  void update(sf::RenderWindow & win);
  bool checkPlayerCollision(ACharacter &character);
protected:
  sf::Vector2f _vector2f;
  sf::Texture*  _texture;
  bool _isDestructible;
  TYPE_OBSTACLE _type;
  sf::Shape *_shape;
  int _sizeX;
  int _sizeY;
};

#endif

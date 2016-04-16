#include "AObstacle.hpp"
#include "data.hpp"

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
sf::Shape &AObstacle::getShape()
{
  return *this->_shape;
}

void                AObstacle::update(sf::RenderWindow & win)
{
    sf::Vector2f    posTmp;


    posTmp = this->_shape->getPosition();
    posTmp.x -= SPEED;
    if (posTmp.x <= 0 - WIDTH)
        posTmp.x = WIDTH;
    this->_shape->setPosition(posTmp);
    win.draw(*this->_shape);
}

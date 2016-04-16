#include "ACharacter.hpp"

ACharacter::ACharacter()
{
  this->_animations = new std::vector<Animation>(20);
  this->_lastAction = IDLE;
}

int ACharacter::getX()
{
  return _x;
}
int ACharacter::getY()
{
  return _y;
}

int ACharacter::getSpeed()
{
  return _speed;
}

int ACharacter::getJumpHeight()
{
  return _jumpHeight;
}

bool ACharacter::getStrength()
{
  return _strengh;
}

void ACharacter::setX(int x)
{
  _x = x;
}

void ACharacter::setY(int Y)
{
  _y = Y;
}

void ACharacter::setSpeed(int speed)
{
  _speed = speed;
}

void ACharacter::setJumpHeigt(int jumpHeight)
{
  _jumpHeight = jumpHeight;
}

void ACharacter::setStrengh(bool strengh)
{
  _strengh = strengh;
}

AnimatedSprite& ACharacter::getAnimatedSprite()
{
  return *_animate;
}

std::vector<Animation>& ACharacter::getAnimations()
{
  return *_animations;
}

void ACharacter::setFrames(animations anim, int sizeX, int sizeY, int line, int maxPerLine, int begin)
{
  int i;

  i = begin;
  while (i < begin + (maxPerLine * sizeX))
  {
    (*this->_animations)[anim].addFrame(sf::IntRect(i, line, sizeX, sizeY));
    i += sizeX;
  }
}

void ACharacter::move(animations move, const sf::Vector2f& coord, const sf::Time& time)
{
  this->_animate->play(*this->_current);
  this->_animate->move(coord * time.asSeconds());
  this->_animate->update(time);
}


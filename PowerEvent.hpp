#pragma once

#include "data.hpp"
#include "AObstacle.hpp"

class   PowerEvent{
private:
    std::list<int>              keys;
    std::vector<sf::Shape *>    PowerList;
    std::list<int>              CurrentKeys;
    std::vector<sf::Shape *>    CurrentPower;
    std::vector<int>            CurrentCorresp;
    int                         time;

    public:
    PowerEvent();
    void                newEvent();
    int                 getTime() const;
    void                update(int time);
    TYPE_OBSTACLE       getBlockType(int key);
    void                killEvent();
};

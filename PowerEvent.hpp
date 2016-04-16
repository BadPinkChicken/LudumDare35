#pragma once

#include "data.hpp"
#include "AObstacle.hpp"
#include <string>

class   PowerEvent{
private:
    sf::Shape*                  backBlock;
    std::list<int>              keys;
    std::vector<sf::Shape *>    PowerList;
    std::map<int, int>          CorrespKeys;
    std::map<int, sf::Shape *>  CurrentPower;
    int                         time;
    bool                        display;
    sf::Font                    font;
    sf::Text                    text;
    sf::Text                    textKeys;

    public:
    PowerEvent();
    void                newEvent();
    int                 getTime() const;
    void                update(int time, sf::RenderWindow &);
    CHARTYPE       getBlockType(int key);
    void                killEvent();
    bool                getDisplay() const;
};

#include "PowerEvent.hpp"

PowerEvent::PowerEvent()
{
    sf::Shape   *block1 = new sf::RectangleShape(sf::Vector2f(50, 50));
    sf::Texture *tmp = new sf::Texture();
    if (!tmp->loadFromFile("ressources/hulkBlock.png"))
        std::cout << "Error texture hulkBlock" << std::endl;
    block1->setTexture(tmp);
    sf::Shape   *block2 = new sf::RectangleShape(sf::Vector2f(50, 50));
    tmp = new sf::Texture();
    if (!tmp->loadFromFile("ressources/poussinBlock.png"))
        std::cout << "Error texture hulkBlock" << std::endl;
    block2->setTexture(tmp);
    sf::Shape   *block3 = new sf::RectangleShape(sf::Vector2f(50, 50));
    tmp = new sf::Texture();
    if (!tmp->loadFromFile("ressources/deathBlock.png"))
        std::cout << "Error texture hulkBlock" << std::endl;
    block3->setTexture(tmp);
    sf::Shape   *block4 = new sf::RectangleShape(sf::Vector2f(50, 50));
    tmp = new sf::Texture();
    if (!tmp->loadFromFile("ressources/rabbitBlock.png"))
        std::cout << "Error texture hulkBlock" << std::endl;
    block4->setTexture(tmp);
    for (int i = 0; i < 4; i++)
        this->keys.push_back(i+1);
    this->PowerList.push_back(block1);
    this->PowerList.push_back(block2);
    this->PowerList.push_back(block3);
    this->PowerList.push_back(block4);
}

static bool     isInList(std::list<int> &list, int nb)
{
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
    {        if (*it == nb)
            return true;
    }
    return false;
}

void    PowerEvent::newEvent()
{
    std::list<int> tmp;
    int nb = rand() % 4 + 1;
    this->time = 10;
   /* for (int i = 0; i < 3; i++){
        while (isInList(this->CurrentKeys, nb))
            nb = rand() % 4 + 1;
        this->CurrentKeys.push_back(nb);
    }
    nb = rand() % 4;
    for (int i = 0; i < 3; i++){
        while (isInList(tmp, nb))
            nb = rand() % 4 + 1;
        tmp.push_back(nb);
    }*/
    for (std::list<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
        this->CurrentPower.push_back(this->PowerList[*it]);
        this->CurrentCorresp.push_back(*it);
    }
}

int     PowerEvent::getTime() const
{
    return this->time;
}

TYPE_OBSTACLE    PowerEvent::getBlockType(int key)
{
    switch (key){
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

void    PowerEvent::killEvent()
{
    while (this->CurrentKeys.size() > 0)
        this->CurrentKeys.pop_front();
    while (this->CurrentCorresp.size() > 0)
        this->CurrentCorresp.pop_back();
    while (this->CurrentPower.size() >0)
        this->CurrentPower.pop_back();
}

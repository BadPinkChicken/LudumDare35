#include "PowerEvent.hpp"

PowerEvent::PowerEvent()
{
    this->font.loadFromFile("ressources/talldark.ttf");
    this->display = false;
    this->text.setFont(this->font);
    this->text.setStyle(sf::Text::Bold);
    this->textKeys.setFont(this->font);
    this->textKeys.setStyle(sf::Text::Bold);
    this->textKeys.setColor(sf::Color::Yellow);
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
    backBlock = new sf::RectangleShape(sf::Vector2f(300, 70));
    tmp = new sf::Texture();
    if (!tmp->loadFromFile("ressources/backblock.png"))
        std::cout << "error texture back block" << std::endl;
    backBlock->setTexture(tmp);
    backBlock->setPosition(sf::Vector2f(480, 190));
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
    this->display = true;
    this->killEvent();
    std::list<int>  tmp;
    std::list<int>  tmp2;
    int i = 0;
    int nb = rand() % 4 + 1;
    std::string tmpString;
    this->time = 10;
    nb = rand() % 4;
    for (int i = 0; i < 3; i++){
        while (isInList(tmp, nb))
            nb = rand() % 4;
        tmp.push_back(nb);
    }
    nb = rand() % 4 + 1;
    for (int i = 0; i < 3; i++){
        while (isInList(tmp2, nb))
            nb = rand() % 4 + 1;
        tmp2.push_back(nb);
    }

    i = 0;
     for (std::list<int>::iterator it = tmp2.begin(); it != tmp2.end(); it++) {
        this->CorrespKeys[i] = *it;

        if (i =! 0)
            tmpString += "           ";
        tmpString += patch::to_string(*it);
        i++;
    }
    for (std::list<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
        this->CurrentPower[*it] = this->PowerList[*it];
    }

    this->textKeys.setString(tmpString);
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
        this->CurrentPower.clear();
   /* while (this->CurrentPower.size() >0)
        this->CurrentPower.pop_front();*/
}

void    PowerEvent::update(int time, sf::RenderWindow & win)
{
    static  int last_time;
    int i = 0;
    (void) time;

    if (!this->display)
        return;
    this->text.setCharacterSize(64);
    this->text.setPosition(sf::Vector2f(610, 120));
    this->textKeys.setPosition(sf::Vector2f(440, 250));
    this->text.setColor(sf::Color::Yellow);
    this->text.setString(patch::to_string(this->time));
    win.draw(this->text);
    win.draw(*backBlock);
    win.draw(this->textKeys);
    for (std::map<int, sf::Shape *>::iterator it = this->CurrentPower.begin(); it != this->CurrentPower.end(); it++)
    {
        it->second->setPosition(sf::Vector2f(i * 100 + 500, 200));
        win.draw(*it->second);
        i++;
    }
}

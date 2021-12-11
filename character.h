#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
class Cell;
class Character {
    int hp;
    int atk;
    int def;
    std::shared_ptr<Cell> pos;
    public:
        Character(int h, int a, int d, std::shared_ptr<Cell> pos);
};

#endif
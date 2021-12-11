#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
class Cell;
class Character {
    protected:
        int hp;
        int atk;
        int def;
        std::shared_ptr<Cell> pos;
    public:
        Character(int h, int a, int d);
        Character(int h, int a, int d, std::shared_ptr<Cell> pos);
        int getHP();
        int getAtk();
        int getDef();
        std::shared_ptr<Cell> getPos();
        void setPos(std::shared_ptr<Cell> p);
};

#endif
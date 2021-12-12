#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include <string>
class Cell;
class Character {
    protected:
        std::string race;
        int maxHP;
        int hp;
        int atk;
        int def;
        std::shared_ptr<Cell> pos;
    public:
        Character(std::string race, int maxHP, int h, int a, int d);
        Character(std::string race, int maxHP, int h, int a, int d, std::shared_ptr<Cell> pos);
        std::string getRace();
        int getHP();
        void changeHP(int n);
        int getAtk();
        int getDef();
        std::shared_ptr<Cell> getPos();
        void setPos(std::shared_ptr<Cell> p);
};

#endif
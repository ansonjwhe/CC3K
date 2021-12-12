#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Player;
class Drow;
class Goblin;
class Enemy: public Character {
    public:
        Enemy(int h, int a, int d, std::shared_ptr<Cell> pos); 
        virtual void strike(Player & p) = 0; // virtual
        virtual void hitBy(Player & p) = 0; // virtual
};

class Halfling: public Enemy {
    public:
        Halfling(std::shared_ptr<Cell> pos);
        void strike(Player & p);
        void hitBy(Player & p);
};

class Human: public Enemy {
    public:
        Human(std::shared_ptr<Cell> pos);
        void strike(Player & p);
        void hitBy(Player & p);
};

class Dwarf: public Enemy {
    public:
        Dwarf(std::shared_ptr<Cell> pos);
        void strike(Player & p);
        void hitBy(Player & p);
};

class Elf: public Enemy {
    public:
        Elf(std::shared_ptr<Cell> pos);
        void strike(Drow & d);
        void strike(Player & p);
        void hitBy(Player & p);
};

class Orcs: public Enemy {
    public:
        Orcs(std::shared_ptr<Cell> pos);
        void strike(Goblin & g);
        void strike(Player & p);
        void hitBy(Player & p);
};

class Merchant: public Enemy {
    public:
        Merchant(std::shared_ptr<Cell> pos);
        void strike(Player & p);
        void hitBy(Player & p);
};

class Dragon: public Enemy {
    public:
        Dragon(std::shared_ptr<Cell> pos);
        void strike(Player & p);
        void hitBy(Player & p);
};

#endif

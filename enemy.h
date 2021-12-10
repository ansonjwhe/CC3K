#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Player;

class Enemy: public Character {
    public: 
        virtual void strike(Player) = 0;
        virtual void hitBy(Player) = 0;
};

class Halfling: public Enemy {
    void strike(Player);
    void hitBy(Player);
};

class Human: public Enemy {
    void strike(Player);
    void hitBy(Player);
};

class Dwarf: public Enemy {
    void strike(Player);
    void hitBy(Player);
};

class Elf: public Enemy {
    void strike(Player);
    void strike(Drow);
    void hitBy(Player);
};

class Orcs: public Enemy {
    void strike(Player);
    void strike(Goblin);
    void hitBy(Player);
};

class Merchant: public Enemy {
    void strike(Player);
    void hitBy(Player);
};

class Dragon: public Enemy {
    void strike(Player);
    void hitBy(Player);
};

#endif

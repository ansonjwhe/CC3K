#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Player;

class Enemy: public Character {
    public:
        Enemy(int h, int a, int d, std::shared_ptr<Cell> pos); 
        virtual void strike(Player) = 0;
        virtual void hitBy(Player) = 0;
};

class Halfling: public Enemy {
    public:
        Halfling(std::shared_ptr<Cell> pos);
        void strike(Player);
        void hitBy(Player);
};

class Human: public Enemy {
    public:
        Human(std::shared_ptr<Cell> pos);
        void strike(Player);
        void hitBy(Player);
};

class Dwarf: public Enemy {
    public:
        Dwarf(std::shared_ptr<Cell> pos);
        void strike(Player);
        void hitBy(Player);
};

class Elf: public Enemy {
    public:
        Elf(std::shared_ptr<Cell> pos);
        void strike(Player);
        void strike(Drow);
        void hitBy(Player);
};

class Orcs: public Enemy {
    public:
        Orcs(std::shared_ptr<Cell> pos);
        void strike(Player);
        void strike(Goblin);
        void hitBy(Player);
};

class Merchant: public Enemy {
    public:
        Merchant(std::shared_ptr<Cell> pos);
        void strike(Player);
        void hitBy(Player);
};

class Dragon: public Enemy {
    public:
        Dragon(std::shared_ptr<Cell> pos);
        void strike(Player);
        void hitBy(Player);
};

#endif

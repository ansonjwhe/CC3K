#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "player.h"

class Enemy: public Character {
    public: 
        virtual void strike(Player) = 0;
        virtual void hitBy(Player) = 0;
};

#endif

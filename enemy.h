#include "character.h"

class Enemy: public Character {
    public: 
        virtual void strike(Player) = 0;
        virtual void hitBy(Player) = 0;
};
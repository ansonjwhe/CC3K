#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "enemy.h"

class Player: public Character {
    public:
        virtual void strike(Enemy) = 0;
        virtual void hitBy(Enemy) = 0;
        void consume(RH);
        void consume(BA);
        void consume(BD);
        void consume(PH);
        void consume(WA);
        void consume(SmallPile);
        void consume(NormalPile);
        void consume(MerchantHoard);
        void consume(DragonHoard);
};

#endif

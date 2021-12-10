#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "enemy.h"

class Player: public Character {
    public:
        Player(char playerRace, int h, int a, int d);
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

class Shade: public Player {
    public: 
        Shade();
}

class Drow: public Player {
    public: 
        Drow();
}

class Vampire: public Player {
    public: 
        Vampire();
}

class Troll: public Player {
    public: 
        Troll();
}

class Goblin: public Player {
    public: 
        Goblin();
}
#endif

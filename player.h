#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include <memory>
class Enemy;
class Cell;
class RH;
class BA;
class BD;
class PH;
class WA;
class WD;
class SmallPile;
class NormalPile;
class MerchantHoard;
class DragonHoard;
class Player: public Character {
    public:
        Player(int h, int a, int d);
        void displayStats();
        void strike(Enemy); // virtual
        void hitBy(Enemy); // virtual
        void consume(RH);
        void consume(BA);
        void consume(BD);
        void consume(PH);
        void consume(WA);
        void consume(WD);
        void consume(SmallPile);
        void consume(NormalPile);
        void consume(MerchantHoard);
        void consume(DragonHoard);
};

class Shade: public Player {
    public: 
        Shade();
};

class Drow: public Player {
    public: 
        Drow();
};

class Vampire: public Player {
    public: 
        Vampire();
        void strike(Enemy);
        void hitBy(Enemy);
};

class Troll: public Player {
    public: 
        Troll();
};

class Goblin: public Player {
    public: 
        Goblin();
};
#endif

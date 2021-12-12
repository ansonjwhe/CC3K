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
    int batk = 0;
    int bdef = 0;
    int score = 0; // increments with gold, never decreases
    int gold = 0; // can decrease when buying from merchant
    public:
        Player(int h, int a, int d);
        void displayStats();
        virtual void strike(Enemy & e) = 0;
        virtual void hitBy(Enemy & e) = 0;
        void consume(RH & r);
        void consume(BA & b);
        void consume(BD & b);
        void consume(PH & p);
        void consume(WA & w);
        void consume(WD & w);
        void consume(SmallPile & s);
        void consume(NormalPile & n);
        void consume(MerchantHoard & m);
        void consume(DragonHoard & d);
        int getGold();
        int getScore();
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
        void strike(Dwarf & d);
        void strike(Enemy & e);
        void hitBy(Enemy & e);
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

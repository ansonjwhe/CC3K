#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
class Enemy;

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
        Player(int h, int a, int d, std::shared_ptr<Cell> pos);
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
        Shade(std::shared_ptr<Cell> pos);
};

class Drow: public Player {
    public: 
        Drow(std::shared_ptr<Cell> pos);
};

class Vampire: public Player {
    public: 
        Vampire(std::shared_ptr<Cell> pos);
        void strike(Enemy);
        void hitBy(Enemy);
};

class Troll: public Player {
    public: 
        Troll(std::shared_ptr<Cell> pos);
};

class Goblin: public Player {
    public: 
        Goblin(std::shared_ptr<Cell> pos);
};
#endif

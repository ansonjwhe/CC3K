#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include "enemy.h"
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
class Player : public Character
{
    int atkModifier = 0;
    int defModifier = 0;
    int score = 0; // increments with gold, never decreases
    int gold = 0;  // can decrease when buying from merchant
public:
    Player(std::string race, int maxHP, int h, int a, int d);

    int getGold();
    void addGold(int v);
    int getScore();
    int getAtkModifier();
    int getDefModifier();

    void displayStats();

    void applyAtkModifier(int a);
    void applyDefModifier(int d);
    int calcDmg(int enemyDef);
    virtual void strike(Enemy &e) = 0;
    virtual void hitBy(Enemy &e) = 0;

    void consume(RH &r);
    void consume(BA &b);
    void consume(BD &b);
    void consume(PH &p);
    void consume(WA &w);
    void consume(WD &w);
    void consume(SmallPile &s);
    void consume(NormalPile &n);
    void consume(MerchantHoard &m);
    void consume(DragonHoard &d);
};

class Shade: public Player {
    public: 
        Shade();
        void strike(Enemy & e);
        void hitBy(Enemy & e);
};

class Drow: public Player {
    public: 
        Drow();
        void strike(Enemy & e);
        void hitBy(Enemy & e);
};

class Dwarf;
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
        void strike(Enemy & e);
        void hitBy(Enemy & e);
};

class Goblin: public Player {
    public: 
        Goblin();
        void strike(Enemy & e);
        void hitBy(Enemy & e);
};

#endif

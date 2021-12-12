#include "enemy.h"
#include "player.h"
#include "character.h"
#include <math.h>

Enemy::Enemy(std::string race, int maxHP, int h, int a, int d, std::shared_ptr<Cell> pos) : 
Character{race, maxHP, h, a, d, pos} {}
Halfling::Halfling(std::shared_ptr<Cell> pos) : Enemy{"Halfling", 100, 100, 15, 20, pos} {}
Human::Human(std::shared_ptr<Cell> pos) : Enemy{"Human", 140, 140, 20, 20, pos} {}
Dwarf::Dwarf(std::shared_ptr<Cell> pos) : Enemy{"Dwarf", 100, 100, 20, 30, pos} {}
Elf::Elf(std::shared_ptr<Cell> pos) : Enemy{"Elf", 140, 140, 30, 10, pos} {}
Orcs::Orcs(std::shared_ptr<Cell> pos) : Enemy{"Orcs", 180, 180, 30, 25, pos} {}
Merchant::Merchant(std::shared_ptr<Cell> pos) : Enemy{"Merchant", 30, 30, 70, 5, pos} {}
Dragon::Dragon(std::shared_ptr<Cell> pos) : Enemy{"Dragon", 150, 150, 20, 20, pos} {}

int Enemy::calcDmg(int playerDef) {
    return (-1) * ceil(100 / (100 + playerDef)) * atk;
}

int Enemy::getDef() {
    return def;
}

void Halfling::strike(Player &p)
{
    int random = rand() % 2;
    if (random == 0)
    {
        int dmg = calcDmg(p.getDef() + p.getDefModifier());
        p.changeHP(dmg);
    }
}

void Halfling::hitBy(Player &p)
{
    int random = rand() % 2;
    if (random == 0)
    {
        p.strike(*this);
    }
}

void Human::strike(Player &p)
{
    int random = rand() % 2;
    if (random == 0)
    {
        int dmg = calcDmg(p.getDef() + p.getDefModifier());
        p.changeHP(dmg);
    }
}

void Human::hitBy(Player &p)
{
    p.strike(*this);
}

void Dwarf::strike(Player &p)
{
    int random = rand() % 2;
    if (random == 0)
    {
        int dmg = calcDmg(p.getDef() + p.getDefModifier());
        p.changeHP(dmg);
    }
}

void Dwarf::hitBy(Player &p)
{
    p.strike(*this);
}

void Elf::strike(Drow &d)
{
    int random = rand() % 2;
    if (random == 0)
    {
        int dmg = calcDmg(d.getDef() + d.getDefModifier());
        d.changeHP(dmg);
    }
}

void Elf::strike(Player &p)
{
    for (int i = 0; i < 2; i++)
    {
        int random = rand() % 2;
        if (random == 0)
        {
            int dmg = calcDmg(p.getDef() + p.getDefModifier());
            p.changeHP(dmg);
        }
    }
}

void Elf::hitBy(Player &p)
{
    p.strike(*this);
}

void Orcs::strike(Goblin &g)
{
    int random = rand() % 2;
    if (random == 0)
    {
        int dmg = calcDmg(g.getDef() + g.getDefModifier());
        g.changeHP(dmg * 3 / 2);
    }
}

void Orcs::strike(Player &p)
{
    int random = rand() % 2;
    if (random == 0)
    {
        int dmg = calcDmg(p.getDef() + p.getDefModifier());
        p.changeHP(dmg);
    }
}

void Orcs::hitBy(Player &p)
{
    p.strike(*this);
}

void Merchant::strike(Player &p)
{
    int random = rand() % 2;
    if (random == 0)
    {
        int dmg = calcDmg(p.getDef() + p.getDefModifier());
        p.changeHP(dmg);
    }
}

void Merchant::hitBy(Player &p)
{
    p.strike(*this);
}

void Dragon::strike(Player &p)
{
    int random = rand() % 2;
    if (random == 0)
    {
        int dmg = calcDmg(p.getDef() + p.getDefModifier());
        p.changeHP(dmg);
    }
}

void Dragon::hitBy(Player &p)
{
    p.strike(*this);
}

std::shared_ptr<Enemy> Enemy::getRandEnemy(std::shared_ptr<Cell> pos)
{
    int enemy = rand() % 18;
    if (enemy <= 3)
    {
        return std::make_shared<Human>(pos);
    }
    else if (enemy > 3 && enemy <= 6)
    {
        return std::make_shared<Dwarf>(pos);
    }
    else if (enemy > 6 && enemy <= 11)
    {
        return std::make_shared<Halfling>(pos);
    }
    else if (enemy > 11 && enemy <= 13)
    {
        return std::make_shared<Elf>(pos);
    }
    else if (enemy > 13 && enemy <= 15)
    {
        return std::make_shared<Orcs>(pos);
    }
    else
    {
        return std::make_shared<Merchant>(pos);
    }
}
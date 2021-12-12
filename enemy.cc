#include "enemy.h"
#include "player.h"
#include "character.h"
#include <math.h>

Enemy::Enemy(int h, int a, int d, std::shared_ptr<Cell> pos) : Character{h, a, d, pos} {}
Halfling::Halfling(std::shared_ptr<Cell> pos) : Enemy{100, 15, 20, pos} {}
Human::Human(std::shared_ptr<Cell> pos) : Enemy{140, 20, 20, pos} {}
Dwarf::Dwarf(std::shared_ptr<Cell> pos) : Enemy{100, 20, 30, pos} {}
Elf::Elf(std::shared_ptr<Cell> pos) : Enemy{140, 30, 10, pos} {}
Orcs::Orcs(std::shared_ptr<Cell> pos) : Enemy{180, 30, 25, pos} {}
Merchant::Merchant(std::shared_ptr<Cell> pos) : Enemy{30, 70, 5, pos} {}
Dragon::Dragon(std::shared_ptr<Cell> pos) : Enemy{150, 20, 20, pos} {}

void Halfling::strike(Player & p) {
    int random = rand() % 2;
    if (random == 0) {
        int dmg = ceil(100 / (100 + p.getDef())) * atk;
        p.changeHp(dmg);
    }
}

void Halfling::hitBy(Player & p) {
    p.strike(*this);
}

void Human::strike(Player & p) {
    int random = rand() % 2;
    if (random == 0) {
        int dmg = ceil(100 / (100 + p.getDef())) * atk;
        p.changeHp(dmg);
    }
}

void Human::hitBy(Player & p) {
    p.strike(*this);
}

void Dwarf::strike(Player & p) {
    int random = rand() % 2;
    if (random == 0) {
        int dmg = ceil(100 / (100 + p.getDef())) * atk;
        p.changeHp(dmg);
    }
}

void Dwarf::hitBy(Player & p) {
    p.strike(*this);
}

void Elf::strike(Drow & d) {
    int random = rand() % 2;
    if (random == 0) {
        int dmg = ceil(100 / (100 + d.getDef())) * atk;
        d.changeHp(dmg);
    }
}

void Elf::strike(Player & p) {
    for (int i = 0; i < 2; i++) {
        int random = rand() % 2;
        if (random == 0) {
            int dmg = ceil(100 / (100 + p.getDef())) * atk;
            p.changeHp(dmg);
        }
    }
}

void Elf::hitBy(Player & p) {
    p.strike(*this);
}

void Orcs::strike(Goblin & g) {
    int random = rand() % 2;
    if (random == 0) {
        int dmg = ceil(100 / (100 + g.getDef())) * atk;
        g.changeHp(dmg * 3 / 2);
    }
}

void Orcs::strike(Player & p) {
    int random = rand() % 2;
    if (random == 0) {
        int dmg = ceil(100 / (100 + p.getDef())) * atk;
        p.changeHp(dmg);
    }
}

void Orcs::hitBy(Player & p) {
    p.strike(*this);
}

void Merchant::strike(Player & p) {
    int random = rand() % 2;
    if (random == 0) {
        int dmg = ceil(100 / (100 + p.getDef())) * atk;
        p.changeHp(dmg);
    }
}

void Merchant::hitBy(Player & p) {
    p.strike(*this);
}

void Dragon::strike(Player & p) {
    int random = rand() % 2;
    if (random == 0) {
        int dmg = ceil(100 / (100 + p.getDef())) * atk;
        p.changeHp(dmg);
    }
}

void Dragon::hitBy(Player & p) {
    p.strike(*this);
}

#include "player.h"
#include "enemy.h"
#include "item.h"
#include "potion.h"
#include "gold.h"
#include <iostream>
#include <string>
#include <math.h>

Player::Player(std::string race, int maxHP, int h, int a, int d) : Character{race, maxHP, h, a, d} {}
Shade::Shade(): Player{"Shade", 125, 125, 25, 25} {}
Drow::Drow(): Player{"Drow", 150, 150, 25, 15} {}
Vampire::Vampire(): Player{"Vampire", 0, 50, 25, 25} {}
Troll::Troll(): Player{"Troll", 120, 120, 25, 15} {}
Goblin::Goblin(): Player{"Goblin", 110, 110, 15, 20} {}

void Player::displayStats() {
    std::string maxHPStr = (maxHP == 0) ? "∞" : std::to_string(maxHP);
    std::cout << "HP: " << hp << "/" << maxHPStr << std::endl;
    std::cout << "Atk: " << atk << " + (" << atkModifier << ")" << std::endl;
    std::cout << "Def: " << def << " + (" << defModifier << ")" << std::endl;
}

int Player::getAtkModifier() {
    return atkModifier;
}

int Player::getDefModifier() {
    return defModifier;
}

int Player::getGold() {
    return gold;
}

void Player::addGold(int v) {
    gold += v;
    if (v > 0) {
        score += v;
    }
}

int Player::getScore() {
    return score;
}

void Player::applyAtkModifier(int a) {
    atkModifier += a;
}

void Player::applyDefModifier(int d) {
    defModifier += d;
}


int Player::calcDmg(int enemyDef) {
    return (-1) * ceil(100 / (100 + enemyDef)) * (atk + atkModifier);
}


void Shade::strike(Enemy & e) {
    int dmg = calcDmg(e.getDef());
    e.changeHP(dmg);
}

void Shade::hitBy(Enemy & e) {
    e.strike(*this);
}

void Drow::strike(Enemy & e) {
    int dmg = calcDmg(e.getDef());
    e.changeHP(dmg);
}

void Drow::hitBy(Enemy & e) {
    e.strike(*this);
}


void Vampire::strike(Dwarf & d) {
    int dmg = calcDmg(d.getDef());
    d.changeHP(dmg);
    changeHP(-5);
}

void Vampire::strike(Enemy & e) {
    int dmg = calcDmg(e.getDef());
    e.changeHP(dmg);
    changeHP(5);
}

void Vampire::hitBy(Enemy & e) {
    e.strike(*this);
}

void Troll::strike(Enemy & e) {
    int dmg = calcDmg(e.getDef());
    e.changeHP(dmg);
}

void Troll::hitBy(Enemy & e) {
    e.strike(*this);
}
void Goblin::strike(Enemy & e) {
    int dmg = calcDmg(e.getDef());
    e.changeHP(dmg);
}

void Goblin::hitBy(Enemy & e) {
    e.strike(*this);
}

void Player::consume(RH &r) {
    changeHP(r.getVal());
}

void Player::consume(BA &b) {
    applyAtkModifier(b.getVal());
}

void Player::consume(BD &b) {
    applyDefModifier(b.getVal());
}

void Player::consume(PH &p) {
    changeHP(p.getVal());
}

void Player::consume(WA &w) {
    applyAtkModifier(w.getVal());
}

void Player::consume(WD &w) {
    applyDefModifier(w.getVal());
}

void Player::consume(SmallPile &s) {
    addGold(s.getVal());
}

void Player::consume(NormalPile &n) {
    addGold(n.getVal());
}

void Player::consume(MerchantHoard &m) {
    addGold(m.getVal());
}

void Player::consume(DragonHoard &d) {
    addGold(d.getVal());
}

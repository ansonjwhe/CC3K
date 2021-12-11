#include "player.h"
#include "enemy.h"
#include <iostream>

Player::Player(int h, int a, int d) : Character{h, a, d} {}
Shade::Shade(): Player{125, 25, 25} {}
Drow::Drow(): Player{150, 25, 15} {}
Vampire::Vampire(): Player{50, 25, 25} {}
Troll::Troll(): Player{120, 25, 15} {}
Goblin::Goblin(): Player{110, 15, 20} {}

void Player::displayStats() {
    std::cout << "HP: " << hp << std::endl;
    std::cout << "Atk: " << atk << std::endl;
    std::cout << "Def: " << def << std::endl;
}

int Player::getGold() {
    return gold;
}

int Player::getScore() {
    return score;
}

void Vampire::strike(Enemy e) {

}

void Vampire::hitBy(Enemy e) {

}
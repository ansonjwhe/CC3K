#include "player.h"
#include "enemy.h"
#include <iostream>

Player::Player(int h, int a, int d, std::shared_ptr<Cell> pos) : Character{h,a,d,pos} {}  
Shade::Shade(std::shared_ptr<Cell> pos): Player{125, 25, 25, pos} {}
Drow::Drow(std::shared_ptr<Cell> pos): Player{150, 25, 15, pos} {}
Vampire::Vampire(std::shared_ptr<Cell> pos): Player{50, 25, 25, pos} {}
Troll::Troll(std::shared_ptr<Cell> pos): Player{120, 25, 15, pos} {}
Goblin::Goblin(std::shared_ptr<Cell> pos): Player{110, 15, 20, pos} {}

void Player::displayStats() {
    std::cout << "HP: " << hp << std::endl;
    std::cout << "Atk: " << atk << std::endl;
    std::cout << "Def: " << def << std::endl;
}

void Vampire::strike(Enemy e) {

}

void Vampire::hitBy(Enemy e) {

}
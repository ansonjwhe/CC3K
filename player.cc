#include "player.h"
#include "enemy.h"
#include <iostream>

Player::Player(int h, int a, int d, std::shared_ptr<Cell> pos, int batk, int bdef) : Character{h,a,d,pos}, batk{batk}, bdef{bdef} {}
Shade::Shade(std::shared_ptr<Cell> pos): Player{125, 25, 25, pos, 0, 0} {}
Drow::Drow(std::shared_ptr<Cell> pos): Player{150, 25, 15, pos, 0, 0} {}
Vampire::Vampire(std::shared_ptr<Cell> pos): Player{50, 25, 25, pos, 0, 0} {}
Troll::Troll(std::shared_ptr<Cell> pos): Player{120, 25, 15, pos, 0, 0} {}
Goblin::Goblin(std::shared_ptr<Cell> pos): Player{110, 15, 20, pos, 0, 0} {}

void Player::displayStats() {
    std::cout << "HP: " << hp << std::endl;
    std::cout << "Atk: " << atk << std::endl;
    std::cout << "Def: " << def << std::endl;
}

void Vampire::strike(Enemy e) {

}

void Vampire::hitBy(Enemy e) {

}
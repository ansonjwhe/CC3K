#include "enemy.h"
#include "player.h"
#include "character.h"

Enemy::Enemy(int h, int a, int d, std::shared_ptr<Cell> pos) : Character{h, a, d, pos} {}
Halfling::Halfling(std::shared_ptr<Cell> pos) : Enemy{100, 15, 20, pos} {}
Human::Human(std::shared_ptr<Cell> pos) : Enemy{140, 20, 20, pos} {}
Dwarf::Dwarf(std::shared_ptr<Cell> pos) : Enemy{100, 20, 30, pos} {}
Elf::Elf(std::shared_ptr<Cell> pos) : Enemy{140, 30, 10, pos} {}
Orcs::Orcs(std::shared_ptr<Cell> pos) : Enemy{180, 30, 25, pos} {}
Merchant::Merchant(std::shared_ptr<Cell> pos) : Enemy{30, 70, 5, pos} {}
Dragon::Dragon(std::shared_ptr<Cell> pos) : Enemy{150, 20, 20, pos} {}

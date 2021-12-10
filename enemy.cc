#include "enemy.h"
#include "player.h"
#include "character.h"

Enemy::Enemy(int h, int a, int d): Character{h,a,d} {}
Halfling::Halfling(): Enemy{100, 15, 20} {}
Human::Human(): Enemy{140, 20, 20} {}
Dwarf::Dwarf(): Enemy{100, 20, 30} {}
Elf::Elf(): Enemy{140, 30, 10} {}
Orcs::Orcs(): Enemy{180, 30, 25} {}
Merchant::Merchant(): Enemy{30, 70, 5} {}
Dragon::Dragon(): Enemy{150, 20, 20} {}

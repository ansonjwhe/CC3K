#include "character.h"

Character::Character(int h, int a, int d, std::shared_ptr<Cell> pos): hp{h}, atk{a}, def{d}, pos{pos} {}

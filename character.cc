#include "character.h"

Character::Character(int h, int a, int d): hp{h}, atk{a}, def{d} {}
Character::Character(int h, int a, int d, std::shared_ptr<Cell> pos): hp{h}, atk{a}, def{d}, pos{pos} {}

int Character::getHP() {return hp;}
int Character::getAtk() {return atk;}
int Character::getDef() {return def;}
std::shared_ptr<Cell> Character::getPos() {return pos;}

void Character::setPos(std::shared_ptr<Cell> p) {
    pos = p;
}

void Character::changeHp(int n) {
    hp -= n;
}

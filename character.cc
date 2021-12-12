#include "character.h"

Character::Character(std::string race, int maxHP, int h, int a, int d):
race{race}, maxHP{maxHP}, hp{h}, atk{a}, def{d} {}
Character::Character(std::string race, int maxHP, int h, int a, int d, std::shared_ptr<Cell> pos):
race{race}, maxHP{maxHP}, hp{h}, atk{a}, def{d}, pos{pos} {}

std::string Character::getRace() {return race;}
int Character::getHP() {return hp;}
int Character::getAtk() {return atk;}
int Character::getDef() {return def;}

std::shared_ptr<Cell> Character::getPos() {return pos;}

void Character::setPos(std::shared_ptr<Cell> p) {
    pos = p;
}

void Character::changeHP(int n) {
    // if hp were to go negative, set to 0
    if (hp + n <= 0) {
        hp = 0;
    }
    // if hp were to exceed maxHP, set to maxHP
    // unless maxHP == 0 (no maxHP, i.e. Vampire)
    else if (hp + n >= maxHP && maxHP != 0) { // 
        hp = maxHP;
    } 
    // otherwise, apply regular hp change
    else {
        hp += n;
    }
}

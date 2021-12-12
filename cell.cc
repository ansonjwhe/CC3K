#include "cell.h"
#include "enemy.h"
#include <iostream>

Cell::Cell(int row, int col, char v) : row{row}, col{col}, val{v} {
    if (v == '.' || v == '\\' || v == '@' || isdigit(v) || isalpha(v)) {
        trueVal = '.';
        type = EmptyFloorTile;
    } else {
        trueVal = v;
        type = NonFloorTile;
    }

    // convert val of Potion and Gold from custom files
    if (v == '0' || v == '1' || v == '2' || v == '3' || v == '4' || v == '5') {
        val = 'P';
    } else if (v == '6' || v == '7' || v == '8' || v == '9') {
        val = 'G';
    }
}

int Cell::getRow() {
    return row;
}

int Cell::getCol() {
    return col;
}

char Cell::getTrueVal() {
    return trueVal;
}

// Should only be used to manipulate Dragon Hoard true value
void Cell::setTrueVal(char c) {
    trueVal = c;
}

char Cell::getVal() {
    return val;
}

void Cell::setVal(char c) {
    val = c;
}

cellType Cell::getCellType() {
    return type;
}

void Cell::setTypeToTrueVal() {
    playerPtr = nullptr;
    potionPtr = nullptr;
    goldPtr = nullptr;
    enemyPtr = nullptr;
    val = trueVal;
    if (trueVal == '.') {
        type = EmptyFloorTile;
    } else {
        type = NonFloorTile;
    }
}

void Cell::attachPlayer(std::shared_ptr<Player> ptr) {
    playerPtr = ptr;
    type = PlayerTile;
    val = '@';
}

void Cell::attachPotion(std::shared_ptr<Potion> ptr) {
    potionPtr = ptr;
    type = PotionTile;
    val = 'P';
}

void Cell::attachGold(std::shared_ptr<Gold> ptr) {
    goldPtr = ptr;
    type = GoldTile;
    val = 'G';
}

void Cell::attachEnemy(std::shared_ptr<Enemy> ptr) {
    enemyPtr = ptr;
    type = EnemyTile;
    std::string race = ptr->getRace();
    if (race == "Human") {
        val = 'H';
    } else if (race == "Dwarf") {
        val = 'W';
    } else if (race == "Elf") {
        val = 'E';
    } else if (race == "Orcs") {
        val = 'O';
    } else if (race == "Merchant") {
        val = 'M';
    } else if (race == "Dragon") {
        val = 'D';
    } else if (race == "Halfling") {
        val = 'L';
    } 
}
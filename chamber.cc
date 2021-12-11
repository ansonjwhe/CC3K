#include "chamber.h"

std::shared_ptr<Cell> Chamber::getRandomEmptyCell(int chamber) {
    int random = rand() % cells.size();
    return cells[random];
}
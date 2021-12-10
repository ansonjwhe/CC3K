#ifndef CHAMBER_H
#define CHAMBER_H
#include "cell.h"
#include <vector>
#include <memory>

class Chamber{
    std::vector<std::shared_ptr<Cell>> cells;
    std::shared_ptr<Cell> getRandomEmptyCell(int chamber);
};

#endif
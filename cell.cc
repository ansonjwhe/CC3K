#include "cell.h"
#include <iostream>

Cell::Cell(char val) : val{val} {}

char Cell::getVal() {
    return val;
}

void Cell::setVal(char c) {
    val = c;
}

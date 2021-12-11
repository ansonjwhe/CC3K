#include "cell.h"
#include <iostream>

Cell::Cell(int row, int col, char v) : row{row}, col{col}, val{v} {
    if (v == '@' || isdigit(v) || isalpha(v)) {
        trueVal = '.';
    } else {
        trueVal = v;
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

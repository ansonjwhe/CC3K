#ifndef CELL_H
#define CELL_H


class Cell {
    char val;
    public:
        Cell(char val);
        Cell getRandomAdjacentCell(Cell);
        char getVal();
        void setVal(char c);
};

#endif

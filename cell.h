#ifndef CELL_H
#define CELL_H


class Cell {
    const int row;
    const int col;
    char trueVal;
    char val;
    public:
        Cell(int row, int col, char v);
        int getRow();
        int getCol();
        char getTrueVal();
        void setTrueVal(char c);
        char getVal();
        void setVal(char c);
};

#endif

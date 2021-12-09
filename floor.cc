
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include "floor.h"
#include "cell.h"

Floor::Floor() {
    std::ifstream map;
    std::string line;
    char c;
    map.open("./plain.txt");
    for (int i=0; i<numRows; i++) {
        std::getline(map, line);
        std::istringstream iss{line};
        for (int j=0; j<numCols; j++) {
            iss >> std::noskipws >> c;
            grid[i][j] = std::make_shared<Cell>(c);
        }
    }

}

void Floor::draw() {
    for (int i=0; i<numRows; i++) {
        for (int j=0; j<numCols; j++) {
            std::cout << grid[i][j]->getVal();
        }
        std::cout << std::endl;
    }
}


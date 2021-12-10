
#include <iostream>
#include <string>
#include <memory>
#include "floor.h"
#include "cell.h"

Floor::Floor()
{
    // std::ifstream map;
    // std::string line;
    // char c;
    // map.open("./plain.txt");
    // for (int i=0; i<numRows; i++) {
    //     std::getline(map, line);
    //     std::istringstream iss{line};
    //     for (int j=0; j<numCols; j++) {
    //         iss >> std::noskipws >> c;
    //         grid[i][j] = std::make_shared<Cell>(c);
    //     }
    // }
}

int Floor::getNumRows() { return numRows; }

int Floor::getNumCols() { return numCols; }

std::shared_ptr<Cell> Floor::getCell(int row, int col)
{
    return grid[row][col];
}

void Floor::setCell(int row, int col, char c)
{
    grid[row][col] = std::make_shared<Cell>(c);
}

int Floor::getRandomChamber(int playerChamber)
{
    std::vector<int> chambers;
    for (int i = 0; i < 5; i++)
    {
        if (i != playerChamber)
        {
            chambers.push_back(i);
        }
    }
    int chosenRandom = rand() % chambers.size();
    return chambers[chosenRandom];
}

void Floor::draw()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            std::cout << grid[i][j]->getVal();
        }
        std::cout << std::endl;
    }
}

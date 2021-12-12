#ifndef FLOOR_H
#define FLOOR_H

#include <string>
#include <vector>
#include <memory>
#include "chamber.h"

class Cell;
class Player;
class Gold;
class Potion;
class Enemy;
class Floor
{
    const int numRows = 25;
    const int numCols = 79;
    Chamber chambers[5];
    std::shared_ptr<Cell> grid[25][79];
    std::shared_ptr<Cell> stairway;
    std::shared_ptr<Cell> start;
    // std::vector<Gold> goldVec;
    // std::vector<Potion> potionVec;
    std::vector<std::shared_ptr<Enemy>> enemyVec;

public:
    Floor();
    int getNumRows();
    int getNumCols();

    std::shared_ptr<Cell> getCell(int row, int col);
    void addCellToChamber(std::shared_ptr<Cell>, int);
    void setCell(int row, int col, char c);

    bool isValidMove(std::shared_ptr<Cell> pos, std::string dir);
    std::shared_ptr<Cell> movePlayer(std::shared_ptr<Cell> pos, std::string dir);

    Cell getRandomAdjacentCell(Cell);
    int getRandomChamber(int playerChamber);

    std::shared_ptr<Cell> getStart();
    void setStart(std::shared_ptr<Cell> pos);
    void setStairway(std::shared_ptr<Cell> pos);
    bool isPCOnStairway(std::shared_ptr<Cell> pos);

    void draw();

    void addEnemy(std::shared_ptr<Enemy> e);
};

#endif

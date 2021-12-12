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
    const int numPotionsGenerated = 10;
    const int numGoldGenerated = 10;
    const int numEnemiesGenerated = 20;
    std::vector<std::shared_ptr<Enemy>> enemyVec;

public:
    int getNumRows();
    int getNumCols();

    std::shared_ptr<Cell> getCell(int row, int col);
    void addCellToChamber(std::shared_ptr<Cell>, int);
    void setCell(int row, int col, char c);
    std::shared_ptr<Cell> getCellInDirection(std::shared_ptr<Cell> pos, std::string dir);
    bool isValidPlayerMove(std::shared_ptr<Cell> pos, std::string dir);
    void movePlayer(std::shared_ptr<Player> player, std::string dir);

    Cell getRandomAdjacentCell(Cell);
    int getRandomStairwayChamber(int playerChamber);
    void populateFloor();

    std::shared_ptr<Cell> getStart();
    void setStart(std::shared_ptr<Cell> pos);
    void setStairway(std::shared_ptr<Cell> pos);
    bool isPCOnStairway(std::shared_ptr<Cell> pos);

    void draw();

    void addEnemy(std::shared_ptr<Enemy> e);
};

#endif

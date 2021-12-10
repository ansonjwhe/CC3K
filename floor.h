#ifndef FLOOR_H
#define FLOOR_H

#include <string>
#include <vector>
#include <memory>


class Cell;
class Player;
class Gold;
class Potion;
class Enemy;
class Floor{
    const int numRows = 25;
    const int numCols = 79;
    std::shared_ptr<Cell> grid [25][79];
    // std::vector<Gold> goldVec;
    // std::vector<Potion> potionVec;
    // std::vector<Enemy> enemyVec;
    
    public:
        Floor();
        int getNumRows();
        int getNumCols();
        std::shared_ptr<Cell> getCell(int row, int col);
        void setCell(int row, int col, char c);
        void movePlayer(Player, std::string dir);
        Cell getRandomAdjacentCell(Cell);
        int getRandomChamber(int playerChamber);
        bool isPCOnStairway(Player);
        void draw();
};

#endif

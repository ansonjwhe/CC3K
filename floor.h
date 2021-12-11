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
    std::shared_ptr<Cell> stairway;
    std::shared_ptr<Cell> start;
    // std::vector<Gold> goldVec;
    // std::vector<Potion> potionVec;
    // std::vector<Enemy> enemyVec;
    
    public:
        Floor();
        int getNumRows();
        int getNumCols();

        std::shared_ptr<Cell> getCell(int row, int col);
        void setCell(int row, int col, char c);

        void movePlayer(Player &, std::string dir);

        Cell getRandomAdjacentCell(Cell);
        int getRandomChamber(int playerChamber);

        std::shared_ptr<Cell> getStart();
        void setStart(std::shared_ptr<Cell> pos);
        void setStairway(std::shared_ptr<Cell> pos);
        bool isPCOnStairway(std::shared_ptr<Cell> pos);

        void draw();
};

#endif

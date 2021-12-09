#ifndef FLOOR_H
#define FLOOR_H

#include <string>
#include <vector>
#include <memory>


class Cell;
class Player;
class Floor{
    const int numRows = 25;
    const int numCols = 79;
    std::shared_ptr<Cell> grid [25][79];
    
    public:
        Floor();
        void movePlayer(Player, std::string dir);
        int getRandomChamber(int playerChamber);
        void draw();
};

#endif

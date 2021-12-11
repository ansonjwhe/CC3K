#ifndef GAME_H
#define GAME_H

#include <memory>
#include "floor.h"
#include "player.h"

enum exitCodes { Lose, Win, Restart, Quit };
class Game {
    std::string playerRace;
    const int numFloors = 5;
    Floor floors [5];
    int curFloor;
    std::shared_ptr<Player> player;

    void setPlayer(std::string pcRace);
    void interpretChar(int floorNum, std::shared_ptr<Cell> pos, char c);
    void loadPlainFloors(std::string fileName);
    void loadCustomFloors(std::string fileName);
    void drawTurn(int floorNum);
    public:
        Game();
        void loadFloors(std::string fileName, bool isCustom);
        exitCodes startGame(std::string pcRace);
};

#endif

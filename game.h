#ifndef GAME_H
#define GAME_H

#include <memory>
#include "floor.h"
#include "player.h"

enum exitCodes { Lose, Win, Restart, Quit };
class Game {
    std::string pcRace;
    const int numFloors = 5;
    Floor floors [5];
    int curFloor;
    std::unique_ptr<Player> player;

    void interpretChar(std::shared_ptr<Cell> pos, char c);
    void loadPlainFloors(std::string fileName);
    void loadCustomFloors(std::string fileName);
    public:
        Game();
        void loadFloors(std::string fileName, bool isCustom);
        exitCodes startGame(std::string playerRace);
};

#endif

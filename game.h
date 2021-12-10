#ifndef GAME_H
#define GAME_H

#include "floor.h"
// #include "player.h"

enum exitCodes { Lose, Win, Restart, Quit };
class Game {
    const int numFloors = 5;
    Floor floors [5];
    // Player player;
    void loadPlainFloors(std::string fileName);
    void loadCustomFloors(std::string fileName);
    public:
        Game();
        void loadFloors(std::string fileName, bool isCustom);
        exitCodes startGame(std::string playerRace);
};

#endif

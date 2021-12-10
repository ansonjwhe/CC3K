#ifndef GAME_H
#define GAME_H

#include "floor.h"
// #include "player.h"

enum exitCodes { Lose, Win, Restart, Quit };
class Game {
    Floor floor;
    // Player player;
    public:
        Game();
        exitCodes startGame(std::string playerRace);
};

#endif

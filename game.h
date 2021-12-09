#ifndef GAME_H
#define GAME_H

#include "floor.h"

class Game {
    Floor floor;
    public:
        Game();
        int startGame(char playerRace);
};

#endif

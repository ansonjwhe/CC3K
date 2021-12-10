#include "game.h"
#include "floor.h"
#include <iostream>

Game::Game() {}


exitCodes Game::startGame(std::string playerRace) {
    // for (int i=0; i<5; i++) {
    //     floor = Floor();
    // }
    floor.draw();
    return Win;
}
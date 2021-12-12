#ifndef GAME_H
#define GAME_H

#include <memory>
#include "floor.h"

class Player;

enum exitCodes { Continue, Lose, Win, Restart, Quit };
class Game {
    const int numFloors = 5;
    Floor floors [5];
    int curFloor;
    std::shared_ptr<Player> player;

    void setPlayer(std::string pcRace);
    void interpretChar(int floorNum, std::shared_ptr<Cell> pos, char c);
    void loadPlainFloors(std::string fileName);
    void generateChambersAndObjects();
    void loadCustomFloors(std::string fileName);
    void drawTurn();
    bool isValidCommand(std::vector<std::string> words);
    exitCodes interpretCommand(std::vector<std::string> words);
    public:
        Game();
        void loadFloors(std::string fileName, bool isCustom);
        exitCodes startGame(std::string pcRace);
        int getScore();
};

#endif

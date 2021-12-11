#include "game.h"
#include "floor.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

Game::Game() {}

void Game::interpretChar(int floorNum, std::shared_ptr<Cell> pos, char c) {
    switch (c) {
        case '@':
            floors[floorNum].setStart(pos);
            break;
        case '\\':
            floors[floorNum].setStairway(pos);
            break;
        default:
            break;
    }
}

void Game::loadPlainFloors(std::string fileName) {
    std::ifstream ifs;
    std::string line;
    char c;
    for (int floorNum=0; floorNum<numFloors; floorNum++) {
        ifs.open(fileName + ".txt");
        for (int i=0; i<floors[floorNum].getNumRows(); i++) {
            std::getline(ifs, line);
            std::istringstream iss{line};
            for (int j=0; j<floors[floorNum].getNumCols(); j++) {
                iss >> std::noskipws >> c;
                floors[floorNum].setCell(i, j, c);
            }
        }
        ifs.close();
    }
}

void Game::loadCustomFloors(std::string fileName) {
    std::ifstream ifs;
    std::string line;
    char c;
    ifs.open(fileName + ".txt");
    for (int floorNum=0; floorNum<numFloors; floorNum++) {
        for (int i=0; i<floors[floorNum].getNumRows(); i++) {
            while (std::getline(ifs, line)) { // skip any whitespace lines
                if (line.find_first_not_of(' ') != std::string::npos) break;
            }
            std::istringstream iss{line};
            for (int j=0; j<floors[floorNum].getNumCols(); j++) {
                iss >> std::noskipws >> c;
                floors[floorNum].setCell(i, j, c);
                interpretChar(floorNum, floors[floorNum].getCell(i, j), c);
            }
        }
    }
}

void Game::loadFloors(std::string fileName, bool isCustom) {
    if (isCustom) {
        loadCustomFloors(fileName);
        
    } else {
        loadPlainFloors(fileName);
        // call victor's algorithm for generating chambers
        // iterate through each cell in a floor
        // if a cell is a "valid" floor tile (may by @, \, 0, 1, etc.)
        // generate PC, stairway, potions, gold, enemies
    }
}

void Game::setPlayer(std::string playerRace) {
    if (playerRace == "s") {
        player = std::make_shared<Shade>();
    } else if (playerRace == "d") {
        player = std::make_shared<Drow>();
    } else if (playerRace == "v") {
        player = std::make_shared<Vampire>();
    } else if (playerRace == "t") {
        player = std::make_shared<Troll>();
    } else if (playerRace == "g") {
        player = std::make_shared<Goblin>();
    }
}

exitCodes Game::startGame(std::string playerRace) {
    setPlayer(playerRace);
    curFloor = 0;
    for (int i=0; i<5; i++) {
        player->setPos(floors[i].getStart());
        floors[i].draw();
        std::cout << "Race: Shade Gold: 0" << std::setw(50) << "Floor 0" << std::endl;
        player->displayStats();
    }
    return Win;
}
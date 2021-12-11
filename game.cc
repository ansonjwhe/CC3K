#include "game.h"
#include "floor.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

Game::Game() {}

void Game::interpretChar(std::shared_ptr<Cell> pos, char c) {
    switch (c) {
        case '@':
            if (pcRace == "s") {
                player = std::make_unique<Shade>(pos);
            } else if (pcRace == "d") {
                player = std::make_unique<Drow>(pos);
            } else if (pcRace == "v") {
                player = std::make_unique<Vampire>(pos);
            } else if (pcRace == "t") {
                player = std::make_unique<Troll>(pos);
            } else if (pcRace == "g") {
                player = std::make_unique<Goblin>(pos);
            }
            break;
        case '\\':
            // generate stairway
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
                interpretChar(floors[floorNum].getCell(i, j), c);
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


exitCodes Game::startGame(std::string playerRace) {
    pcRace = playerRace;
    curFloor = 0;
    for (int i=0; i<5; i++) {
        floors[i].draw();
        std::cout << "Race: Shade Gold: 0" << std::setw(50) << "Floor 0" << std::endl;
        player->displayStats();
    }
    return Win;
}
#include "game.h"
#include "floor.h"
#include <iostream>
#include <fstream>
#include <sstream>

Game::Game() {}

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
            }
        }
    }
}

void Game::loadFloors(std::string fileName, bool isCustom) {
    if (isCustom) {
        loadCustomFloors(fileName);
    } else {
        loadPlainFloors(fileName);
        // generate PC, stairway, potions, gold, enemies
    }
}


exitCodes Game::startGame(std::string playerRace) {
    for (int i=0; i<5; i++) {
        floors[i].draw();
    }
    return Win;
}
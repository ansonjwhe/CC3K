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

void Game::setPlayer(std::string pcRace) {
    if (pcRace == "s") {
        playerRace = "Shade";
        player = std::make_shared<Shade>();
    } else if (pcRace == "d") {
        playerRace = "Drow";
        player = std::make_shared<Drow>();
    } else if (pcRace == "v") {
        playerRace = "Vampire";
        player = std::make_shared<Vampire>();
    } else if (pcRace == "t") {
        playerRace = "Troll";
        player = std::make_shared<Troll>();
    } else if (pcRace == "g") {
        playerRace = "Goblin";
        player = std::make_shared<Goblin>();
    }
}

void Game::drawTurn(int floorNum) {
    floors[floorNum].draw();
    std::cout << "Race: " << playerRace << "      Gold: " << player->getGold();
    std::cout << std::setw(60 - playerRace.length() - std::to_string(player->getGold()).length())
    std::cout << "Floor " << floorNum+1 << std::endl;
    player->displayStats();
    std::cout << "Action: insert last turn's events here." << std::endl;
}

exitCodes Game::startGame(std::string pcRace) {
    std::string command;

    setPlayer(pcRace);
    curFloor = 0;
    for (int i=0; i<5; i++) {
        player->setPos(floors[i].getStart());
        while (!floors[i].isPCOnStairway(player->getPos())) {
            drawTurn(i);
            std::getline(std::cin, command);
            
        }
    }
    return Win;
}
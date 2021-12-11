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

void Game::drawTurn() {
    floors[curFloor].draw();
    std::cout << "Race: " << playerRace << "      Gold: " << player->getGold();
    std::cout << std::setw(60 - playerRace.length() - std::to_string(player->getGold()).length());
    std::cout << "Floor " << curFloor+1 << std::endl;
    player->displayStats();
    std::cout << "Action: insert last turn's events here." << std::endl;
}

std::vector<std::string> extractWords(std::string command) {
    std::vector<std::string> result;
    std::string nextWord;
    std::istringstream iss{command};
    while (iss >> nextWord) {
        result.push_back(nextWord);
    }
    return result;
}

bool isDirectional(std::string s) {
    return (s == "no") || (s == "so") || (s == "ea") || (s == "we") 
        || (s == "ne") || (s == "nw") || (s == "se") || (s == "sw");
}

// checks if command is syntactically valid and is possible to execute
bool Game::isValidCommand(std::vector<std::string> words) {
    if (words.size() == 1) {
        if (isDirectional(words[0])) {
            if (floors[curFloor].isValidMove(player->getPos(), words[0])) {
                return true;
            } else {
                std::cout << "Player can only move to unoccupied ";
                std::cout << "floor tile(.), doorway(+), passage(#), ";
                std::cout << "stairway(\\), or gold(G)." << std::endl;
            }
        } else if (words[0] == "f" || words[0] == "r" || words[0] == "q") {
            return true;
        }
    } else if (words.size() == 2) {
        if (words[0] == "u") {
            if (isDirectional(words[1])) {
                // if specified direction has potion, return true
                // else 
                // std::cout << "No potion found in specified direction." << std::endl;
            }
        } else if (words[0] == "a") {
            if (isDirectional(words[1])) {
                // if specified direction has enemy, return true
                // else 
                // std::cout << "No enemy found in specified direction." << std::endl;
            }
        }
    }
    return false;
}

// assume that command in words is valid and possible to execute
exitCodes Game::interpretCommand(std::vector<std::string> words) {
    if (words.size() == 1) {
        if (isDirectional(words[0])) {
            player->setPos(floors[curFloor].movePlayer(player->getPos(), words[0]));
            // process consume gold
        } else if (words[0] == "f") {
            // toggles enemies' random movement (i.e. stops movement, then resumes movement)
        } else if (words[0] == "r") {
            return Restart;
        } else if (words[0] == "q") {
            return Quit;
        }
    } else if (words.size() == 2) { // assume words[1] is a valid direction and has potion/enemy
        if (words[0] == "u") {

        } else if (words[0] == "a") {

        }
    }
    return Continue;
}

exitCodes Game::startGame(std::string pcRace) {
    std::string command;
    std::vector<std::string> words;

    setPlayer(pcRace);
    for (int i=0; i<5; i++) {
        curFloor = i;
        player->setPos(floors[i].getStart());
        while (!floors[i].isPCOnStairway(player->getPos())) {
            drawTurn();

            // loop for getting valid command
            std::getline(std::cin, command);
            words = extractWords(command);
            while (!isValidCommand(words)) {
                std::cout << "Invalid Command." << std::endl; 
                std::getline(std::cin, command);
                words = extractWords(command);
            }

            exitCodes exitCode = interpretCommand(words);
            if (exitCode == Quit || exitCode == Restart) {
                return exitCode;
            }
        }
    }
    return Win;
}

int Game::getScore() {
    return player->getScore();
}
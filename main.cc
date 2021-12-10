#include <iostream>
#include "game.h"

std::string promptPC() {
    std::string selectedPC;
    std::cout << "Select a Player Class from the following or (q)uit:" << std::endl;
    std::cout << "(s)hade, (d)row, (v)ampire, (t)roll, (g)oblin" << std::endl;
    std::getline(std::cin, selectedPC);
    return selectedPC;
}

bool isValidPCInput(std::string PC) {
    return (PC == "s") || (PC == "d") || (PC == "v") || (PC == "t") || (PC == "g") || (PC == "q");
}

bool promptPlayAgain() {
    std::string s;
    while (true) {
        std::cout << "Select (p)lay again or (q)uit" << std::endl;
        std::getline(std::cin, s); // BUG: spaces in input will be treated as multiple inputs
        if (s == "p") {
            return true;
        } else if (s == "q") {
            return false;
        } else {
            std::cout << "Invalid Command." << std::endl << std::endl;
        }
    }
}

bool interpretExitCode(exitCodes exitCode) {
    switch(exitCode) {
        case Lose:
            std::cout << "Game Lost! Show game score here" << std::endl;
            return promptPlayAgain();

        case Win:
            std::cout << "Game Won! Show game score here" << std::endl;
            return promptPlayAgain();

        case Restart:
            return true;

        case Quit:
            return false;

        default:
            std::cout << "Undefined Exit Code." << std::endl;
            return false;
    }
}

int main(int argc, char** argv) {
    Game game;
    if (argc == 1) {
        game.loadFloors("plain", false);
    } else if (argc == 2) {
        game.loadFloors(argv[1], true);
    }

    std::string selectedPC;

    while (true) {
        selectedPC = promptPC();
        while (!isValidPCInput(selectedPC)) {
            std::cout << "Invalid Command." << std::endl << std::endl;
            selectedPC = promptPC();
        }
        // valid PC race or 'q' has been selected
        if (selectedPC == "q") {
            return 0;
        } else {
            exitCodes exitCode = game.startGame(selectedPC);
            bool playAgain = interpretExitCode(exitCode);
            if (!playAgain) {
                return 0;
            }
        }
    }
}
 
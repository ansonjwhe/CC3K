#include <iostream>
#include "game.h"

char promptPC() {
    char selectedPC;
    std::cout << "Select a Player Class from the following or (q)uit:" << std::endl;
    std::cout << "(s)hade, (d)row, (v)ampire, (t)roll, (g)oblin" << std::endl;
    std::cin >> selectedPC;
    return selectedPC;
}

bool isValidPCInput(char PC) {
    return (PC == 's') || (PC == 'd') || (PC == 'v') || (PC == 't') || (PC == 'g') || (PC == 'q');
}

bool promptPlayAgain() {
    char c;
    while (true) {
        std::cout << "Select (p)lay again or (q)uit" << std::endl;
        std::cin >> c;
        if (c == 'p') {
            return 1;
        } else if (c == 'q') {
            return 0;
        } else {
            std::cout << "Invalid Command." << std::endl << std::endl;
        }
    }
}

int main() {
    Game game;
    char selectedPC;

    while (true) {
        selectedPC = promptPC();
        while (!isValidPCInput(selectedPC)) {
            std::cout << "Invalid Command." << std::endl << std::endl;
            selectedPC = promptPC();
        }
        // valid PC race or 'q' has been selected
        if (selectedPC == 'q') {
            return 0;
        } else {
            int exitCode = game.startGame(selectedPC);
            std::cout << exitCode << ": Show game score here" << std::endl;
            bool playAgain = promptPlayAgain();
            if (!playAgain) {
                return 0;
            }
        }
    }
}
 
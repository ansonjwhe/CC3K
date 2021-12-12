
#include <iostream>
#include <string>
#include <memory>
#include <array>
#include "floor.h"
#include "cell.h"
#include "chamber.h"
#include "potion.h"
#include "gold.h"

Floor::Floor()
{
    // std::ifstream map;
    // std::string line;
    // char c;
    // map.open("./plain.txt");
    // for (int i=0; i<numRows; i++) {
    //     std::getline(map, line);
    //     std::istringstream iss{line};
    //     for (int j=0; j<numCols; j++) {
    //         iss >> std::noskipws >> c;
    //         grid[i][j] = std::make_shared<Cell>(c);
    //     }
    // }
}

int Floor::getNumRows() { return numRows; }

int Floor::getNumCols() { return numCols; }

std::shared_ptr<Cell> Floor::getCell(int row, int col)
{
    return grid[row][col];
}

void Floor::setCell(int row, int col, char c)
{
    grid[row][col] = std::make_shared<Cell>(row, col, c);
}

void Floor::addCellToChamber(std::shared_ptr<Cell> cell, int chamberNum)
{
    chambers[chamberNum].addCell(cell);
}

int Floor::getRandomChamber(int playerChamber)
{
    std::vector<int> chambers;
    for (int i = 0; i < 5; i++)
    {
        if (i != playerChamber)
        {
            chambers.push_back(i);
        }
    }
    int chosenRandom = rand() % chambers.size();
    return chambers[chosenRandom];
}

std::shared_ptr<Cell> Floor::getStart()
{
    return start;
}
void Floor::setStart(std::shared_ptr<Cell> pos)
{
    start = pos;
}

void Floor::setStairway(std::shared_ptr<Cell> pos)
{
    stairway = pos;
}

bool Floor::isPCOnStairway(std::shared_ptr<Cell> pos)
{
    return stairway == pos;
}

std::array<int, 2> interpretDirection(std::string dir)
{
    std::array<int, 2> result;
    if (dir == "no")
    {
        result[0] = -1;
        result[1] = 0;
    }
    else if (dir == "so")
    {
        result[0] = 1;
        result[1] = 0;
    }
    else if (dir == "ea")
    {
        result[0] = 0;
        result[1] = 1;
    }
    else if (dir == "we")
    {
        result[0] = 0;
        result[1] = -1;
    }
    else if (dir == "ne")
    {
        result[0] = -1;
        result[1] = 1;
    }
    else if (dir == "nw")
    {
        result[0] = -1;
        result[1] = -1;
    }
    else if (dir == "se")
    {
        result[0] = 1;
        result[1] = 1;
    }
    else if (dir == "sw")
    {
        result[0] = 1;
        result[1] = -1;
    }
    return result;
}

bool Floor::isValidMove(std::shared_ptr<Cell> pos, std::string dir)
{
    std::array<int, 2> dirInts = interpretDirection(dir);
    int deltaRow = dirInts[0];
    int deltaCol = dirInts[1];
    int row = pos->getRow();
    int col = pos->getCol();

    // get val in specified direction
    char val = grid[row + deltaRow][col + deltaCol]->getVal();
    return (val == '.') || (val == '+') || (val == '#') || (val == '\\') || (val == 'G');
}

std::shared_ptr<Cell> Floor::movePlayer(std::shared_ptr<Cell> pos, std::string dir)
{
    std::array<int, 2> dirInts = interpretDirection(dir);
    int deltaRow = dirInts[0];
    int deltaCol = dirInts[1];
    int row = pos->getRow();
    int col = pos->getCol();

    // set prev player position to true val (either '.', '+', or '#')
    pos->setVal(pos->getTrueVal());

    // get new player position
    std::shared_ptr<Cell> newPos = grid[row + deltaRow][col + deltaCol];

    // set player position val to '@'
    newPos->setVal('@');
    return newPos;
}

void Floor::draw()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            std::cout << grid[i][j]->getVal();
        }
        std::cout << std::endl;
    }
}

void Floor::addEnemy(std::shared_ptr<Enemy> e) {
    enemyVec.push_back(e);
}
// Handle all generic generation
void Floor::populateFloor()
{
    // populate floor with everything but player
    int playerChamber = rand() % 5;
    setStart(chambers[playerChamber].getRandomEmptyCell());
    setStairway(chambers[getRandomChamber(playerChamber)].getRandomEmptyCell());
    // generate potions
    for (int i = 0; i < 10; i++)
    {
        int randomChamber = rand() % 5;
        std::shared_ptr<Cell> newPos = chambers[randomChamber].getRandomEmptyCell();
        std::shared_ptr<Potion> potion = Potion::getRandPotion(newPos);
        chambers[randomChamber].getRandomEmptyCell()->attachPotion(potion);
    }
    // generate gold
    for (int i = 0; i < 10; i++)
    {
        int randomChamber = rand() % 5;
        std::shared_ptr<Cell> newPos = chambers[randomChamber].getRandomEmptyCell();
        std::shared_ptr<Gold> gold = Gold::getRandGold(newPos);
        chambers[randomChamber].getRandomEmptyCell()->attachGold(gold);
    }
    // spawn enemies
    for (int i = 0; i < 20; i++)
    {
        int randomChamber = rand() % 5;
        std::shared_ptr<Cell> newPos = chambers[randomChamber].getRandomEmptyCell();
        std::shared_ptr<Enemy> enemy = Enemy::getRandEnemy(newPos);
        chambers[randomChamber].getRandomEmptyCell()->attachEnemy(enemy);
    }
}

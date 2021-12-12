
#include <iostream>
#include <string>
#include <memory>
#include <array>
#include "floor.h"
#include "cell.h"
#include "chamber.h"
#include "potion.h"
#include "gold.h"
#include "player.h"
#include "enemy.h"


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

int Floor::getRandomStairwayChamber(int playerChamber)
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
    pos->setVal('\\');
}

bool Floor::isPCOnStairway(std::shared_ptr<Cell> pos)
{
    return stairway == pos;
}

std::shared_ptr<Cell> Floor::getCellInDirection(std::shared_ptr<Cell> pos, std::string dir)
{
    int deltaRow;
    int deltaCol;
    if (dir == "no")
    {
        deltaRow = -1;
        deltaCol = 0;
    }
    else if (dir == "so")
    {
        deltaRow = 1;
        deltaCol = 0;
    }
    else if (dir == "ea")
    {
        deltaRow = 0;
        deltaCol = 1;
    }
    else if (dir == "we")
    {
        deltaRow = 0;
        deltaCol = -1;
    }
    else if (dir == "ne")
    {
        deltaRow = -1;
        deltaCol = 1;
    }
    else if (dir == "nw")
    {
        deltaRow = -1;
        deltaCol = -1;
    }
    else if (dir == "se")
    {
        deltaRow = 1;
        deltaCol = 1;
    }
    else if (dir == "sw")
    {
        deltaRow = 1;
        deltaCol = -1;
    }
    int row = pos->getRow();
    int col = pos->getCol();
    return grid[row + deltaRow][col + deltaCol];    
}

bool Floor::isValidPlayerMove(std::shared_ptr<Cell> pos, std::string dir)
{
    std::shared_ptr<Cell> newPos = getCellInDirection(pos, dir);

    // get val in specified direction
    char val = newPos->getVal();
    return (val == '.') || (val == '+') || (val == '#') || (val == '\\') || (val == 'G');
}

void Floor::movePlayer(std::shared_ptr<Player> player, std::string dir)
{
    // get old player position
    std::shared_ptr<Cell> pos = player->getPos();

    // get new player position
    std::shared_ptr<Cell> newPos = getCellInDirection(pos, dir);

    // set old player position to true val (either '.', '+', or '#')
    // and set cellType to EmptyTile
    pos->setVal(pos->getTrueVal());
    pos->setTypeToTrueVal();

    // set newPos val to '@'
    // and attach player
    newPos->setVal('@');
    newPos->attachPlayer(player);

    // update player position property
    player->setPos(newPos);
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
    // generate player spawn location
    int playerChamber = rand() % 5;
    setStart(chambers[playerChamber].getRandomEmptyCell());

    // generate stairway location
    setStairway(chambers[getRandomStairwayChamber(playerChamber)].getRandomEmptyCell());

    // generate potions
    for (int i = 0; i < numPotionsGenerated; i++)
    {
        int randomChamber = rand() % 5;
        std::shared_ptr<Cell> newPos = chambers[randomChamber].getRandomEmptyCell();
        std::shared_ptr<Potion> potion = Potion::getRandPotion(newPos);
        newPos->attachPotion(potion);
    }

    // generate gold
    for (int i = 0; i < numGoldGenerated; i++)
    {
        int randomChamber = rand() % 5;
        std::shared_ptr<Cell> newPos = chambers[randomChamber].getRandomEmptyCell();
        std::shared_ptr<Gold> gold = Gold::getRandGold(newPos);
        newPos->attachGold(gold);
    }

    // spawn enemies
    for (int i = 0; i < numEnemiesGenerated; i++)
    {
        int randomChamber = rand() % 5;
        std::shared_ptr<Cell> newPos = chambers[randomChamber].getRandomEmptyCell();
        std::shared_ptr<Enemy> enemy = Enemy::getRandEnemy(newPos);
        newPos->attachEnemy(enemy);
        addEnemy(enemy);
    }
}

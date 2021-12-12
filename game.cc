

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "game.h"
#include "player.h"
#include "floor.h"
#include "chamber.h"
#include "cell.h"
#include "enemy.h"

Game::Game() {}

void Game::interpretChar(int floorNum, std::shared_ptr<Cell> pos, char c)
{
  switch (c)
  {
  case '@':
    floors[floorNum].setStart(pos);
    break;
  case '\\':
    floors[floorNum].setStairway(pos);
    break;
  case 'H':
    {
      std::shared_ptr<Enemy> h = std::make_shared<Human>(pos);
      floors[floorNum].addEnemy(h);
      break;
    }
  case 'W':
    {
      std::shared_ptr<Enemy> w = std::make_shared<Dwarf>(pos);
      floors[floorNum].addEnemy(w);
      break;
    }
  case 'E':
    {
      std::shared_ptr<Enemy> e = std::make_shared<Elf>(pos);
      floors[floorNum].addEnemy(e);
      break;
    }
  case 'O':
    {
      std::shared_ptr<Enemy> o = std::make_shared<Merchant>(pos);
      floors[floorNum].addEnemy(o);
      break;
    }
  case 'M':
    {
      std::shared_ptr<Enemy> m = std::make_shared<Human>(pos);
      floors[floorNum].addEnemy(m);
      break;
    }
  case 'D':
    {
      std::shared_ptr<Enemy> d = std::make_shared<Dragon>(pos);
      floors[floorNum].addEnemy(d);
      break;
    }
  case 'L':
    {
      std::shared_ptr<Enemy> l = std::make_shared<Halfling>(pos);
      floors[floorNum].addEnemy(l);
      break;
    }
  default:
    break;
  }
}

void Game::loadPlainFloors(std::string fileName)
{
  std::ifstream ifs;
  std::string line;
  char c;
  for (int floorNum = 0; floorNum < numFloors; floorNum++)
  {
    ifs.open(fileName + ".txt");
    for (int i = 0; i < floors[floorNum].getNumRows(); i++)
    {
      std::getline(ifs, line);
      std::istringstream iss{line};
      for (int j = 0; j < floors[floorNum].getNumCols(); j++)
      {
        iss >> std::noskipws >> c;
        floors[floorNum].setCell(i, j, c);
      }
    }
    ifs.close();
  }
}

void Game::generateChambersAndObjects()
{
  const std::string plainFloorChamberCoordinates = "coordinates.txt";
  for (int i = 0; i < numFloors; i++)
  {
    std::ifstream ifs;
    std::string line;
    int rowCoordinate;
    int colCoordinate;

    ifs.open(plainFloorChamberCoordinates);
    int currChamber = 0;
    while (std::getline(ifs, line))
    {
      if (line != "chamber")
      {
        std::istringstream iss(line);
        iss >> rowCoordinate;
        iss >> colCoordinate;
        floors[i].addCellToChamber(floors[i].getCell(rowCoordinate, colCoordinate), currChamber);
      } else {
        currChamber++;
      }
    }
    floors[i].populateFloor();
  }
}

void Game::loadCustomFloors(std::string fileName)
{
  std::ifstream ifs;
  std::string line;
  char c;
  ifs.open(fileName + ".txt");
  for (int floorNum = 0; floorNum < numFloors; floorNum++)
  {
    for (int i = 0; i < floors[floorNum].getNumRows(); i++)
    {
      while (std::getline(ifs, line))
      { // skip any whitespace lines
        if (line.find_first_not_of(' ') != std::string::npos)
          break;
      }
      std::istringstream iss{line};
      for (int j = 0; j < floors[floorNum].getNumCols(); j++)
      {
        iss >> std::noskipws >> c;
        floors[floorNum].setCell(i, j, c);
        interpretChar(floorNum, floors[floorNum].getCell(i, j), c);
      }
    }
  }
}

void Game::loadFloors(std::string fileName, bool isCustom)
{
  if (isCustom)
  {
    loadCustomFloors(fileName);
  }
  else
  {
    loadPlainFloors(fileName);
    generateChambersAndObjects();
  }
}

void Game::setPlayer(std::string pcRace)
{
  if (pcRace == "s")
  {
    player = std::make_shared<Shade>();
  }
  else if (pcRace == "d")
  {
    player = std::make_shared<Drow>();
  }
  else if (pcRace == "v")
  {
    player = std::make_shared<Vampire>();
  }
  else if (pcRace == "t")
  {
    player = std::make_shared<Troll>();
  }
  else if (pcRace == "g")
  {
    player = std::make_shared<Goblin>();
  }
}

void Game::drawTurn()
{
  floors[curFloor].draw();
  std::cout << "Race: " << player->getRace() << "      Gold: " << player->getGold();
  std::cout << std::setw(60 - player->getRace().length() -
                         std::to_string(player->getGold()).length());
  std::cout << "Floor " << curFloor + 1 << std::endl;
  player->displayStats();
  std::cout << "Action: insert last turn's events here." << std::endl;
}

std::vector<std::string> extractWords(std::string command)
{
  std::vector<std::string> result;
  std::string nextWord;
  std::istringstream iss{command};
  while (iss >> nextWord)
  {
    result.push_back(nextWord);
  }
  return result;
}

bool isDirectional(std::string s)
{
  return (s == "no") || (s == "so") || (s == "ea") || (s == "we") ||
         (s == "ne") || (s == "nw") || (s == "se") || (s == "sw");
}

// checks if command is syntactically valid and is possible to execute
bool Game::isValidCommand(std::vector<std::string> words)
{
  if (words.size() == 1)
  {
    if (isDirectional(words[0]))
    {
      if (floors[curFloor].isValidPlayerMove(player->getPos(), words[0]))
      {
        return true;
      }
      else
      {
        std::cout << "Player can only move to unoccupied ";
        std::cout << "floor tile(.), doorway(+), passage(#), ";
        std::cout << "stairway(\\), or gold(G)." << std::endl;
      }
    }
    else if (words[0] == "f" || words[0] == "r" || words[0] == "q" || words[0] == "NEXT")
    {
      return true;
    }
  }
  else if (words.size() == 2)
  {
    if (words[0] == "u")
    {
      if (isDirectional(words[1]))
      {
        std::shared_ptr<Cell> newPos = floors[curFloor].getCellInDirection(player->getPos(), words[1]);
        if (newPos->getCellType() == PotionTile) {
          return true;
        } else {
          std::cout << "No potion found in specified direction." << std::endl;
        }
      }
    }
    else if (words[0] == "a")
    {
      if (isDirectional(words[1]))
      {
        std::shared_ptr<Cell> newPos = floors[curFloor].getCellInDirection(player->getPos(), words[1]);
        if (newPos->getCellType() == EnemyTile) {
          return true;
        } else {
          std::cout << "No enemy found in specified direction." << std::endl;
        }
      }
    }
  }
  return false;
}

// assume that command in words is valid and possible to execute
exitCodes Game::interpretCommand(std::vector<std::string> words)
{
  if (words.size() == 1)
  {
    if (isDirectional(words[0]))
    {
      floors[curFloor].movePlayer(player, words[0]);
      // process consume gold
    }
    else if (words[0] == "f")
    {
      // toggles enemies' random movement (i.e. stops movement, then resumes
      // movement)
    }
    else if (words[0] == "r")
    {
      return Restart;
    }
    else if (words[0] == "q")
    {
      return Quit;
    } else if (words[0] == "NEXT") {
      floors[curFloor].setStairway(player->getPos());
    }
  }
  else if (words.size() == 2)
  { // assume words[1] is a valid direction and has potion/enemy
    if (words[0] == "u")
    {
    }
    else if (words[0] == "a")
    {
    }
  }
  return Continue;
}

exitCodes Game::startGame(std::string pcRace)
{
  std::string command;
  std::vector<std::string> words;

  setPlayer(pcRace);
  for (int i = 0; i < 5; i++)
  {
    curFloor = i;
    player->setPos(floors[i].getStart());
    floors[i].getStart()->attachPlayer(player);
    while (!floors[i].isPCOnStairway(player->getPos()))
    {
      drawTurn();

      // loop for getting valid command
      std::getline(std::cin, command);
      words = extractWords(command);
      while (!isValidCommand(words))
      {
        std::cout << "Invalid Command." << std::endl;
        std::getline(std::cin, command);
        words = extractWords(command);
      }

      // assume command is safe to be executed
      exitCodes exitCode = interpretCommand(words);
      if (exitCode == Quit || exitCode == Restart)
      {
        return exitCode;
      }
    }
  }
  return Win;
}

int Game::getScore() { return player->getScore(); }
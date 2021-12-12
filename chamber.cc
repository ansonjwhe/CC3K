#include "chamber.h"
#include "cell.h"

std::shared_ptr<Cell> Chamber::getRandomEmptyCell()
{
  int random = rand() % cells.size();
  std::shared_ptr<Cell> newCell = cells[random];
  cells.erase(cells.begin() + random);
  return newCell;
}

void Chamber::addCell(std::shared_ptr<Cell> cell)
{
  cells.push_back(cell);
}
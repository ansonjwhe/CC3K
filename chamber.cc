#include "chamber.h"

std::shared_ptr<Cell> Chamber::getRandomEmptyCell()
{
  int random = rand() % cells.size();
  return cells[random];
}

void Chamber::addCell(std::shared_ptr<Cell> cell)
{
  cells.push_back(cell);
}
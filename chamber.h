#ifndef CHAMBER_H
#define CHAMBER_H
#include <memory>
#include <vector>

class Cell;

class Chamber
{
  std::vector<std::shared_ptr<Cell>> cells;

public:
  void addCell(std::shared_ptr<Cell>);
  std::shared_ptr<Cell> getRandomEmptyCell();
};

#endif
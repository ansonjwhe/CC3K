#ifndef ITEM_H
#define ITEM_H

#include <memory>

class Player;
class Cell;
class Item{
  protected:
    int val;
    std::shared_ptr<Cell> pos;
  public:
    Item(int v, std::shared_ptr<Cell> pos);
    virtual void consumedBy(std::shared_ptr<Player>) = 0;
    int getVal();
};

#endif
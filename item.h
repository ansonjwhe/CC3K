#ifndef ITEM_H
#define ITEM_H

#include "player.h"
#include <memory>

class Item{
  int val;
  std::shared_ptr<Cell> pos;
  public:
    Item(int v, std::shared_ptr<Cell> pos);
    virtual void consumedBy(Player) = 0;  
};

#endif
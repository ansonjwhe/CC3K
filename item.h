#ifndef ITEM_H
#define ITEM_H
#include "player.h"

class Item{
  virtual void consumedBy(Player) = 0;  
};

#endif
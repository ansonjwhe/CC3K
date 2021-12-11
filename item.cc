#include "item.h"

Item::Item(int v, std::shared_ptr<Cell> pos) : val{v}, pos{pos} {}

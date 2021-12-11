#include "gold.h"
#include "player.h"
#include "item.h"

Gold::Gold(int v, std::shared_ptr<Cell> pos) : Item{v, pos} {}
SmallPile::SmallPile(std::shared_ptr<Cell> pos) : Gold{1, pos} {}
NormalPile::NormalPile(std::shared_ptr<Cell> pos) : Gold{2, pos} {}
MerchantHoard::MerchantHoard(std::shared_ptr<Cell> pos) : Gold{4, pos} {}
DragonHoard::DragonHoard(std::shared_ptr<Cell> pos) : Gold{6, pos}, slain{false} {}

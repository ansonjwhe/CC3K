#include "gold.h"
#include "player.h"
#include "item.h"

Gold::Gold(int v, std::shared_ptr<Cell> pos) : Item{v, pos} {}
SmallPile::SmallPile(std::shared_ptr<Cell> pos) : Gold{1, pos} {}
NormalPile::NormalPile(std::shared_ptr<Cell> pos) : Gold{2, pos} {}
MerchantHoard::MerchantHoard(std::shared_ptr<Cell> pos) : Gold{4, pos} {}
DragonHoard::DragonHoard(std::shared_ptr<Cell> pos) : Gold{6, pos}, slain{false} {}

static std::shared_ptr<Potion> getRandGold(std::shared_ptr<Cell> pos)
{
    // 5/8 of goldType is allocated for normal, 1/8 for dragon hoard, 1/4 for small hoard
    int gold = rand() % 8;
    if (gold <= 4)
    {
        return std::make_shared<NormalPile>(pos);
    }
    else if (gold <= 5)
    {
        return std::make_shared<DragonPile>(pos);
    }
    else
    {
        return std::make_shared<SmallPile>(pos);
    }
}
#include "gold.h"
#include "player.h"
#include "item.h"

Gold::Gold(int v, std::shared_ptr<Cell> pos) : Item{v, pos} {}
SmallPile::SmallPile(std::shared_ptr<Cell> pos) : Gold{1, pos} {}
NormalPile::NormalPile(std::shared_ptr<Cell> pos) : Gold{2, pos} {}
MerchantHoard::MerchantHoard(std::shared_ptr<Cell> pos) : Gold{4, pos} {}
DragonHoard::DragonHoard(std::shared_ptr<Cell> pos) : Gold{6, pos} {}

std::shared_ptr<Gold> Gold::getRandGold(std::shared_ptr<Cell> pos)
{
    // 5/8 of goldType is allocated for normal, 1/8 for dragon hoard, 1/4 for small hoard
    int gold = rand() % 8;
    if (gold <= 4)
    {
        return std::make_shared<NormalPile>(pos);
    }
    else if (gold <= 5)
    {
        return std::make_shared<DragonHoard>(pos);
    }
    else
    {
        return std::make_shared<SmallPile>(pos);
    }
}


void SmallPile::consumedBy(std::shared_ptr<Player> player) {
    player->consume(*this);
}

void NormalPile::consumedBy(std::shared_ptr<Player> player) {
    player->consume(*this);
}

void MerchantHoard::consumedBy(std::shared_ptr<Player> player) {
    player->consume(*this);
}

void DragonHoard::consumedBy(std::shared_ptr<Player> player) {
    player->consume(*this);
}
#include "potion.h"
#include "player.h"
#include "item.h"
#include <memory>

Potion::Potion(int v, std::shared_ptr<Cell> pos) : Item{v, pos} {}
RH::RH(std::shared_ptr<Cell> pos) : Potion{10, pos} {}
BA::BA(std::shared_ptr<Cell> pos) : Potion{5, pos} {}
BD::BD(std::shared_ptr<Cell> pos) : Potion{5, pos} {}
PH::PH(std::shared_ptr<Cell> pos) : Potion{-10, pos} {}
WA::WA(std::shared_ptr<Cell> pos) : Potion{-5, pos} {}
WD::WD(std::shared_ptr<Cell> pos) : Potion{-5, pos} {}

std::shared_ptr<Potion> Potion::getRandPotion(std::shared_ptr<Cell> pos)
{
    switch (rand() % 6)
    {
    case 0:
        return std::make_shared<RH>(pos);
    case 1:
        return std::make_shared<BA>(pos);
    case 2:
        return std::make_shared<BD>(pos);
    case 3:
        return std::make_shared<PH>(pos);
    case 4:
        return std::make_shared<WA>(pos);
    case 5:
    default:
        return std::make_shared<WD>(pos);
    }
}

void RH::consumedBy(std::shared_ptr<Player> player) {
    player->consume(*this);
}

void BA::consumedBy(std::shared_ptr<Player> player) {
    player->consume(*this);
}

void BD::consumedBy(std::shared_ptr<Player> player) {
    player->consume(*this);
}

void PH::consumedBy(std::shared_ptr<Player> player) {
    player->consume(*this);
}

void WA::consumedBy(std::shared_ptr<Player> player) {
    player->consume(*this);
}

void WD::consumedBy(std::shared_ptr<Player> player) {
    player->consume(*this);
}
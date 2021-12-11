#include "potion.h"
#include "player.h"
#include "item.h"

Potion::Potion(int v, std::shared_ptr<Cell> pos) : Item{v, pos} {}
RH::RH(std::shared_ptr<Cell> pos) : Potion{10, pos} {}
BA::BA(std::shared_ptr<Cell> pos) : Potion{5, pos} {}
BD::BD(std::shared_ptr<Cell> pos) : Potion{5, pos} {}
PH::PH(std::shared_ptr<Cell> pos) : Potion{-10, pos} {}
WA::WA(std::shared_ptr<Cell> pos) : Potion{-5, pos} {}
WD::WD(std::shared_ptr<Cell> pos) : Potion{-5, pos} {}

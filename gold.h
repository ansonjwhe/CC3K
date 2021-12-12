#ifndef GOLD_H
#define GOLD_H

#include "item.h"

class Player;

class Gold : public Item
{
public:
    Gold(int v, std::shared_ptr<Cell> pos);
    virtual void consumedBy(std::shared_ptr<Player>) = 0; // virtual
    static std::shared_ptr<Gold> getRandGold(std::shared_ptr<Cell>);
};

class SmallPile : public Gold
{
public:
    SmallPile(std::shared_ptr<Cell> pos);
    void consumedBy(std::shared_ptr<Player>);
};

class NormalPile : public Gold
{
public:
    NormalPile(std::shared_ptr<Cell> pos);
    void consumedBy(std::shared_ptr<Player>);
};

class MerchantHoard : public Gold
{
public:
    MerchantHoard(std::shared_ptr<Cell> pos);
    void consumedBy(std::shared_ptr<Player>);
};

class DragonHoard : public Gold
{
    bool slain = false;

public:
    DragonHoard(std::shared_ptr<Cell> pos);
    void consumedBy(std::shared_ptr<Player>);
};

#endif

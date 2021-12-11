#ifndef GOLD_H
#define GOLD_H

#include "item.h"

class Player;

class Gold : public Item {
    public:
        Gold(int v, std::shared_ptr<Cell> pos);
        void consumedBy(Player); // virtual
};

class SmallPile : public Gold {
    public:
        SmallPile(std::shared_ptr<Cell> pos);
        void consumedBy(Player);
};

class NormalPile : public Gold {
    public:
        NormalPile(std::shared_ptr<Cell> pos);
        void consumedBy(Player);
};

class MerchantHoard : public Gold {
    public:
        MerchantHoard(std::shared_ptr<Cell> pos);
        void consumedBy(Player);
};

class DragonHoard : public Gold {
    bool slain;
    public:
        DragonHoard(std::shared_ptr<Cell> pos);
        void consumedBy(Player);
};

#endif

#ifndef POTION_H
#define POTION_H

#include "item.h"
#include <memory>

class Player;

class Potion : public Item
{
public:
    Potion(int v, std::shared_ptr<Cell> pos);
    void consumedBy(Player); // virtual
    static std::shared_ptr<Potion> getRandPotion(std::shared_ptr<Cell>);
};

class RH : public Potion
{
public:
    RH(std::shared_ptr<Cell> pos);
    void consumedBy(Player);
};

class BA : public Potion
{
public:
    BA(std::shared_ptr<Cell> pos);
    void consumedBy(Player);
};

class BD : public Potion
{
public:
    BD(std::shared_ptr<Cell> pos);
    void consumedBy(Player);
};

class PH : public Potion
{
public:
    PH(std::shared_ptr<Cell> pos);
    void consumedBy(Player);
};

class WA : public Potion
{
public:
    WA(std::shared_ptr<Cell> pos);
    void consumedBy(Player);
};

class WD : public Potion
{
public:
    WD(std::shared_ptr<Cell> pos);
    void consumedBy(Player);
};

#endif

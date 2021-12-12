#ifndef POTION_H
#define POTION_H

#include "item.h"
#include <memory>

class Player;

class Potion : public Item
{
public:
    Potion(int v, std::shared_ptr<Cell> pos);
    virtual void consumedBy(std::shared_ptr<Player>) = 0; // virtual
    static std::shared_ptr<Potion> getRandPotion(std::shared_ptr<Cell>);
};

class RH : public Potion
{
public:
    RH(std::shared_ptr<Cell> pos);
    void consumedBy(std::shared_ptr<Player>);
};

class BA : public Potion
{
public:
    BA(std::shared_ptr<Cell> pos);
    void consumedBy(std::shared_ptr<Player>);
};

class BD : public Potion
{
public:
    BD(std::shared_ptr<Cell> pos);
    void consumedBy(std::shared_ptr<Player>);
};

class PH : public Potion
{
public:
    PH(std::shared_ptr<Cell> pos);
    void consumedBy(std::shared_ptr<Player>);
};

class WA : public Potion
{
public:
    WA(std::shared_ptr<Cell> pos);
    void consumedBy(std::shared_ptr<Player>);
};

class WD : public Potion
{
public:
    WD(std::shared_ptr<Cell> pos);
    void consumedBy(std::shared_ptr<Player>);
};

#endif

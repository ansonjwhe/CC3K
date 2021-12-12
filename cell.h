#ifndef CELL_H
#define CELL_H

#include <memory>

class Player;
class Potion;
class Gold;
class Enemy;

enum cellType { NonFloorTile, EmptyFloorTile, PlayerTile, PotionTile, GoldTile, EnemyTile };
class Cell {
    const int row;
    const int col;
    char trueVal;
    char val;
    cellType type;
    std::shared_ptr<Player> playerPtr = nullptr;
    std::shared_ptr<Potion> potionPtr = nullptr;
    std::shared_ptr<Gold> goldPtr = nullptr;
    std::shared_ptr<Enemy> enemyPtr = nullptr;

    public:
        Cell(int row, int col, char v);
        int getRow();
        int getCol();
        char getTrueVal();
        void setTrueVal(char c);
        char getVal();
        void setVal(char c);

        cellType getCellType();
        void setTypeToTrueVal();
        void attachPlayer(std::shared_ptr<Player> ptr);
        void attachPotion(std::shared_ptr<Potion> ptr);
        void attachGold(std::shared_ptr<Gold> ptr);
        void attachEnemy(std::shared_ptr<Enemy> ptr);
};

#endif

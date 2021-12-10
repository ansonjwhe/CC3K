#include "player.h"

Player::Player(char playerRace, int h, int a, int d) : Character{h, a, d} {}
Shade::Shade() : Player("s", 125, 25, 25);
Drow::Drow() : Player("d", 150, 25, 15);
Vampire::Vampire() : Player("v", 50, 25, 25);
Troll::Troll() : Player("t", 120, 25, 15);
Goblin::Goblin() : Player("g", 110, 15, 20);

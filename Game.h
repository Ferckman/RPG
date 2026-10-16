#pragma once
#include <memory>
#include "Player.h"
#include "Enemy.h"

class Game {
private:
    std::unique_ptr<Player> player;
    std::unique_ptr<Enemy> enemy;
    int turnCount;

    void processPlayerTurn();
    void processEnemyTurn();

public:
    Game();
    ~Game() = default;

    void run(); // Main game loop entry point
};
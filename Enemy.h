#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
private:
    int xpReward;

public:
    Enemy(const std::string& name, int health, int attackPower, int xpReward);
    ~Enemy() override = default;

    // Basic AI behavior method
    void takeTurn(Character& target);

    int getXpReward() const { return xpReward; }
};

#endif // ENEMY_H
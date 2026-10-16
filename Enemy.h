#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
public:
    Enemy(const std::string& name, int health, int attackPower);
    ~Enemy() override = default;

    // Basic AI behavior method
    void takeTurn(Character& target);
    void attack(Character& target) override;
};

#endif // ENEMY_H
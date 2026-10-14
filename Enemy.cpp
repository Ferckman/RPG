#include "Enemy.h"

Enemy::Enemy(const std::string& name, int health, int attackPower, int xpReward)
    : Character(name, health, attackPower), xpReward(xpReward) {}

void Enemy::takeTurn(Character& target) {
    if (!isAlive()) return;

    // Simple AI decision logic
    std::cout << "\n[Enemy Turn] " << name << " is deciding its action...\n";
    attack(target);
}
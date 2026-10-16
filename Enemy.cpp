#include "Enemy.h"

Enemy::Enemy(const std::string& name, int health, int attackPower)
    : Character(name, health, attackPower) {}

void Enemy::takeTurn(Character& target) {
    if (!isAlive()) return;

    // Simple AI decision logic
    std::cout << "\n[Enemy Turn] " << name << " is deciding its action...\n";
    attack(target);
}

// Enemy attack implementation
void Enemy::attack(Character& target) {
    std::cout << name << " strikes back at " << target.getName() << " for " << attackPower << " damage!\n";
    target.takeDamage(attackPower);
}
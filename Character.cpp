#include "Character.h"

Character::Character(const std::string& name, int health, int attackPower)
    : name(name), health(health), maxHealth(health), attackPower(attackPower) {}

void Character::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
    
    std::cout << name << " takes " << amount << " damage. "
              << "(Remaining Health: " << health << "/" << maxHealth << ")\n";
}

void Character::attack(Character& target) {
    std::cout << name << " attacks " << target.getName() << "!\n";
    target.takeDamage(attackPower);
}

bool Character::isAlive() const {
    return health > 0;
}
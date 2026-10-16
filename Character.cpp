#include "Character.h"
#include <iostream>

void Character::takeDamage(int amount) {
    int damageToHealth = amount;

    // Check if the character has active armor to absorb incoming damage
    if (armor > 0) {
        if (armor >= amount) {
            // Armor completely absorbs the incoming attack
            armor -= amount;
            std::cout << name << "'s armor fully absorbed " << amount << " damage! Remaining Armor: " << armor << "\n";
            return; // Exit early, health is untouched
        } else {
            // Armor absorbs what it can and breaks completely
            int absorbed = armor;
            damageToHealth = amount - armor;
            armor = 0; // Armor is shattered
            std::cout << name << "'s armor absorbed " << absorbed << " damage and broke! Remaining damage to HP: " << damageToHealth << "\n";
        }
    }

    // Apply remaining damage directly to health
    health -= damageToHealth;
    if (health < 0) {
        health = 0;
    }

    std::cout << name << " took " << damageToHealth << " damage to HP. Current HP: " << health << "/" << maxHealth << "\n";
}

void Character::heal(int amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth;
    std::cout << name << " healed for " << amount << ". HP: " << health << "/" << maxHealth << "\n";
}

void Character::addStatusEffect(std::unique_ptr<StatusEffect> effect) {
    std::cout << name << " is now under the effect of " << effect->getName() << "!\n";
    activeEffects.push_back(std::move(effect));
}

void Character::updateEffects() {
    auto it = activeEffects.begin();
    while (it != activeEffects.end()) {
        // Apply current effect
        (*it)->applyEffect(*this);
        (*it)->decrementDuration();

        // If expired, remove effect and erase from vector (std::unique_ptr cleans up memory automatically)
        if ((*it)->isExpired()) {
            (*it)->removeEffect(*this);
            it = activeEffects.erase(it);
        } else {
            ++it;
        }
    }
}
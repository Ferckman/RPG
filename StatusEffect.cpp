#include "StatusEffect.h"
#include "Character.h"

// PoisonEffect implementation
void PoisonEffect::applyEffect(Character& target) {
    std::cout << "[Effect] " << target.getName() << " takes " 
              << damagePerTurn << " poison damage! (" 
              << duration << " turns remaining)\n";
    target.takeDamage(damagePerTurn);
}
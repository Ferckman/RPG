#pragma once
#include <string>
#include <vector>
#include <memory>
#include "StatusEffect.h"

class Character {
protected:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;
    int armor;
    
    // List of active effects managed via smart pointers
    std::vector<std::unique_ptr<StatusEffect>> activeEffects;

public:
    Character(const std::string& nameVal, int healthVal, int attackVal, int armorVal = 0)
        : name(nameVal), health(healthVal), maxHealth(healthVal), 
          attackPower(attackVal), armor(armorVal) {}

    virtual ~Character() = default;

    virtual void attack(Character& target) = 0;
    virtual void takeDamage(int amount);

    // Status Effect Management
    void addStatusEffect(std::unique_ptr<StatusEffect> effect);
    void updateEffects();

    // Getters and Setters
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    bool isAlive() const { return health > 0; }
    int getArmor() const { return armor; }
    void setArmor(int val) { armor = val; }
    void heal(int amount);
};
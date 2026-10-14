#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

// Base class representing any entity in the game
class Character {
protected:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;

public:
    // Constructor
    Character(const std::string& name, int health, int attackPower);

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Character() = default;

    // Core gameplay methods
    virtual void takeDamage(int amount);
    virtual void attack(Character& target);
    
    bool isAlive() const;

    // Getters
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
};

#endif // CHARACTER_H
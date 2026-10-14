#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Item.h"
#include <vector>
#include <memory>

class Player : public Character {
private:
    int mana;
    int maxMana;
    // Ownership of Items managed cleanly via unique_ptr (automatic cleanup, zero leaks)
    std::vector<std::unique_ptr<Item>> inventory;

public:
    Player(const std::string& name, int health, int attackPower, int mana);
    ~Player() override = default;

    // Inventory Management Methods
    void addItem(std::unique_ptr<Item> item);
    void showInventory() const;
    void useItem(size_t index);

    // Player Special Action
    void heal(int amount);

    // Getters
    int getMana() const { return mana; }
    int getMaxMana() const { return maxMana; }
};

#endif // PLAYER_H
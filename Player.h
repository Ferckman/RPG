#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Item.h"
#include <vector>
#include <memory>

class Player : public Character {
private:
    // Ownership of Items managed cleanly via unique_ptr (automatic cleanup, zero leaks)
    std::vector<std::unique_ptr<Item>> inventory;

public:
    Player(const std::string& name, int health, int attackPower);
    ~Player() override = default;

    // Inventory Management Methods
    void addItem(std::unique_ptr<Item> item);
    void showInventory() const;

    // Player Special Action
    void attack(Character& target) override;
    bool useItem(size_t index, Character& target); // Returns true if item was used successfully
    void heal(int amount);
};

#endif // PLAYER_H
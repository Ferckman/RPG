#include "Player.h"

Player::Player(const std::string& name, int health, int attackPower, int mana)
    : Character(name, health, attackPower), mana(mana), maxMana(mana) {}

void Player::addItem(std::unique_ptr<Item> item) {
    std::cout << name << " acquired item: " << item->getName() << "\n";
    // std::move transfers ownership of the unique_ptr into the inventory vector
    inventory.push_back(std::move(item));
}

void Player::showInventory() const {
    std::cout << "\n--- " << name << "'s Inventory ---\n";
    if (inventory.empty()) {
        std::cout << "(Inventory is empty)\n";
        return;
    }

    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << "[" << i + 1 << "] " << inventory[i]->getName() 
                  << " (Value: " << inventory[i]->getValue() << ")\n";
    }
}

void Player::useItem(size_t index) {
    if (index >= inventory.size()) {
        std::cout << "Invalid item selection!\n";
        return;
    }

    // Access the item
    auto& item = inventory[index];
    std::cout << name << " used " << item->getName() << "!\n";

    if (item->getType() == ItemType::HEALING) {
        heal(item->getValue());
    }

    // Remove the item from inventory. unique_ptr will automatically deallocate memory!
    inventory.erase(inventory.begin() + index);
}

void Player::heal(int amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth;
    std::cout << name << " healed for " << amount << " HP. Current Health: " 
              << health << "/" << maxHealth << "\n";
}
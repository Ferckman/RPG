#include "Player.h"

Player::Player(const std::string& name, int health, int attackPower)
    : Character(name, health, attackPower) {}

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

// Player attack implementation
void Player::attack(Character& target) {
        std::cout << name << " attacks " << target.getName() << " with a sword for " << attackPower << " damage!\n";
        target.takeDamage(attackPower);
}

bool Player::useItem(size_t index, Character& target) {
    if (index >= inventory.size()) {
        std::cout << "Invalid item selection!\n";
        return false;
    }

    // Access the item using smart pointer reference
    auto& item = inventory[index];
    std::cout << name << " uses " << item->getName() << "!\n";

    if (item->getType() == ItemType::HEALING) {
        heal(item->getValue());
    } 
    else if (item->getType() == ItemType::EFFECT) {
        target.addStatusEffect(std::make_unique<PoisonEffect>(item->getEffectTurns(), item->getValue()));
        std::cout << target.getName() << " has been poisoned by the arrow!\n";
    }

    // Remove the item from inventory. unique_ptr automatically deallocates memory!
    inventory.erase(inventory.begin() + index);
    return true;
}

void Player::heal(int amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth;
    std::cout << name << " healed for " << amount << " HP. Current Health: " 
              << health << "/" << maxHealth << "\n";
}
#include <iostream>
#include <memory>
#include "Player.h"
#include "Enemy.h"

void displayMenu() {
    std::cout << "\n--- CHOOSE YOUR ACTION ---\n";
    std::cout << "1. Attack\n";
    std::cout << "2. Open Inventory & Use Item\n";
    std::cout << "3. Skip Turn\n";
    std::cout << "Select (1-3): ";
}

int main() {
    std::cout << "===========================================\n";
    std::cout << "   TURN-BASED RPG CORE - GAMEPLAY SYSTEM   \n";
    std::cout << "===========================================\n\n";

    // Setup Combatants
    Player player("Hero", 80, 18, 30);
    Enemy enemy("Orc Warrior", 60, 12, 100);

    // Initial Inventory Setup
    player.addItem(std::make_unique<Item>("Minor Health Potion", ItemType::HEALING, 25));
    player.addItem(std::make_unique<Item>("Greater Health Potion", ItemType::HEALING, 50));

    std::cout << "A wild " << enemy.getName() << " appears!\n";

    // Main Gameplay Loop
    while (player.isAlive() && enemy.isAlive()) {
        std::cout << "\n===========================================\n";
        std::cout << player.getName() << " HP: " << player.getHealth() << "/" << player.getMaxHealth() << "\n";
        std::cout << enemy.getName() << " HP: " << enemy.getHealth() << "/" << enemy.getMaxHealth() << "\n";

        displayMenu();
        int choice;
        std::cin >> choice;

        bool validAction = false;

        switch (choice) {
            case 1:
                std::cout << "\n[Player Turn]\n";
                player.attack(enemy);
                validAction = true;
                break;
            case 2:
                player.showInventory();
                std::cout << "Enter item number to use (or 0 to cancel): ";
                int itemChoice;
                std::cin >> itemChoice;
                if (itemChoice > 0) {
                    player.useItem(static_cast<size_t>(itemChoice - 1));
                    validAction = true;
                }
                break;
            case 3:
                std::cout << "\n" << player.getName() << " waits and guards.\n";
                validAction = true;
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
                break;
        }

        // Enemy reacts if still alive and player performed a valid action
        if (validAction && enemy.isAlive()) {
            enemy.takeTurn(player);
        }
    }

    // End Game Resolution
    std::cout << "\n===========================================\n";
    if (player.isAlive()) {
        std::cout << "VICTORY! You defeated the " << enemy.getName() << "!\n";
        std::cout << "Gained " << enemy.getXpReward() << " XP.\n";
    } else {
        std::cout << "DEFEAT! " << player.getName() << " was slain...\n";
    }

    std::cout << "\n=== Shutting down system and cleaning memory ===\n";
    return 0;
}
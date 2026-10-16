#include "Game.h"
#include "Item.h"
#include "StatusEffect.h"
#include <iostream>

Game::Game() : turnCount(1) {
    // Initialize player and enemy using smart pointers
    player = std::make_unique<Player>("Hero", 120, 20);
    enemy = std::make_unique<Enemy>("Goblin", 50, 15);

    // Add initial inventory items to player
    player->addItem(std::make_unique<Item>("Potion", ItemType::HEALING, 25, 0));
    player->addItem(std::make_unique<Item>("Great Potion", ItemType::HEALING, 50, 0));
    player->addItem(std::make_unique<Item>("Poison Arrow", ItemType::EFFECT, 5, 2));
}

void Game::run() {
    std::cout << "=== TURN-BASED RPG CORE ===\n\n";

    // Main Game Loop
    while (player->isAlive() && enemy->isAlive()) {
        std::cout << "\n--------------------------------------------------\n";
        std::cout << "TURN " << turnCount << "\n";
        std::cout << "--------------------------------------------------\n";

        // 1. Process Player status effects at the start of player's turn
        std::cout << "\n[Status Effects - Player]\n";
        player->updateEffects();

        // 2. Player Turn
        processPlayerTurn();

        // Check victory after player actions
        if (!enemy->isAlive()) {
            std::cout << "\n*** VICTORY! " << enemy->getName() << " was defeated! ***\n";
            break;
        }

        // 3. Enemy Turn
        processEnemyTurn();

        // Check defeat after enemy actions
        if (!player->isAlive()) {
            std::cout << "\n*** DEFEAT! " << player->getName() << " was slain... ***\n";
            break;
        }

        turnCount++;
    }

    std::cout << "\n=== GAME OVER ===\n";
}

void Game::processPlayerTurn() {
    bool playerTurnActive = true;
    while (playerTurnActive && player->isAlive()) {
        std::cout << "\n--- PLAYER TURN ---\n";
        std::cout << player->getName() << " HP: " << player->getHealth() 
                  << " | Armor: " << player->getArmor() << "\n";
        std::cout << enemy->getName() << " HP: " << enemy->getHealth() 
                  << " | Armor: " << enemy->getArmor() << "\n";
        std::cout << "\nActions:\n1. Attack\n2. Use Item\n3. Skip Turn\nChoose action: ";

        int choice;
        std::cin >> choice;

        // Input sanitization: handle non-numeric inputs (letters) gracefully
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "[Error] Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            player->attack(*enemy);
            playerTurnActive = false;
        } 
        else if (choice == 2) {
            player->showInventory();
            std::cout << "Select item number to use (-1 to cancel): ";
            int itemNum;
            std::cin >> itemNum;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "[Error] Invalid input! Returning to turn menu.\n";
                continue;
            }

            if (itemNum == -1) {
                continue;
            }

            size_t index = static_cast<size_t>(itemNum - 1);

            if (player->useItem(index, *enemy)) {
                playerTurnActive = false; 
            } else {
                continue; 
            }
        } 
        else if (choice == 3) {
            std::cout << player->getName() << " skips their turn.\n";
            playerTurnActive = false;
        } 
        else {
            std::cout << "[Warning] Invalid choice! Please select 1, 2, or 3.\n";
        }
    }
}

void Game::processEnemyTurn() {
    std::cout << "\n--- ENEMY TURN ---\n";
    
    // Process Enemy status effects (like Poison) right before they act
    std::cout << "\n[Status Effects - Enemy]\n";
    enemy->updateEffects();

    // Check if poison defeated the enemy before they can attack
    if (!enemy->isAlive()) {
        return; // Exit enemy turn early if dead
    }

    // Enemy attacks player
    enemy->attack(*player);
}
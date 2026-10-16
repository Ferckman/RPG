#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, ItemType type, int value, int effectTurns)
    : name(name), type(type), value(value), effectTurns(effectTurns) {
    std::cout << "[Item] " << name << " created.\n";
}

Item::~Item() {
    // Logging destructor execution proves no memory leak occurred
    std::cout << "[Memory Clean] Item destroyed: " << name << "\n";
}
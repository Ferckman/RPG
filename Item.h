#ifndef ITEM_H
#define ITEM_H

#include <string>

enum class ItemType {
    HEALING,
    BUFF,
    WEAPON
};

class Item {
private:
    std::string name;
    ItemType type;
    int value; // Healing amount, attack boost, etc.

public:
    Item(const std::string& name, ItemType type, int value);
    ~Item(); // We will log destructor calls to prove proper memory cleanup

    // Getters
    std::string getName() const { return name; }
    ItemType getType() const { return type; }
    int getValue() const { return value; }
};

#endif // ITEM_H
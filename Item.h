#ifndef ITEM_H
#define ITEM_H

#include <string>

enum class ItemType {
    HEALING,
    EFFECT
};

class Item {
private:
    std::string name;
    ItemType type;
    int value;
    int effectTurns;

public:
    Item(const std::string& name, ItemType type, int value, int effectTurns = 0);
    ~Item(); // We will log destructor calls to prove proper memory cleanup

    // Getters
    std::string getName() const { return name; }
    ItemType getType() const { return type; }
    int getValue() const { return value; }
    int getEffectTurns() const { return effectTurns; }
};

#endif // ITEM_H
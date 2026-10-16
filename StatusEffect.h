#pragma once
#include <string>
#include <iostream>

// Forward declaration to avoid circular dependencies
class Character;

class StatusEffect {
protected:
    std::string name;
    int duration; // Remaining duration in turns

public:
    StatusEffect(const std::string& effectName, int durationTurns)
        : name(effectName), duration(durationTurns) {}

    virtual ~StatusEffect() = default;

    // Polymorphic methods
    virtual void applyEffect(Character& target) = 0;
    virtual void removeEffect(Character& target) {}

    void decrementDuration() { duration--; }
    bool isExpired() const { return duration <= 0; }
    int getDuration() const { return duration; }
    std::string getName() const { return name; }
};

// --- CONCRETE EFFECT 1: Poison (Debuff) ---
class PoisonEffect : public StatusEffect {
private:
    int damagePerTurn;

public:
    PoisonEffect(int turns, int damage)
        : StatusEffect("Poison", turns), damagePerTurn(damage) {}

    void applyEffect(Character& target) override;
};
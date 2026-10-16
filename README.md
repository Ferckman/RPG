# Turn-Based RPG Gameplay Core (C++)

A modular, object-oriented turn-based RPG gameplay engine written in modern C++ (C++17/20). Built as a technical showcase for gameplay programming principles, clean architecture, and modern memory management.

## 🚀 Key Features & Technical Highlights

- **Modern C++ Memory Management:** Zero raw pointers and no memory leaks. All dynamic object lifetimes (characters, items, status effects) are managed strictly using smart pointers (`std::unique_ptr`) and move semantics.
- **Object-Oriented & Polymorphic Design:** 
  - Abstract base class `Character` with virtual destructors to ensure proper resource cleanup.
  - Specialized derived classes (`Player`, `Enemy`) extending core combat behavior.
  - **Polymorphic Status Effects:** A flexible `StatusEffect` system (`PoisonEffect`, etc.) injected dynamically into entities and processed at turn boundaries.
- **Engine Architecture & Separation of Concerns:** 
  - Strict decoupling between class declarations (`.h`) and implementations (`.cpp`).
  - Encapsulation of the core game loop and state management inside a dedicated `Game` engine class, keeping `main.cpp` as a clean entry point.
- **Robust Input Handling:** Interactive command-line turn orchestration featuring input sanitization (`std::cin.fail()`) to prevent infinite loops and handle user error gracefully.

## 🛠️ Project Structure

```text
RPG/
├── Game.h / Game.cpp            # Core engine class managing turn orchestration and game state
├── Character.h / Character.cpp  # Abstract base character entity (Health, Attack, Armor, Virtual methods)
├── Player.h / Player.cpp        # Player class with smart-pointer inventory system
├── Enemy.h / Enemy.cpp          # Enemy class with basic turn AI
├── Item.h / Item.cpp            # Item entity supporting healing and effect injection
├── StatusEffect.h / StatusEffect.cpp # Polymorphic status effect system
├── main.cpp                     # Minimalist entry point instantiating the Game engine
└── .gitignore                   # Keeps repository clean of platform binaries (.exe)
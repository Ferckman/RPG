# Turn-Based RPG Gameplay Core (C++)

A modular, object-oriented turn-based RPG gameplay system written in modern C++ (C++17/20). Built as a technical showcase for gameplay programming principles, clean architecture, and modern memory management.

## 🚀 Key Features & Technical Highlights

* **Modern C++ Memory Management:** Zero raw pointers and no memory leaks. All dynamic object lifetimes (items, inventory) are managed strictly using `std::unique_ptr` and move semantics (`std::move`).
* **Object-Oriented Design (OOP):** 
  * Polymorphic base class `Character` with virtual destructors to prevent resource leaks during inheritance cleanup.
  * Specialized derived classes (`Player`, `Enemy`) extending core behavior.
* **Separation of Concerns:** Strict decoupling between declarations (`.h`) and implementations (`.cpp`).
* **Interactive Command-Line Gameplay:** Includes turn management, inventory usage, damage calculations, and simple enemy AI decision-making.

## 🛠️ Project Structure

```text
RPG/
├── Character.h / Character.cpp  # Abstract/Base character entity (Health, Attack, Virtual methods)
├── Player.h / Player.cpp        # Player class with smart-pointer inventory system
├── Enemy.h / Enemy.cpp          # Enemy class with basic turn AI
├── Item.h / Item.cpp            # Item entity with destructor logging for memory verification
├── main.cpp                     # Interactive Game Loop and turn orchestration
└── .gitignore                   # Keeps repository clean of platform binaries (.exe)
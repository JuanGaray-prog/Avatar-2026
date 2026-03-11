# 🎮 Avatar OOP Project

A C++ Object-Oriented simulation where an "Avatar" navigates a dynamic board to find the exit. This project focuses on **Pathfinding**, **Random Generation**, and **Console Visual Effects**.

## 🚀 Key Features

* **OOP Architecture:** Developed using clean Class structures (`Avatar`, `Tablero`) to manage game state and entity behavior.
* **Visual Enhancements:** Customized console rendering to clearly distinguish between:
    * 🛣️ **Road:** Walkable paths.
    * 🕳️ **Abyss:** Deadly obstacles.
    * 👤 **Player:** Your current position.
* **Smart Respawn:** The Avatar uses a random spawn algorithm that guarantees placement on an "allowed" (road) tile, preventing instant-death starts.
* **Auto-Solver:** Implementation of a search algorithm that allows the Avatar to find the optimal path to the exit.

## 📂 Project Structure

```text
/
├── src/            # Implementation files (.cpp)
├── include/        # Header files (.h)
├── data/           # Level layouts (tablero.txt)
└── LICENSE         # MIT License

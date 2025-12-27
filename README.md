2048 Game in C 

A classic implementation of the popular 2048 puzzle game written in C. This version runs directly in the Windows console and includes features like high-score saving and support for both WASD and Numpad controls.

🎮 Features
Keyboard Controls: Move tiles using W, A, S, D or the Numpad (8, 4, 2, 6).
High Score Persistence: Your highest score is saved to a scores.txt file and loaded automatically when you restart.
Game Logic: Accurate tile merging and movement mechanics.
Win/Loss Conditions: Detects when you reach the 2048 tile or when no more moves are available.

🚀 How to Run
Prerequisites
Windows OS: This project uses conio.h and system("cls"), which are Windows-specific.
C Compiler: (e.g., GCC/MinGW, Clang, or MSVC).
Compilation
Open your terminal or command prompt and run:

gcc main.c -o 2048.exe


Execution
Run the generated executable:

2048.exe


🕹️ How to Play
Controls

Key

Action

W / 8

Move Up

A / 4

Move Left

S / 2

Move Down

D / 6

Move Right

ESC

Exit Game

R

Restart (on Game Over screen)

Rules
Merge: When two tiles with the same number touch, they merge into one!
Goal: Keep merging numbers to reach the 2048 tile.
Game Over: The game ends when the board is full and no more merges can be made, or when you reach the 2048 goal.
🛠️ Code Structure
The game is built with a simple, modular structure:


Functions used
1)

# Othello Game

## Description
This project is an implementation of the classic board game **Othello** (also known as Reversi) in C++. The game allows two players (human vs. computer or human vs. human) to play on an 8x8 board, following the standard rules of Othello.

## Features
- Fully functional Othello game with standard rules.
- Interactive gameplay with a simple text-based interface.
- Computer AI to play against the user.
- Highlights valid moves and updates the board dynamically.

## How to Compile and Run
### Prerequisites
- A C++ compiler (e.g., `g++`).
- Make sure the compiler is added to your system's PATH.

### Steps
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd Othello

2. Compile and run the program using the provided Makefile
   ```bash
   make
   make run

3. To remove compiled files and executables
   ```bash
   make clean

## Rules of Othello
1. The game is played on an 8x8 board.
2. Players take turns placing their pieces (X or O) on the board.
3. A move is valid if it captures at least one of the opponent's pieces by surrounding them horizontally, vertically, or diagonally.
4. The game ends when no valid moves are available for either player.
5. The player with the most pieces on the board at the end wins.

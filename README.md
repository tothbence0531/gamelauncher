# Game Launcher in C

This project is a simple game launcher developed during my first semester as an introduction to programming. It is written entirely in C and serves as my first project in the field of software development. The launcher includes two games: **Tic-Tac-Toe** and **Blackjack**.

## Features

### Game Launcher

- Main menu to select and launch the desired game.

### Tic-Tac-Toe

- A classic 2-player game where participants compete against each other.
- Simple and intuitive gameplay.

### Blackjack

- A single-player game against the dealer.
- Includes a balance system to track player winnings.
- Displays statistics at the end of each game.

## Technologies Used

- **C Programming Language**: Entire project written in C.
- **Standard Libraries**: Utilized for input/output, random number generation, and game logic.

## How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/tothbence0531/gamelauncher.git
   ```

2. Compile the source code using a C compiler (e.g., `gcc`):

   ```bash
   gcc -o gamelauncher gamelauncher.c
   ```

3. Run the executable:

   ```bash
   ./gamelauncher
   ```

4. Follow the on-screen instructions to choose and play a game.

## Gameplay Instructions

### Tic-Tac-Toe

1. Choose Tic-Tac-Toe from the main menu.
2. Players take turns selecting a cell on the grid.
3. The first player to align three of their marks horizontally, vertically, or diagonally wins.
4. If the grid is full and no player has aligned three marks, the game ends in a draw.

### Blackjack

1. Choose Blackjack from the main menu.
2. Start with an initial balance.
3. Place bets and try to beat the dealer's hand without exceeding 21.
4. Statistics (e.g., total wins, losses, and balance) are displayed at the end of each game.

## Project Details

- **Semester**: First semester
- **University**: SZTE
- **Languages Used**: C
- **Team Members**: Solo project
- **Purpose**: Introduction to programming and basic game development.

## Future Improvements

- Add more games to the launcher.
- Implement a graphical user interface (GUI) for better user experience.
- Enhance the Blackjack logic with more advanced betting options.
- Add multiplayer functionality to Blackjack.

## License

This project is for educational purposes and is not licensed for commercial use.

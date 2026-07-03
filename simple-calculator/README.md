# Simple Calculator

An interactive, text-based command-line calculator written in pure C. This program processes standard arithmetic operations safely within a continuous execution loop and includes robust input handling and zero-division defense mechanisms.

## Core Features

* **Interactive Menu Loop**: Program continuously prompts the user for choices until `0` is selected to exit safely.
* **Input Validation**: Strictly validates user options. If a choice outside the `0-4` range or a non-numeric character is entered, the program safely clears the buffer and triggers an `Invalid choice` message.
* **Addition (Choice 1)**: Reads integer variables `A` and `B`, calculates `A + B`, and displays the result.
* **Subtraction (Choice 2)**: Reads integer variables `A` and `B`, calculates `A - B`, and displays the result.
* **Multiplication (Choice 3)**: Reads integer variables `A` and `B`, calculates `A * B`, and displays the result.
* **Division (Choice 4)**: Reads integer variables `A` and `B`, calculates `A / B`, and displays the result.
* **Division by Zero Defense**: Intercepts null divisors before processing to display exactly `Error: division by zero` and safely returns to the menu loop.

## Project Structure

* **calculator.c**: Core source code written in compliance with strict formatting guidelines (variable declarations, indentation, and clean functional segregation).
* **README.md**: Comprehensive documentation highlighting features, compilation parameters, and execution workflows.

## Compilation

The codebase is strictly written to compile with standard gcc flags ensuring production-ready code hygiene:

```bash
gcc -Wall -Werror -Wextra -pedantic calculator.c -o compiler
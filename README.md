## Reading References:

    1. Dynamic Memory Allocation of 2D Arrays
    'https://larningc.org/chapters/chapter09-multi-dimensional-arrays/2d-dynamic-memory-alloce'

## Concepts involved:

1. 2D Array and dynamic memory allocation of 2D arrays and 2D array passing to functions.
2. Recursion and Backtracking
3. GDB Debugging (optional) - I used for resolving `Segmentation Fault (core dumped)`
4. File Handling
5. Command Line Argument Passing

## NOTE: 0 represents empty cell of Sudoku

## Prerequisites

To compile and run these programs, you will need a C compiler, such as `gcc`, installed on your system.

## Installation and Usage

First, clone the repository to your local machine and navigate into the project directory.

`git clone https://github.com/truthseeker20/sudoku_solver.git`

`cd sudoku_solver`

## How to use the files and compile & run:

1. Hardcoded Puzzle (sudoku.c)
This program solves a 9x9 Sudoku puzzle (all cells are 0) that is hardcoded directly into the source file. You can edit the code to change the puzzle.

Compile:
`gcc sudoku.c -lm -o sudoku`

Run:
`./sudoku`

2. Puzzle by Order (order_passing_sudoku.c)
This program takes the grid size (order) as a command-line argument and solves a blank Sudoku of that size. The order must be a positive perfect square number (e.g., 9 for a 9x9 grid).

Compile:
`gcc order_passing_sudoku.c -lm -o order_passing_sudoku`

Run:
`./order_passing_sudoku 9`

3. Puzzle from a File (problem_passing_sudoku.c)
This program reads a Sudoku puzzle from a text file specified as a command-line argument. A sample puzzle.txt file is included for reference.

Compile:
`gcc problem_passing_sudoku.c -lm -o problem_solver`

Run:
`./problem_solver puzzle.txt`

   

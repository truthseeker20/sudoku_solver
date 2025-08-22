Reading References:

    1. Dynamic Memory Allocation of 2D Arrays
    'https://larningc.org/chapters/chapter09-multi-dimensional-arrays/2d-dynamic-memory-alloce'

NOTE: 0 represents empty cell of Sudoku

## How to use the files:

1. Clone the repository: `git clone https://github.com/truthseeker20/sudoku_solver.git`
2. Navigate to the directory `cd /sudoku`
3. Types of files and how to compile:
   -> sudoku.c
       1. it has 9x9 zero sudoku, which it solves by itself, you can change it by making changes to the code
       2. to compile: $ gcc sudoku.c -lm -o sudoku    
       3. to run:     $ ./sudoku 

   -> order_passing_sudoku.c
       1. it takes order (a positive perfect square number as second command line argument)
       2. it solves a sudoku (all zero elements) of given order
       3. to compile: $ gcc order_passing_sudoku.c -lm -o order_passing_sudoku
       4. to run:     $ ./order_passing_sudoku 9
   
   -> problem_passing_sudoku.c
       1. it takes a .txt file as second command line argument, which has the sudoku problem in it, for reference there is a puzzle.txt file which has a sample problem, we don't have to pass order for this
       2. to compile: $ gcc problem_passing_sudoku.c -lm -o problem_solving_puzzle
       3. to run:     $ ./problem_solving_puzzle puzzle.txt

   -> I also took help from gemini along, shared all conversation in gemini_help.txt file

   

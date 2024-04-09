# N-queens-Problem
A project I made in C programming language .
INTRODUCTION
The N-Queens problems are classic combinatorial puzzles that have been studied extensively in computer science and mathematics. These problems involve placing N queens on an N×N chessboard (or a rectangular board) such that no two pieces attack each other according to their respective movement rules.

The objective of this project is to develop a C program that can solve both the N-Queens problems for any given number of rows and columns. The program will find and display all possible solutions for placing N queens or N horses on the board.

The N-Queens Problem
The N-Queens problem is a well-known puzzle that involves placing N queens on an N×N chessboard such that no two queens can attack each other. In chess, a queen can move any number of squares horizontally, vertically, or diagonally in any direction. The goal is to find all possible arrangements of N queens on the board where no two queens share the same row, column, or diagonal.

This problem has applications in various areas, including computer science (e.g., parallel computing, scheduling), mathematics (e.g., graph coloring, combinatorics), and even in real-world scenarios like circuit design and traffic management.


Approach and Implementation
The program is implemented in C and utilizes a backtracking algorithm to find all possible solutions for the N-Queens problems. The backtracking algorithm is a recursive approach that explores all possible solutions by building candidates to the solutions incrementally and abandoning each candidate ("backtracking") as soon as it determines that the candidate cannot possibly be completed to a valid solution.

The program dynamically allocates memory for the board based on the user-provided number of rows and columns. It then initializes the board with all cells set to 0 (empty). The isSafe function checks if it is safe to place a queen at a given position on the board by examining row, column, diagonal.

The solveNQueenUtil function is the recursive backtracking function that systematically places queens on the board, one column at a time, and recursively explores all possibilities. If a solution is found, it prints the solution board. The function keeps track of the total number of solutions found and returns this value.

The program prompts the user to enter the number of rows and columns, and then asks the user to choose whether to solve the N-Queens problem. The program calls the appropriate function and displays the total number of solutions found, if any.

Usage and Example
To use the program, compile the source code using a C++ compiler and run the executable. The program will prompt you for the number of rows and columns, and then ask you to choose between the N-Queens problem .

The program will display each solution, where '1' represents the position of a queen, and '0' represents an empty cell. If no solution exists, the program will print "Solution does not exist".


Working of every parameters and functions
Certainly! Here's a brief explanation of the parameters, key lines, and functions in the code:

**Parameters:**

1. `rows` and `cols`: Global variables to store the number of rows and columns entered by the user.

**Key Lines:**

1. `int** board = (int**)malloc(rows * sizeof(int*));`: Dynamically allocates memory for the board using `malloc`. Each row is a pointer to an array of integers.
2. `board[i] = (int*)malloc(cols * sizeof(int));`: Dynamically allocates memory for each row of the board.
3. `board[i][j] = 0;`: Initializes all cells of the board to 0 (empty).
4. `board[i][col] = 1;`: Places a queen or horse at the position `(i, col)` on the board.
5. `board[i][col] = 0;`: Removes the queen or horse from the position `(i, col)` on the board (backtracking).

**Functions:**

1. `isSafe(int** board, int row, int col, int type)`:
   - Checks if it is safe to place a queen or horse at the position `(row, col)` on the board.
   - Iterates through the current row and column to check for conflicts.
   - Checks diagonals for conflicts.
   - Returns 1 (true) if the position is safe, 0 (false) otherwise.

2. `printSolution(int** board)`:
   - Prints the current state of the board.
   - Iterates through each cell and prints its value (1 for a queen/horse, 0 for an empty cell).
   - Prints a separator line after each solution.

3. `solveNQueenUtil(int** board, int col, int type)`:
   - Recursive backtracking function to solve the N-Queens or N-Horses problem.
   - Base case: If all columns are filled (`col == cols`), it prints the current solution and returns 1 (a solution found).
   - Iterates through each row of the current column.
   - If a safe position is found using `isSafe`, it places a queen/horse there (`board[i][col] = 1`), recursively calls itself with the next column (`solveNQueenUtil(board, col + 1, type)`), and backtracks by removing the queen/horse (`board[i][col] = 0`).
   - Keeps track of the total number of solutions found and returns it.

4. `main()`:
   - Entry point of the program.
   - Prompts the user for the number of rows and columns.
   
   - Dynamically allocates memory for the board.
   - Initializes the board with all cells set to 0 (empty).
   - Calls `solveNQueenUtil` 
   - Prints the total number of solutions found, if any.
   - Frees the dynamically allocated memory for the board.

The code uses a backtracking approach to systematically explore all possible arrangements of queens or horses on the board. The `isSafe` function checks if a position is safe to place a piece, and the `solveNQueenUtil` function recursively tries all possible placements, backtracking when a solution cannot be extended further.

You're right, my previous explanation didn't go into enough detail for the `isSafe` function. Let me provide a more extensive explanation:

The `isSafe` function is responsible for checking if it's safe to place a queen or a horse at a given position `(row, col)` on the board. It takes three parameters:

1. `int** board`: A 2D array representing the chessboard.
2. `int row`: The row index of the position to be checked.
3. `int col`: The column index of the position to be checked.
4. `int type`: An integer flag indicating whether the problem is N-Queens (type = 1) .

The function performs the following checks:

1. **Row and Column Conflicts:**
   Code:-
   for (i = 0; i < cols; i++) {
       if (board[row][i] == 1) {
           return 0;
       }
   }

   for (j = 0; j < row; j++) {
       if (board[j][col] == 1) {
           return 0;
       }
   }
   ```
   These two loops check if there is already a queen or horse placed in the same row or column as the current position `(row, col)`. If a piece is found, it means there is a conflict, and the function returns 0 (false).

3.	**Diagonal Conflicts:**
Code:-
   for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
       if (board[i][j] == 1) {
           return 0;
       }
   }

   for (i = row + 1, j = col - 1; i < rows && j >= 0; i++, j--) {
       if (board[i][j] == 1) {
           return 0;
       }
   }

   for (i = row - 1, j = col + 1; i >= 0 && j < cols; i--, j++) {
       if (board[i][j] == 1) {
           return 0;
       }
   }

   for (i = row + 1, j = col + 1; i < rows && j < cols; i++, j++) {
       if (board[i][j] == 1) {
           return 0;
       }
   }
   ```
   These four loops check for diagonal conflicts. They iterate in all four diagonal directions (upper-left, lower-left, upper-right, and lower-right) from the current position `(row, col)`. If a piece is found in any of the diagonals, it means there is a conflict, and the function returns 0 (false).


The `isSafe` function ensures that no two queens or horses attack each other based on their respective movement rules. For queens, it checks for row, column, and diagonal conflicts. 
We also used file handiling in this case to store the number of solutions that we can get .

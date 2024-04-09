#include <stdio.h>
#include <stdlib.h>

// Dynamically get row and column numbers from the user
int rows, cols;


// Function prototypes
int isSafe(int** board, int row, int col);
void printSolution(int** board,FILE *outputFile);
int solveNQueenUtil(int** board, int col,FILE *outputFile);

int main() {
   printf(" 1 represents the place where the queen is placed and  0 represents empty space \n");
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   printf("Enter the number of columns: ");
   scanf("%d", &cols);
   

   int** board = (int**)malloc(rows * sizeof(int*));
   for (int i = 0; i < rows; i++) {
       board[i] = (int*)malloc(cols * sizeof(int));
   }

   // Initialize all cells as empty
   for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
           board[i][j] = 0;
       }
   }
   FILE *outputFile = fopen("solutions.txt", "w"); // Open output file for writing
        if (outputFile == NULL) {
            printf("Error opening output file.\n");
            return 1;
        }


   int total_solutions_found = solveNQueenUtil(board, 0,outputFile);
        if (total_solutions_found > 0) {
            fprintf(outputFile, "Total solutions found: %d\n", total_solutions_found);
        } else {
            fprintf(outputFile, "Solution does not exist.\n");
        }


   // Free the dynamically allocated memory (important!)
   for (int i = 0; i < rows; i++) {
       free(board[i]);
   }
   free(board);
   fclose(outputFile);

   return 0;
}

// Check if a queen can be placed safely in a given row and column
int isSafe(int** board, int row, int col) {
   int i, j;

   // Check for row and column conflicts
   for (i = 0; i < cols; i++) {
       // Check entire column (adjusted for cols)
       if (board[row][i] == 1) {
           return 0;
       }
   }

   for (j = 0; j < row; j++) {
       if (board[j][col] == 1) { //Check entire row (adjusted for rows)
           return 0;
       }
   }

   // Check for diagonals (adjusted for rectangular board)
   for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
       // Check upper left diagonal
       if (board[i][j] == 1) {
           return 0;
       }
   }

   for (i = row + 1, j = col - 1; i < rows && j >= 0; i++, j--) {
       // Check lower left diagonal
       if (board[i][j] == 1) {
           return 0;
       }
   }

   for (i = row - 1, j = col + 1; i >= 0 && j < cols; i--, j++) {
       // Check upper right diagonal
       if (board[i][j] == 1) {
           return 0;
       }
   }

   for (i = row + 1, j = col + 1; i < rows && j < cols; i++, j++) {
       // Check lower right diagonal
       if (board[i][j] == 1) {
           return 0;
       }
   }

   return 1;
}

// Print the solution board
void printSolution(int** board,FILE *outputFile) {
   for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
           printf(" %d ", board[i][j]);
       }
       printf("\n"); // Add newline after each row
   }
   printf("-------------\n");
}

// Recursive function to solve N-Queen problem
int solveNQueenUtil(int** board, int col,FILE *outputFile) {
   // Base case: If all queens are placed (check all columns)
   if (col == cols) {
       printSolution(board,outputFile); // Print current solution
       return 1; // Indicate a solution found (for tracking)
   }

   int num_solutions_found = 0; // Track total solutions found

   // Consider this column and try placing this queen in all rows one by one
   for (int i = 0; i < rows; i++) {
       // Check all rows for placement
       if (isSafe(board, i, col)) {
           board[i][col] = 1; // Mark this cell as filled

           // Recursively explore all possibilities from next column
           num_solutions_found += solveNQueenUtil(board, col + 1,outputFile);

           // Backtrack if placement doesn't lead to a solution
           board[i][col] = 0;
       }
   }

   return num_solutions_found; // Return total solutions found in this branch
}

#include<iostream.h>
#include<conio.h>
#define MAX 16 // Maximum size of the chessboard

class N_Queen {
    int matrix[MAX][MAX]; // Chessboard matrix
    int queen; // Number of queens

public:
    // Constructor to initialize the number of queens
    N_Queen() {
        queen = 0;
    }

    // Function to input the number of queens
    void setQueen() {
        cout << "Enter No of Queens: ";
        cin >> queen;
    }

    // Function to set up the chessboard and solve the problem
    void setMatrix() {
        // Check if the number of queens is valid
        if (queen <= 3 || queen > MAX) {
            queen = 0;
            cout << "Solution does not exist." << endl;
        } else {
            solve(0, 0); // Start solving from the first row
        }
    }

private:
    // Recursive function to solve the N-Queen problem
    int solve(int row, int col) {
        // Base case: If all columns are filled, the problem is solved
        if (col > queen - 1)
            return 0;

        // If all rows are filled, the problem is solved
        if (row > queen - 1)
            return 1;

        // Check if the current position is safe to place a queen
        if (safe(row, col)) {
            matrix[row][col] = 1; // Place the queen

            // Move to the next row
            if (solve(row + 1, 0) == 0) {
                matrix[row][col] = 0; // Backtrack if no solution found
                return solve(row, col + 1); // Try the next column
            } else
                return 1; // Queen successfully placed
        } else {
            // If the position is not safe, try the next column
            return solve(row, col + 1);
        }
    }

    // Function to check if a queen can be safely placed at (row, col)
    int safe(int row, int col) {
        // The first row is always safe
        if (row == 0)
            return 1;

        // Check all rows above the current one
        for (int rowIndex = 0; rowIndex <= row; rowIndex++) {
            for (int colIndex = 0; colIndex < queen; colIndex++) {
                if (matrix[rowIndex][colIndex] == 1) {
                    // If a queen is found, check if placing another is valid
                    if (!validPlace(row, col, rowIndex, colIndex))
                        return 0;
                    break;
                }
            }
        }
        return 1; // No conflicts, so the position is safe
    }

    // Function to check if placing a queen at (x_row, x_col) conflicts with (row, col)
    int validPlace(int x_row, int x_col, int row, int col) {
        // Check if two queens are on the same diagonal or in the same column
        if (x_row + x_col == row + col || x_col == col) {
            return 0;
        }

        // Check if two queens are in the same row or column
        for (int index = 0; index <= x_row; index++) {
            if (x_row == row && x_col == col)
                return 0;

            row++;
            col++;
        }

        return 1; // Position is valid
    }

public:
    // Function to display the final chessboard matrix
    void showMatrix() {
        for (int rowIndex = 0; rowIndex < queen; rowIndex++) {
            for (int colIndex = 0; colIndex < queen; colIndex++)
                cout << matrix[rowIndex][colIndex] << " ";
            cout << endl;
        }
    }
};

void main() {
    clrscr();
    
    N_Queen nQueen; // Create an object of the N_Queen class

    nQueen.setQueen();    // Input the number of queens
    nQueen.setMatrix();    // Attempt to solve the N-Queen problem
    nQueen.showMatrix();   // Display the solution

    getch();
}

//Backtracking approach to solve Sudoku
#include <vector>
#include <iostream>

using namespace std;

bool isSafe(const vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                
                // Try digits from 1-9
                for (char num = '1'; num <= '9'; ++num) {
                    if (isSafe(board, i, j, num)) {
                        board[i][j] = num; // Place the number

                        if (solveSudoku(board)) {
                            return true; // Solved.
                        }

                        board[i][j] = '.'; // Backtrack takes place. Tries next number.
                    }
                }
                return false; // No number worked in this cell
            }
        }
    }
    return true; // No empty cells left, puzzle is solved
}
// Time Complexity: Exponential in the worst case, but efficient for solvable Sudoku problems.
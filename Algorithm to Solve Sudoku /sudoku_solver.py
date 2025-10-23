"""
Sudoku Solver using Backtracking
Author: Mohit Kourav

Description:
A Python implementation to solve a 9x9 Sudoku puzzle using backtracking.
Includes:
- Line-by-line code explanation
- Example input/output
- Time and Space complexity analysis
"""

def is_valid(board, row, col, num):
    """
    Check if it's valid to place 'num' in board[row][col].
    
    How it works:
    1. Check the current row for duplicates.
    2. Check the current column for duplicates.
    3. Check the 3x3 subgrid for duplicates.
    Returns True if no duplicates, else False.
    """
    # Check row and column
    for i in range(9):
        if board[row][i] == num or board[i][col] == num:
            return False
    
    # Check 3x3 subgrid
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(3):
        for j in range(3):
            if board[start_row + i][start_col + j] == num:
                return False
    
    return True

def solve_sudoku(board):
    """
    Solve the Sudoku board using backtracking.
    
    How it works:
    1. Iterate over each cell in the 9x9 board.
    2. Find the first empty cell (denoted by 0).
    3. Try placing numbers 1-9 in that cell.
    4. If placing a number is valid (checked by is_valid), recurse to next empty cell.
    5. If no number fits, backtrack by resetting cell to 0.
    6. Continue until all cells are filled.
    
    Returns True if solved, False if no solution exists.
    """
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:  # Empty cell found
                for num in range(1, 10):
                    if is_valid(board, row, col, num):
                        board[row][col] = num  # Tentatively place number
                        if solve_sudoku(board):  # Recurse
                            return True
                        board[row][col] = 0  # Backtrack if no solution
                return False  # Trigger backtracking
    return True  # Sudoku solved

def print_board(board):
    """
    Print the Sudoku board in a readable format.
    
    How it works:
    - Loops through each row and prints numbers separated by spaces.
    """
    for row in board:
        print(" ".join(str(num) for num in row))

if __name__ == "__main__":
    # Example Sudoku puzzle (0 represents empty cells)
    board = [
        [5,3,0,0,7,0,0,0,0],
        [6,0,0,1,9,5,0,0,0],
        [0,9,8,0,0,0,0,6,0],
        [8,0,0,0,6,0,0,0,3],
        [4,0,0,8,0,3,0,0,1],
        [7,0,0,0,2,0,0,0,6],
        [0,6,0,0,0,0,2,8,0],
        [0,0,0,4,1,9,0,0,5],
        [0,0,0,0,8,0,0,7,9]
    ]

    print("🔹 Original Sudoku Board:")
    print_board(board)

    # Solve the Sudoku
    if solve_sudoku(board):
        print("\n✅ Solved Sudoku Board:")
        print_board(board)
    else:
        print("❌ No solution exists for the given Sudoku puzzle.")

    """
    Time & Space Complexity:
    ---------------------------------
    Time Complexity: O(9^(N*N)) worst-case
        - N = 9 for standard Sudoku board
        - Each empty cell tries numbers 1-9, potentially recursively for all empty cells
    Space Complexity: O(N*N)
        - Board storage and recursion stack
    Practical performance:
        - Usually much faster because Sudoku puzzles have enough initial clues to limit recursion.
    """

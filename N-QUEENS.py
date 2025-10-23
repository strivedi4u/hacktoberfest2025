class Solution:
    def solveNQueens(self, n: int):
        # Results list: will hold all the valid board configurations
        res = []

        # board[row] = col means: in row “row” we put a queen at column “col”
        board = [-1] * n

        # These arrays track whether a column or diagonals are already attacked by a queen:
        cols = [False] * n                   # columns
        diag1 = [False] * (2 * n - 1)        # “\” diagonal: index = row + col
        diag2 = [False] * (2 * n - 1)        # “/” diagonal: index = row - col + (n-1)

        def backtrack(row):
            """
            Try to place a queen in row “row”, and then recurse for next rows.
            """
            # Base case: if we've placed queens up to row n, we have a full solution
            if row == n:
                # build the configuration lines
                solution = []
                for r in range(n):
                    # create a row string of length n, filled with '.'
                    row_chars = ['.'] * n
                    # place the 'Q' at the correct column
                    row_chars[ board[r] ] = 'Q'
                    # convert list of chars to string
                    solution.append("".join(row_chars))
                # add this configuration to results
                res.append(solution)
                return

            # Try placing the queen in each column of the current row
            for c in range(n):
                # Check if column c or diagonals are already under attack
                if cols[c] or diag1[row + c] or diag2[row - c + n - 1]:
                    # cannot place queen here
                    continue

                # Place the queen at (row, c)
                board[row] = c
                cols[c] = True
                diag1[row + c] = True
                diag2[row - c + n - 1] = True

                # Move to next row
                backtrack(row + 1)

                # Backtrack: remove the queen and unmark the attacks
                cols[c] = False
                diag1[row + c] = False
                diag2[row - c + n - 1] = False
                board[row] = -1

        # Start placing from row 0
        backtrack(0)
        return res
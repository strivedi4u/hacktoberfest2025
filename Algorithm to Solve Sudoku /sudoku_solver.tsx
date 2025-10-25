import React, { useState } from "react";
type SudokuGrid = number[][];

const isSafe = (board: SudokuGrid, row: number, col: number, num: number): boolean => {
  for (let x = 0; x < 9; x++) {
    if (board[row][x] === num) return false;
  }
  for (let x = 0; x < 9; x++) {
    if (board[x][col] === num) return false;
  }
  const startRow = row - (row % 3);
  const startCol = col - (col % 3);
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      if (board[i + startRow][j + startCol] === num) return false;
    }
  }
  return true;
};
const solveSudoku = (board: SudokuGrid): boolean => {
  for (let row = 0; row < 9; row++) {
    for (let col = 0; col < 9; col++) {
      if (board[row][col] === 0) {
        for (let num = 1; num <= 9; num++) {
          if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) return true;
            board[row][col] = 0;
          }
        }
        return false;
      }
    }
  }
  return true;
};
const SudokuSolver: React.FC = () => {
  const [board, setBoard] = useState<SudokuGrid>([
    [3, 0, 6, 5, 0, 8, 4, 0, 0],
    [5, 2, 0, 0, 0, 0, 0, 0, 0],
    [0, 8, 7, 0, 0, 0, 0, 3, 1],
    [0, 0, 3, 0, 1, 0, 0, 8, 0],
    [9, 0, 0, 8, 6, 3, 0, 0, 5],
    [0, 5, 0, 0, 9, 0, 6, 0, 0],
    [1, 3, 0, 0, 0, 0, 2, 5, 0],
    [0, 0, 0, 0, 0, 0, 0, 7, 4],
    [0, 0, 5, 2, 0, 6, 3, 0, 0],
  ]);
  const [solved, setSolved] = useState(false);
  const handleSolve = () => {
    const newBoard = board.map(row => [...row]);
    if (solveSudoku(newBoard)) {
      setBoard(newBoard);
      setSolved(true);
    } else {
      alert("No solution exists!");
    }
  };
  return (
    <div style={{ textAlign: "center" }}>
      <h2>Sudoku Solver (TypeScript + React)</h2>
      <table
        style={{
          borderCollapse: "collapse",
          margin: "auto",
        }}
      >
        <tbody>
          {board.map((row, i) => (
            <tr key={i}>
              {row.map((cell, j) => (
                <td
                  key={j}
                  style={{
                    border: "1px solid #000",
                    width: "30px",
                    height: "30px",
                    textAlign: "center",
                    backgroundColor: cell === 0 ? "#eee" : "#fff",
                  }}
                >
                  {cell !== 0 ? cell : ""}
                </td>
              ))}
            </tr>
          ))}
        </tbody>
      </table>
      <button
        onClick={handleSolve}
        style={{
          marginTop: "20px",
          padding: "8px 16px",
          fontSize: "16px",
          cursor: "pointer",
        }}
      >
        Solve Sudoku
      </button>
      {solved && <p>✅ Sudoku solved successfully!</p>}
    </div>
  );
};
export default SudokuSolver;

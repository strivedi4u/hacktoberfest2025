const ROWS = 6, COLS = 7;
let board = [];
let currentPlayer = "red";
let playerNames = { red: "Red", yellow: "Yellow" };
let gameActive = false;

const boardDiv = document.getElementById("board");
const msg = document.querySelector(".turn");
const setupDiv = document.getElementById("player-setup");
const startBtn = document.getElementById("start-btn");

function createBoard() {
    boardDiv.innerHTML = "";
    board = Array.from({ length: ROWS }, () => Array(COLS).fill(""));
    for (let c = 0; c < COLS; c++) {
        const col = document.createElement("ul");
        col.className = "column";
        col.dataset.col = c;
        for (let r = 0; r < ROWS; r++) {
            const tile = document.createElement("p");
            tile.className = "tile";
            tile.dataset.row = r;
            col.appendChild(tile);
        }
        boardDiv.appendChild(col);
    }
}

function setTurnMessage(type, text) {
    msg.className = "turn";
    if (type === "red") msg.classList.add("red");
    else if (type === "yellow") msg.classList.add("yellow");
    else if (type === "draw") msg.classList.add("draw");
    msg.innerText = text;
}

function startGame() {
    const p1 = document.getElementById("player1").value.trim() || "Red";
    const p2 = document.getElementById("player2").value.trim() || "Yellow";
    playerNames = { red: p1, yellow: p2 };
    currentPlayer = "red";
    gameActive = true;
    setupDiv.style.display = "none";
    msg.style.display = "block";
    setTurnMessage(currentPlayer, `${playerNames[currentPlayer]}'s turn! Drop your disc.`);
    createBoard();
}

function dropPiece(colIdx) {
    if (!gameActive) return;
    for (let r = ROWS - 1; r >= 0; r--) {
        if (!board[r][colIdx]) {
            board[r][colIdx] = currentPlayer;
            updateUI(r, colIdx, currentPlayer);
            if (checkWin(r, colIdx)) {
                setTurnMessage(currentPlayer, `${playerNames[currentPlayer]} wins! Congratulations! 🏆`);
                gameActive = false;
            } else if (board.flat().every(cell => cell)) {
                setTurnMessage("draw", "It's a draw! Well played both! 🤝");
                gameActive = false;
            } else {
                currentPlayer = currentPlayer === "red" ? "yellow" : "red";
                setTurnMessage(currentPlayer, ` ${playerNames[currentPlayer]}'s turn! Drop your disc.`);
            }
            return;
        }
    }
    setTurnMessage(currentPlayer, "That column is full! Try another one! ");
    setTimeout(() => setTurnMessage(currentPlayer, ` ${playerNames[currentPlayer]}'s turn! Drop your disc.`), 1200);
}

function updateUI(row, col, color) {
    const colDiv = boardDiv.children[col];
    const tile = colDiv.children[row];
    tile.style.backgroundColor = color;
}

function checkWin(row, col) {
    const color = board[row][col];
    const directions = [
        [ [0,1], [0,-1] ],  // horizontal
        [ [1,0], [-1,0] ],  // vertical
        [ [1,1], [-1,-1] ], // diagonal (\)
        [ [1,-1], [-1,1] ]  // diagonal (/)
    ];
    for (const dir of directions) {
        let count = 1;
        for (const [dr, dc] of dir) {
            let r = row + dr, c = col + dc;
            while (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] === color) {
                count++;
                r += dr; c += dc;
            }
        }
        if (count >= 4) return true;
    }
    return false;
}

startBtn.onclick = startGame;
boardDiv.onclick = function(e) {
    if (!gameActive) return;
    const colDiv = e.target.closest(".column");
    if (colDiv) dropPiece(Number(colDiv.dataset.col));
};


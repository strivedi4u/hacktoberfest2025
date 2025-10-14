#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;
void drawBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " | " << board[i][j];
        }
        cout << " |" << endl;
        cout << "-------------" << endl;
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}
int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return current_player;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player;
    }

    return 0;
}

void switchPlayer() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}
int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;

    current_player = 1;
    current_marker = 'X';

    int winner = 0;
    int slot;

    for (int i = 0; i < 9; i++) {
        drawBoard();
        cout << "Player " << current_player << ", enter your slot (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot. Please choose a slot between 1 and 9." << endl;
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken. Try again." << endl;
            i--;
            continue;
        }

        winner = checkWinner();

        if (winner != 0) {
            drawBoard();
            cout << "Player " << winner << " wins the game!" << endl;
            break;
        }

        switchPlayer();
    }

    if (winner == 0) {
        drawBoard();
        cout << "It's a tie!" << endl;
    }

    return 0;
}

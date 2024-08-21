#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<char>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 9; i += 3) {
        cout << "| " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << " |" << endl;
        cout << "-------------" << endl;
    }
}

bool checkWin(const vector<char>& board, char player) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player && board[i + 1] == player && board[i + 2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }

    return false;
}

int main() {
    vector<char> board(9, ' ');
    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter a position (1-9): ";
        int position;
        cin >> position;

        if (position < 1 || position > 9 || board[position - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[position - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (find(board.begin(), board.end(), ' ') == board.end()) {
            displayBoard(board);
            cout << "It's a tie!" << endl;
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
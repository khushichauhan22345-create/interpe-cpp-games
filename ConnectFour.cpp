#include <iostream>
using namespace std;

char board[6][7];

void display() {
    cout << "\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++)
            cout << "| " << board[i][j] << " ";
        cout << "|\n";
    }
    cout << "-----------------------------\n";
    cout << " 1  2  3  4  5  6  7\n";
}

bool win(char p) {
    for (int r = 0; r < 6; r++)
        for (int c = 0; c < 7; c++) {

            if (c + 3 < 7 &&
                board[r][c] == p && board[r][c+1] == p &&
                board[r][c+2] == p && board[r][c+3] == p)
                return true;

            if (r + 3 < 6 &&
                board[r][c] == p && board[r+1][c] == p &&
                board[r+2][c] == p && board[r+3][c] == p)
                return true;

            if (r + 3 < 6 && c + 3 < 7 &&
                board[r][c] == p && board[r+1][c+1] == p &&
                board[r+2][c+2] == p && board[r+3][c+3] == p)
                return true;

            if (r + 3 < 6 && c - 3 >= 0 &&
                board[r][c] == p && board[r+1][c-1] == p &&
                board[r+2][c-2] == p && board[r+3][c-3] == p)
                return true;
        }

    return false;
}

bool drop(int col, char p) {
    for (int r = 5; r >= 0; r--) {
        if (board[r][col] == '.') {
            board[r][col] = p;
            return true;
        }
    }
    return false;
}

int main() {
    for (int r = 0; r < 6; r++)
        for (int c = 0; c < 7; c++)
            board[r][c] = '.';

    char player = 'X';
    int col;

    cout << "CONNECT FOUR GAME\n";

    for (int turn = 0; turn < 42; turn++) {
        display();

        cout << "Player " << player << ", choose column (1-7): ";
        cin >> col;

        if (col < 1 || col > 7 || !drop(col - 1, player)) {
            cout << "Invalid move! Try again.\n";
            turn--;
            continue;
        }

        if (win(player)) {
            display();
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    display();
    cout << "Game Draw!\n";

    return 0;
}

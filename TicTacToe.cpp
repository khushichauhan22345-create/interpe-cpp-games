#include <iostream>
using namespace std;

char board[9] = {'1','2','3','4','5','6','7','8','9'};

void display() {
    cout << "\n";
    cout << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "--+---+--\n";
    cout << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "--+---+--\n";
    cout << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

bool win(char p) {
    int w[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for (int i = 0; i < 8; i++)
        if (board[w[i][0]] == p &&
            board[w[i][1]] == p &&
            board[w[i][2]] == p)
            return true;

    return false;
}

int main() {
    char player = 'X';
    int pos;

    cout << "TIC-TAC-TOE GAME\n";

    for (int turn = 0; turn < 9; turn++) {
        display();

        cout << "Player " << player << ", enter position: ";
        cin >> pos;

        if (pos < 1 || pos > 9 ||
            board[pos - 1] == 'X' ||
            board[pos - 1] == 'O') {
            cout << "Invalid move! Try again.\n";
            turn--;
            continue;
        }

        board[pos - 1] = player;

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

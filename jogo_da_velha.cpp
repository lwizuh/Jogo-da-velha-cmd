#include <iostream>
#include <vector>

using namespace std;

const char CampoVazio = ' ';
const char JogadorX = 'X';
const char JogadorO = 'O';

vector<vector<char>> board(3, vector<char>(3, CampoVazio));

void displayBoard() {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2)
                cout << "|";
        }
        cout << endl;
        if (i < 2)
            cout << "  -----\n";
    }
}

bool isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == CampoVazio)
                return false;
        }
    }
    return true;
}

bool checkWin(char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

void playMove(int row, int col, char player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == CampoVazio)
        board[row][col] = player;
}

int main() {
    char currentPlayer = JogadorX;

    while (!isBoardFull()) {
        displayBoard();
        cout << "Jogador " << currentPlayer << ", sua vez (linha e coluna): ";
        int row, col;
        cin >> row >> col;

        playMove(row, col, currentPlayer);

        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Jogador " << currentPlayer << " Ganhou!" << endl;
            return 0;
        }

        // troca o turno do player
        currentPlayer = (currentPlayer == JogadorX) ? JogadorO : JogadorX;
    }

    displayBoard();
    cout << "Empate!" << endl;

    return 0;
}

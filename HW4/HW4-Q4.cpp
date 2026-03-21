// Terry Addey
// ECE 205
// Homework 4, Question 4

#include <iostream>
using namespace std;


//board setup
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

//show the board
void showBoard();

int checkWin() {
   
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Cols
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for(int i = 0; i < 8; i++) {
        if(board[wins[i][0]] == board[wins[i][1]] && board[wins[i][1]] == board[wins[i][2]])
            return 1;
    }
    return 0;
}

int main() {
    int pos;
    char player = 'X';
    int turns = 0;

    while(turns < 9) {
        showBoard();
        cout << "Player " << player << ", enter position (1-9): ";
        cin >> pos;

    
        if(pos < 1 || pos > 9 || board[pos-1] == 'X' || board[pos-1] == 'O') {
            cout << "You're Cooked! Try again." << endl;
            continue;
        }

        board[pos-1] = player;
        turns++;

        if(checkWin()) {
            showBoard();
            cout << "Player " << player << " wins!" << endl;
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    showBoard();
    cout << "It's a draw!" << endl;
    return 0;
}

void showBoard() {
    cout << "\n " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n" << endl;
}

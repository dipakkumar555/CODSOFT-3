#include <iostream>
#include <vector>

using namespace std;

struct TicTacToe {
    vector<vector<char>> board{{'1', '2', '3'},
                               {'4', '5', '6'},
                               {'7', '8', '9'}};
    char currentPlayer;
    int moveCount;

    // Function to initialize the game
    void initialize() {
        currentPlayer = 'X';
        moveCount = 0;
        displayBoard();
    }

    // Function to display the Tic Tac Toe board
    void displayBoard() {
        cout << "  1 | 2 | 3 " << endl;
        cout << " -----------" << endl;
        cout << "  4 | 5 | 6 " << endl;
        cout << " -----------" << endl;
        cout << "  7 | 8 | 9 " << endl;
        cout << " -----------" << endl;
    }

    // Function to make a move
    void make_a_move(int position) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move. Try again." << endl;
        } else {
            board[row][col] = currentPlayer;
            moveCount++;
            displayBoard();
            check_Winning_move();
            switch_Players();
        }
    }

    // Function to switch players (X to O or O to X)
    void switch_Players() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Function to check for a win
    void check_Winning_move() {
        if (check_Rows() || check_Columns() || check_Diagonals()) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            exit(0);  // Exit the program
        } else if (moveCount == 9) {
            cout << "It's a draw!" << endl;
            exit(0);  // Exit the program
        }
    }

    // Function to check rows for a win
    bool check_Rows() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true;
            }
        }
        return false;
    }

    // Function to check columns for a win
    bool check_Columns() {
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true;
            }
        }
        return false;
    }

    // Function to check diagonals for a win
    bool check_Diagonals() {
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }
};

int main() {
    TicTacToe game;
    game.initialize();

    int position;

    while (true) {
        cout << "Player " << game.currentPlayer << ", enter your move (1-9): ";
        cin >> position;

        if (position < 1 || position > 9) {
            cout << "Invalid move. Please enter a number between 1 and 9." << endl;
            continue;
        }

        game.make_a_move(position);
    }

    return 0;
}
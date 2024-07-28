#include <iostream>

using namespace std;

char board[3][3] = {{' ', ' ', ' '} , {' ', ' ', ' '} , {' ', ' ', ' '}} ;

char currentPlayer = 'X';

void Board() 
{
    cout << "     1   2   3" << endl;
    cout << "   - - - - - - -" << endl;
    for (int i = 0 , k = 1 ; i < 3; i++ , k++) {
        cout << k << "  | " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |   " << k << endl;
        cout << "   - - - - - - -" << endl;
    }
    cout << "     1   2   3" << endl;
}

bool Victory() {
    
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) 
    {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) 
    {
        return true;
    }
    return false;
}

bool checkDraw() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] == ' ') 
            {
                return false; 
            }
        }
    }
    return true; 
}

void playerMove() {

    int row, col;
    cout << "Player " << currentPlayer << ", Row and Column Number: ";
    
    // Taking inputs for square
    cin >> row >> col;
    row -= 1 ;
    col -= 1 ;

    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') 
    {
        board[row][col] = currentPlayer;
    } 
    else 
    {
        cout << "Try a valid square!" << endl;
        playerMove();
    }
}

int main() 
{
    while (true) 
    {
        Board();
        playerMove();

        if (Victory()) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (checkDraw()) {
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}

#include <iostream>
#include <string.h>
using namespace std;
// `N × N` chessboard
#define N 4

// Function to check if two queens threaten each other or not
int isSafe(char board[][N], int r, int c)
{
    // return 0 if two queens share the same column
    for (int i = 0; i < r; i++)
    {
        if (board[i][c] == 'Q')
        {
            return 0;
        }
    }

    // return 0 if two queens share the same `` diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return 0;
        }
    }

    // return 0 if two queens share the same `/` diagonal
    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return 0;
        }
    }

    return 1;
}

void printSolution(char board[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void nQueen(char board[][N], int r)
{
    // if `N` queens are placed successfully in each row, print the solution
    if (r == N)
    {
        printSolution(board);
        return;
    }

    // place queen at every square in the current row `r`
    // and recur for each valid movement
    for (int i = 0; i < N; i++)
    {
        // if no two queens threaten each other
        if (isSafe(board, r, i))
        {
            // place queen on the current square
            board[r][i] = 'Q';

            // recur for the next row
            nQueen(board, r + 1);

            // if r+1 leads to no solution, backtrack and remove the queen from the current square
            board[r][i] = '-';
        }
    }
}

int main()
{
    // `board[][]` keeps track of the position of queens in the current configuration
    char board[N][N];

    // initialize `board[][]` by `-`
    memset(board, '-', sizeof(board));

    nQueen(board, 0);

    return 0;
}
/* Consider a rat placed at (0, 0) in a square matrix of order N * N. 
It has to reach the destination at (N - 1, N - 1). Find all possible 
paths that the rat can take to reach from source to destination.
Value 0 at a cell in the matrix represents that it is blocked and rat 
cannot move to it while value 1 at a cell in the matrix represents 
that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. */
#include <iostream>
using namespace std;

// Maze size
#define N 4

bool isSafe(int maze[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}

void printPath(int solution[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool solveMazeUtil(int maze[N][N], int x, int y, int solution[N][N])
{
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        solution[x][y] = 1;
        return true;
    }

    // if its safe to go to square
    if (isSafe(maze, x, y))
    {
        // check if current block is already part of solution path
        if (solution[x][y] == 1)
        {
            return false;
        }
        // mark current block as part of the solution
        solution[x][y] = 1;

        // move to next column and try again recursively
        if (solveMazeUtil(maze, x + 1, y, solution))
        {
            return true;
        }

        // or move to next row and try again recursively
        else if (solveMazeUtil(maze, x, y + 1, solution))
        {
            return true;
        }

        // or move to previous column and try again recursively
        else if (solveMazeUtil(maze, x - 1, y, solution))
        {
            return true;
        }

        // or move to previous row and try again recursively
        else if (solveMazeUtil(maze, x, y - 1, solution))
        {
            return true;
        }

        else
        {
            // otherwise, if rat hits a deadend, backtrack
            solution[x][y] = 0;
            return false;
        }
    }
    else
    {
        return false;
    }
}

/* 
    Time Complexity: O(2^(n^2)). 
                    The recursion can run upper-bound 2^(n^2) times.
    Space Complexity: O(n^2). 
                    Output matrix is required so an extra space of size n*n is needed.
 */
bool solveMaze(int maze[N][N])
{
    int solution[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            solution[i][j] = 0;
        }
    }

    if (!solveMazeUtil(maze, 0, 0, solution))
    {
        cout << "Rat can't reach the end of the maze";
        return false;
    }

    printPath(solution);
    return true;
}

int main()
{
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 1, 0},
                      {1, 0, 1, 1},
                      {0, 0, 0, 1}};

    solveMaze(maze);

    return 0;
}
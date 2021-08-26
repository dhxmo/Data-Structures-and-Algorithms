/* Given a matrix of size r*c. Traverse the matrix in spiral form. */

#include <iostream>
#include <vector>
using namespace std;

class SpiralTraverse
{
public:
    // Time Complexity - O(R*C)
    // Space Complexity - O(N)
    vector<int> subOptimal(vector<vector<int>> matrix, int rows, int cols)
    {
        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = cols - 1;

        vector<int> arr;

        while (top < bottom && left < right)
        {
            for (int i = left; i <= right; i++)
            {
                arr.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++)
            {
                arr.push_back(matrix[i][right]);
            }
            right--;

            if (top < bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    arr.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    arr.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return arr;
    }
};

int main()
{
    vector<vector<int>> vec{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    int rows = 4;
    int cols = 4;

    SpiralTraverse spiral;
    vector<int> arr = spiral.subOptimal(vec, rows, cols);
    for (int elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>

/* Time Complexity O(n^2) */
bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    std::unordered_map<int, int> map;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            map[matrix[i][j]]++;
        }
    }

    for (const auto &n : map)
    {
        if (n.first == target)
        {
            return true;
        }
    }
    return false;
}

/* https://leetcode.com/problems/search-a-2d-matrix/discuss/897152/C%2B%2B-Binary-Search-Solution-100-Time-~40-Space */

bool searchMatrixOp(std::vector<std::vector<int>> &m, int t)
{
    // pointless edge case we still have to consider
    if (!m.size() || !m[0].size())
        return false;
    // support variables
    int row, l = 0, r = m.size() - 1, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        // moving l up if needed
        if (m[mid].back() < t)
            l = mid + 1;
        // moving r down if needed
        else if (m[mid][0] > t)
            r = mid - 1;
        // we found our row!
        else
        {
            l = mid;
            break;
        };
    }
    // storing the value of the new found row
    row = l;
    // resetting l and r to run a binary search on the rows
    l = 0;
    r = m[0].size() - 1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        // moving l up if needed
        if (m[row][mid] < t)
            l = mid + 1;
        // moving r down if needed
        else if (m[row][mid] > t)
            r = mid - 1;
        // we found our value!
        else
            return true;
    }
    return false;
}

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 3, 5, 7},
                                            {10, 11, 16, 20},
                                            {23, 30, 34, 60}};

    int target = 10;

    if (searchMatrixOp(matrix, target))
    {
        std::cout << target << " present" << std::endl;
    }
    else
    {
        std::cout << target << " not present" << std::endl;
    }

    return 0;
}

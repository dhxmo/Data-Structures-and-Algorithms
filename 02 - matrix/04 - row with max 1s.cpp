/* 
Given a boolean 2D array of n x m dimensions where each row is sorted. 
Find the 0-based index of the first row that has the maximum number of 1's.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define r 4
#define c 4

/* 
brute force 
Time complexity: O(m * n)
Auxiliary Space: O(1)
*/
int rowWithMax1sBrute(bool arr[r][c])
{
    int count = 0, maxCount = 0, row = 0;

    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (arr[i][j] == 1)
                count++;
        }
        if (maxCount < count)
        {
            maxCount = count;
            row = i;
        }
    }

    return row;
}

/* 
use Binary Search to count of 1s in each row. We find the index of first 
instance of 1 in each row. The count of 1s will be equal to total number 
of columns minus the index of first 1.


Time Complexity: O(mLogn) where m is number of rows 
                            and n is number of columns in matrix.
 */
int firstIndexOf1(bool arr[], int low, int high)
{
    if (high >= low)
    {
        //get middle index
        int mid = (low + high) / 2;

        // check if element in the middle is 1
        if ((mid == 0 || arr[mid - 1] == 0) && arr[mid] == 1)
            return mid;

        // if element is 0, recur right side
        else if (arr[mid] == 0)
            return firstIndexOf1(arr, (mid + 1), high);

        // else recur on light side
        else
            return firstIndexOf1(arr, low, (mid - 1));
    }

    return -1;
}

int rowWithMax1sSubOp(bool arr[r][c])
{
    //initialize max value
    int row = 0, max = -1;

    // traverse row and count number of 1s
    int i, index;
    for (i = 0; i < r; i++)
    {
        index = firstIndexOf1(arr[i], 0, c - 1);

        if (index != -1 && c - index > max)
        {
            max = c - index;
            row = i;
        }
    }
    return row;
}

/* 
The time complexity is O(m+n), we go as far left as we came ahead in the first step.
 */
int rowWithMax1sOp(bool arr[r][c])
{
    int j = c - 1, row = 0;

    for (int i = 0; i < r; i++)
    {
        // check whether a row has more 1s than the previous one
        bool flag = false;

        // move left until a 0 is found
        while (j >= 0 && arr[i][j] == 1)
        {
            // update leftmost index seen so far
            j = j - 1;
            // present row has more 1s than previous
            flag = true;
        }

        // if present row has more 1s than the previous
        if (flag)
            // update index
            row = i;
    }

    if (row == 0 && arr[0][c - 1] == 0)
        return -1;

    return row;
}

int main()
{
    bool arr[r][c] = {{0, 1, 1, 1},
                      {0, 0, 1, 1},
                      {1, 1, 1, 1},
                      {0, 0, 0, 0}};

    cout << "Row with the most 1s(zero-indexed) = " << rowWithMax1sBrute(arr) << endl;

    cout << "Row with the most 1s(zero-indexed) = " << rowWithMax1sSubOp(arr) << endl;

    cout << "Row with the most 1s(zero-indexed) = " << rowWithMax1sOp(arr) << endl;

    return 0;
}
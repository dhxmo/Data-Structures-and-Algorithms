/* Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix. */

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100

/* 
binary search algorithm:

01 - First, we need to find the minimum and maximum elements from the matrix. The minimum and maximum can be easily found 
since the rows are sorted so we need to comapare with the first element of each row for minimum and last element of each row for maximum.

02 - After finding our min and max, we can apply binary search on this range. The mid element can be calculated and 
number of elements smaller or equal to mid can be calculated, we have used upper_bound() function for this.

03 - Based on the value of our counter, the min and max can be adjusted accordingly based on what we do for binary search.
 
        Time Complexity: O(32 * r * log(c)). The upper bound function will take log(c) time and is performed for each row. 
                        And since the numbers will be max of 32 bit, so binary search of numbers from min to max will be 
                        performed in at most 32 ( log2(2^32) = 32 ) operations. 
        Auxiliary Space : O(1) 
 */
int medianOp(int matrix[][MAX], int row, int col)
{
    int min = INT32_MAX, max = INT32_MIN;
    int median = (row * col + 1) / 2;
    int counter = 0;

    for (int i = 0; i < row; i++)
    {
        // find min element in sorted matrix
        if (matrix[i][0] < min)
            min = matrix[i][0];

        // find max element in sorted matrix
        if (matrix[i][col - 1] > max)
            max = matrix[i][col - 1];
    }

    while (min < max)
    {
        int mid = (max + min) / 2;
        counter = 0;

        // count of elements smaller than the mid
        for (int i = 0; i < row; i++)
            counter += upper_bound(matrix[i], matrix[i] + col, mid) - matrix[i];
        if (counter < median)
            min = mid + 1;
        else
            max = mid;
    }

    return min;
}

int main()
{
    int rows = 3, columns = 3;
    int arr[][MAX] = {{1, 3, 5},
                      {2, 6, 9},
                      {3, 6, 9}};

    cout << "Median: " << medianOp(arr, rows, columns) << endl;
    return 0;
}
/* Inversion Count: For an array, inversion count indicates how far 
(or close) the array is from being sorted. If array is already sorted 
then the inversion count is 0. If an array is sorted in the reverse 
order then the inversion count is the maximum. Formally, two elements 
a[i] and a[j] form an inversion if a[i] > a[j] and i < j. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class countInversions
{
public:
    // Time Complexity: O(n^2), Two nested loops are needed to traverse the array from start to end, so the Time complexity is O(n^2)
    // Space Complexity:O(1), No extra space is required.
    int subOptimal(int arr[], int size)
    {
        int count = 0;

        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    count++;
                }
            }
        }
        return count;
    }

    /* 
    Algorithm: 
    1. The idea is similar to merge sort, divide the array into two equal 
    or almost equal halves in each step until the base case is reached.
    
    2. Create a function merge that counts the number of inversions when two 
    halves of the array are merged, create two indices i and j, i is the index 
    for the first half, and j is an index of the second half. if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray 
    (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
    
    3. Create a recursive function to divide the array into halves and find the answer by summing the number of inversions is the first half, the number of inversion in the second half and the number of inversions by merging the two.
           
    4. The base case of recursion is when there is only one element in the given half.
            
    5. Print the answer

    Time Complexity: O(n log n), The algorithm used is divide and conquer, So in each level, one full array traversal is needed, and there are log n levels, so the time complexity is O(n log n).
    
    Space Complexity: O(n), Temporary array.
     */

    int merge(int arr[], int temp[], int left, int mid, int right)
    {
        int i, j, k;
        int inv_count = 0;

        // index for left side of array
        i = left;
        // index for right side of array
        j = mid;
        // index for merged temp array
        k = left;

        while (i <= mid - 1 && j <= right)
        {
            if (arr[i] <= arr[j])
            {
                // add to temp array from left side and move to next index
                temp[k++] = arr[i++];
            }
            else
            {
                // add to temp from right side and move to next index
                temp[k++] = arr[j++];

                // since array is sorted, the numbers after i as greater than j as well
                inv_count += mid - i;
            }
        }

        // copy remaining left array to temp
        while (i <= mid - 1)
        {
            temp[k++] = arr[i++];
        }
        // copy remaning right array to temp
        while (j <= right)
        {
            temp[k++] = arr[j++];
        }

        //copy temp to original array
        for (i = left; i <= right; i++)
        {
            arr[i] = temp[i];
        }

        return inv_count;
    }

    int mergeSort(int arr[], int temp[], int left, int right)
    {
        int mid, inv_count = 0;
        if (right > left)
        {
            mid = (right + left) / 2;

            /* total inversions will be the inversion in left, right and eventual merging */

            inv_count += mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid + 1, right);
            inv_count += merge(arr, temp, left, mid + 1, right);
        }

        return inv_count;
    }

    int optimal(int arr[], int size)
    {
        int temp[size];
        return mergeSort(arr, temp, 0, size - 1);
    }
};

int main()
{

    int arr[] = {2, 4, 1, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    countInversions sol;
    int subOpSolution = sol.subOptimal(arr, size);
    int opSolution = sol.optimal(arr, size);

    cout << subOpSolution << endl;
    cout << opSolution << endl;

    return 0;
}

/* 
    array -> {1 5 3 2 6 4}


    divide and conquer
    sort and split

    1 3 5       2 4 6
    i           j
                |
             mid index

if a[i] > a[j] -> count++ and j++
(since array sorted, inversion count = mid - i)
    i   j      inversion count      merged array    

    0   3              0                 1
    1   4              2                 1 2
    1   4              2                 1 2 3
    2   4              count++
    2   5              3                 1 2 3 4
    2   5              3                 1 2 3 4 5
    2   5              3                 1 2 3 4 5 6                 
 */
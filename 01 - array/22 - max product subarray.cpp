/* Given an array Arr[] that contains N integers (may be positive, negative or zero). 
Find the product of the maximum product subarray. */

#include <iostream>
using namespace std;

/* 
    Time Complexity: O(n²)
    Space Complexity: O(1)
 */
int maxProductSubOp(int arr[], int size)
{
    int maxProduct = INT32_MIN;
    for (int i = 0; i < size; i++)
    {
        int currentProduct = 1;
        for (int j = i; j < size; j++)
        {
            currentProduct *= arr[j];
        }
        maxProduct = max(maxProduct, currentProduct);
    }

    return maxProduct;
}

/* 
    Time Complexity: O(n)
    Space Complexity: O(1)
 */
int maxProductOp(int arr[], int size)
{
    int maxProduct = arr[0];
    int currMax = arr[0], currMin = arr[0];
    
    // iterate through the array
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < 0)
        {
            // multiplied by a negative element
            // the current maximum product becomes the new minimum product
            // and vice versa
            swap(currMax, currMin);
        }
        currMax = max(arr[i], currMax * arr[i]);
        currMin = min(arr[i], currMin * arr[i]);
        maxProduct = max(maxProduct, currMax);
    }
    return maxProduct;
}

int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum product in subarrays: " << maxProductSubOp(arr, n) << endl;

    cout << "Maximum product in subarrays: " << maxProductOp(arr, n) << endl;

    return 0;
}
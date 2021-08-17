/* Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify 
the height of each tower either by increasing or decreasing them by K only once. After modifying, 
height should be a non-negative integer. Find out what could be the possible minimum difference 
of the height of shortest and longest towers after you have modified each tower. */

#include <iostream>
#include <algorithm>
using namespace std;

int getMinDiff(int arr[], int n, int k);

int main()
{
    int arr[] = {3, 9, 12, 16, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << "Minimized maximum difference between the towers = " << getMinDiff(arr, n, k) << endl;
}

// time complexity - O(N*logN) | space complexity - O(N)
int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr+n);

    // initial minimum difference between towers
    int minDiff = arr[n - 1] - arr[0];

    // to minimize distance we add to the smallest and subtract from the largest
    int smallestTower = arr[0] + k;
    int largestTower = arr[n - 1] - k;

    int currSmallestTower, currLargestTower;

    for (int i = 0; i < n; i++)
    {
        // reduce i+1 tower and compare with previous smallest tower...
        currSmallestTower = min(smallestTower, arr[i + 1] - k);

        // increase i tower and compare with previous largest...
        currLargestTower = max(largestTower, arr[i] + k);

        // if smallest is negative (largest - smallest) will be positive and since we are looking for the minimum value
        if (currSmallestTower < 0) continue;

        //find diff between largest and smallest tower and comapre with initial minimum
        minDiff = min(minDiff, currLargestTower - currSmallestTower);
    }

    return minDiff;
}

#include <iostream>
using namespace std;

// int bruteForce(int arr[], int n);
int kadaneAlgo(int arr[], int n);

int main()
{
    int arr[] = {1, 2, -3, -2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << kadaneAlgo(arr, n) << endl;
}

// time complexity O(n^2)
// int bruteForce(int arr[], int n)
// {
//     int maxSum = INT32_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;

//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if (sum > maxSum)
//             {
//                 maxSum = sum;
//             }
//         }
//     }

//     return maxSum;
// }

// time complexity O(n) - space complexity - O(1)
int kadaneAlgo(int arr[], int n) {
    int maxSum = 0;
    int currSum = 0;

    for ( int i = 0; i < n; i++) {
        currSum = currSum + arr[i];

        if ( currSum > maxSum) {
            maxSum = currSum;
        }

        // if the chunk has too many neg numbers
        // set their total to zero before moving to next number
        if ( currSum < 0) {
            currSum = 0;
        }
    }

    return maxSum;
}
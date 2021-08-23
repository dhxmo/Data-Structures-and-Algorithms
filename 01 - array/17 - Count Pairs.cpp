/* Given an array of N integers, and an integer K, find the number of pairs of elements 
in the array whose sum is equal to K. */

#include <iostream>
#include <unordered_map>
using namespace std;

class countPairs
{
public:
    // Time Complexity - O(N^2)
    // Space Complexity - O(1)
    int subOptimal(int arr[], int size, int k)
    {
        int count = 0;

        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                int sum = arr[i] + arr[j];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }

    // Time Complexity - O(N)
    // Space Complexity - O(N)
    int optimal(int arr[], int size, int k)
    {
        int count = 0;
        unordered_map<int, int> map;

        for (int i = 0; i < size; i++)
        {
            int x = k - arr[i];

            // if the difference isn't found in hashmap, increase its frequency
            if (map[x] == 0)
            {
                map[arr[i]]++;
            }
            else
            {
                // add the difference's frequency to the hashmap
                map[arr[i]]++;
                // update count
                count += map[x];
            }
        }

        return count;
    }
};

int main()
{
    int k = 6;
    int arr[] = {1, 5, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countPairs cp;

    int subOpSol = cp.subOptimal(arr, n, k);
    cout << subOpSol << endl;

    int opSol = cp.optimal(arr, n, k);
    cout << opSol << endl;

    return 0;
}

/* 
    optimal solution iteration

    arr[] = {1, 5, 7, 1}

    k = 6

    i       arr[i]       x=k-arr[i]       map[x] (number, frequency)          count 
    0         1             5              (5, 1)                               0
    1         5             1              (1, 1), (5, 1)                       0
    2         7            -1              (-1, 1), (1, 1), (5, 1)              0
    3         1             5              (-1, 1), (1, 1), (5, 2)              2 ->return

 */
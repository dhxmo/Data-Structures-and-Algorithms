/* 
You are given an array prices where prices[i] is the price of a given 
stock on the ith day.You want to maximize your profit by choosing a single day to buy one stock 
and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.
 */

#include <iostream>
#include <algorithm>
using namespace std;

class maxDiff
{
public:
    // Time Complexity - O(N^2)
    // Space Complexity - O(1)
    int subOptimal(int arr[], int size)
    {
        int max = 0;
        int diff;

        for (int i = 1; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                diff = arr[j] - arr[i];

                if (diff > max)
                {
                    max = diff;
                }
            }
        }

        return max;
    }

    // Time Complexity - O(N)
    // Space Complexity - O(1)
    int optimal(int arr[], int size)
    {
        int maxProfit = 0;
        int currMin = arr[0];

        // as we iterate through the prices
        for (int i = 0; i < size; i++)
        {
            // save the minimum price of buying
            currMin = min(currMin, arr[i]);
            // find the profit for that day compared with the minimum buy ...
            int profit = arr[i] - currMin;
            // ... and compare against the max profit
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};

int main()
{
    int arr[] = {3, 5, 1, 7, 4, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    maxDiff md;
    int subOpSol = md.subOptimal(arr, n);
    int opSol = md.optimal(arr, n);

    cout << subOpSol << endl;
    cout << opSol << endl;

    return 0;
}
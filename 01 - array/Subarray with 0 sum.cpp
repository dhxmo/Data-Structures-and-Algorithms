/* Given an array of positive and negative numbers. 
Find if there is a subarray (of size at-least one) with 0 sum. */

#include <iostream>
#include <unordered_set>
using namespace std;

class SubArrayZeroSum
{
public:
    // Time Complexity - O(N^2)
    // Space Complexity - O(1)
    bool suboptimal(int arr[], int n)
    {
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;

            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum == 0)
                {
                    count++;
                }
            }
        }

        if (count > 0)
        {
            cout << "There exist subarrays with sum 0" << endl;
            return true;
        }
        else
        {
            cout << "There are no subarrays with sum 0" << endl;
            return false;
        }
    }

    // Time Complexity - O(N)
    // Space Complexity - O(N)
    bool optimal(int arr[], int n)
    {
        // declare hash and store sum
        unordered_set<int> hash;
        hash.insert(0);

        int sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            // check if sum already exists
            if (sum == 0 || hash.find(sum) != hash.end())
            {
                cout << "There exist subarrays with sum 0" << endl;
                return true;
            }

            //store sum in hash
            hash.insert(sum);
        }

        cout << "There are no subarrays with sum 0" << endl;
        return false;
    }
};

int main()
{
    int arr[] = {4, 7, -2, 3, 4, -5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    SubArrayZeroSum zeroSum;
    // int subOpSum = zeroSum.suboptimal(arr, n);
    // cout << subOpSum << endl;

    int opSum = zeroSum.optimal(arr, n);
    cout << opSum << endl;

    return 0;
}
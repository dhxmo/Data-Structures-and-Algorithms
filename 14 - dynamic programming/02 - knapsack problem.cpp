#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <climits>
using namespace std;

/*  
    Time Complexity: O(2^n) - As there are redundant subproblems.
    Auxiliary Space :O(1) -  As no extra data structure has been 
                            used for storing values. 
*/
int knapsackSubOp(int weight[], int knapsackCapacity, int values[], int n)
{
    // base case
    if (weight < 0)
        return INT16_MIN;
    if (n < 0 | weight == 0)
        return 0;

    // include -> current item in the knapsack and recur for the remaining items n-1 wih decreased capacity
    int include = values[n] + knapsackSubOp(weight, knapsackCapacity - weight[n], values, n - 1);

    // exclude -> current item excluded and recur for the remaining n-1 items
    int exclude = knapsackSubOp(weight, knapsackCapacity, values, n - 1);

    return max(include, exclude);
}

/* 
    Time Complexity: O(n*w)
    Auxiliary Space: O(n*w)
 */

// map to store solutions to subproblems
unordered_map<string, int> subProblems;
int knapsackOp(int weight[], int W, int values[], int n)
{
    // base case
    if (W < 0)
    {
        return INT16_MIN;
    }
    if (n < 0 || W == 0)
    {
        return 0;
    }

    // construct a unique map key from dynamic elements of the input
    string key = to_string(n) + "|" + to_string(W);

    // if the subproblem is seen for the first time, solve it and
    // store its result in a map
    if (subProblems.find(key) == subProblems.end())
    {
        // Case 1. Include current item `v[n]` in the knapsack and recur for
        // remaining items `n-1` with decreased capacity `W-w[n]`
        int include = values[n] + knapsackOp(weight, W - weight[n], values, n - 1);

        // Case 2. Exclude current item `v[n]` from the knapsack and recur for
        // remaining items `n-1`
        int exclude = knapsackOp(weight, W, values, n - 1);

        // assign the max value we get by including or excluding the current item
        subProblems[key] = max(include, exclude);
    }

    // return solution to the current subproblem
    return subProblems[key];
}

int main()
{
    int knapsackCapacity = 50;

    int values[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int n = sizeof(values) / sizeof(values[0]);

    cout << "Maximum total value in the knapsack: " << knapsackSubOp(weight, knapsackCapacity, values, n) << endl;

    cout << "Maximum total value in the knapsack: " << knapsackOp(weight, knapsackCapacity, values, n) << endl;

    return 0;
}
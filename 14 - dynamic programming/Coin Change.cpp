/* 
Given a value N, find the number of ways to make change for N cents, 
if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. */

#include <iostream>
using namespace std;

/* 
    Time Complexity: O(amount * coins.length)
    Space Complexity: O(amount)
*/

int waysToMakeChange(int coins[], int size, int amount)
{
    if (size == 0 || amount <= 0)
        return 0;

    // initialize to accomodate 0 sum
    int arr[size][amount + 1];

    // there's one way of making no change
    for (int i = 0; i < size; i++)
    {
        arr[i][0] = 1;
    }

    for (int i = 0; i < size; i++)
    {
        for (int sum = 1; sum <= amount; sum++)
        {
            int includingCurrentCoin = 0;
            int excludingCurrentCoin = 0;

            // only if coins is lesser than amount can
            // the current coin be included in the sum
            if (coins[i] <= sum)
            {
                // sum - coin[i]
                // amount minus the change -
                //   use the coin
                //      land on a previous sum, ie. to make 4 with {$1, $2}
                //          use the $2 coin or don't
                //          if I don't use it then there's 1 way to make this sum - 1 + 1 + 1 + 1
                //          if I do, then 2 + 2 = 4 and 1 + 1 + 2 = 4
                //          sum (4) - coins[i] (2) = 2 -> how much is left after we use $2 for the first time

                //          so there's 1 way to make sum 4 without $2
                //          and 2 ways to make sum 2 with $1 and $2
                //              so count to make sum 4 goes up to 3
                //                      ..so on and so forth
                includingCurrentCoin = arr[i][sum - coins[i]];
            }

            if (i > 0)
            {
                // i-1 to exclude the current coin
                // if we exclude the current coin then
                // the sum  has already been computed in the last row
                excludingCurrentCoin = arr[i - 1][sum];
            }

            arr[i][sum] = includingCurrentCoin + excludingCurrentCoin;
        }
    }

    return arr[size - 1][amount];
}

int main()
{
    int amount = 5;
    int coins[] = {1, 2, 3};
    int size = sizeof(coins) / sizeof(coins[0]);

    cout << "Number of ways to make $" << amount << " with ";

    for (auto elem : coins)
        cout << "$" << elem << " ";

    cout << "coins = " << waysToMakeChange(coins, size, amount) << endl;
}

/* 
    cutting down search space to exclude the min value to prevent permutations. 
    as we're interested in the combintions.

    coins = {1, 2, 3}

    total ways = including current coin + excluding current coin

    i -> index for coins[]

    for i = 1, we can't exclude 1 for sums 0 - 5, so 
           count = arr[i][j - coins[i]]

            0    1   2   3   4   5  j
        0   1    1   1   1   1   1    
        1   1          
        2   1
        i

    when i > 1
    count =    arr[i][j - coins[i]]    +    arr[i - 1][j]


            0    1   2   3   4   5  j
        0   1    1   1   1   1   1    
        1   1    1   2   2   3   3       
        2   1    1   2   3   4   5
        i
    
 */
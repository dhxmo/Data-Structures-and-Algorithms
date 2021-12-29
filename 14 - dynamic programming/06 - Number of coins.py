"""
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that 
you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. 
Find the minimum number of coins to make the change. If not possible to make change then return -1.
"""
import sys


class Min_coins_for_change:
    # top down approach
    # Time Complexity: O(Amount * no. of coins)
    # Space Complexity : O(Amount)
    def top_down(self, coins, remainder, cache):
        # base case
        if remainder < 0:
            return -1

        # The minimum coins needed to make change for 0 is 0
        if remainder == 0:
            return 0

        # return cached answer
        if cache[remainder] != 0:
            return cache[remainder]

        # initialize min as the max available number
        min_num = sys.maxsize

        # iterate over the given coins
        for coin in coins:
            # make change with the present coin and recurse with what's left
            change_res = self.top_down(coins, remainder - coin, cache)

            # increment min if change is possible and it's less than our current minimum count
            if(change_res >= 0 and change_res < min_num):
                min_num = 1 + change_res

        # if no answer is found return -1 else return the min count
        cache[remainder] = -1 if (min_num == sys.maxsize) else min_num

        return cache[remainder]

    def minCoins(self, coins, amount):
        if amount < 1:
            return 0

        return self.top_down(coins, amount, [0] * (amount + 1))

    # bottom up approach
    # Time Complexity: O(Amount * no. of coins)
    # Space Complexity : O(Amount)

    def bottom_up(self, coins, amount):
        dp = [amount + 1] * (amount + 1)

        # The minimum coins needed to make change for 0 is 0
        dp[0] = 0

        # for every subproblem from 1 to total amount
        for i in range(1, amount + 1):
            # for each given coin
            for j in range(0, len(coins)):
                # coin can only be used if it's less than the total
                if coins[j] <= i:
                    # either the coin gets used or
                    """subtract value of the coin from the total and evaluate subproblem
                    add one as we use the current coin"""
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1)

        return -1 if dp[amount] > amount else dp[amount]


if __name__ == '__main__':
    v = 30
    coins = [25, 10, 5]
    ob = Min_coins_for_change()
    ans_topDown = ob.minCoins(coins, v)
    print(f"Minimum number of coins needed to make ${v} from ", end="")
    for coin in coins:
        print(coin, end=" ")
    print(f"= {ans_topDown}")

    ans_bottomUp = ob.bottom_up(coins, v)
    print(f"Minimum number of coins needed to make ${v} from ", end="")
    for coin in coins:
        print(coin, end=" ")
    print(f"= {ans_bottomUp}")

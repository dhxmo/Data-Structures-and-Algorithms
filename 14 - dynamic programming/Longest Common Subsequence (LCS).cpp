/*
Given two sequences, find the length of longest subsequence
present in both of them. Both the strings are of uppercase.
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int dp[1001][1001];

int lcsUtil(int x, int y, string s1, string s2)
{
    // if string has reached the beginning, return
    if (x == -1 or y == -1)
        return 0;

    // memoize
    if (dp[x][y] != -1)
        return dp[x][y];

    // if character is the same in both strings
    // add 1 and recurse character 1 from the end
    if (s1[x] == s2[y])
        return dp[x][y] = 1 + lcsUtil(x - 1, y - 1, s1, s2);
    else
    {
        // recurse on each string with one less character
        int a = lcsUtil(x - 1, y, s1, s2);
        int b = lcsUtil(x, y - 1, s1, s2);

        // get max of the recursion
        return dp[x][y] = max(a, b);
    }
}

// Time Complexity: O(x*y)
int lcs(int x, int y, string s1, string s2)
{
    memset(dp, -1, sizeof(dp));
    // 0-indexed so reduce 1
    return lcsUtil(x - 1, y - 1, s1, s2);
}

int main()
{
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";

    cout << "Longest common subsequence of " << s1 << " and " << s2 << " is of length " << lcs(s1.length(), s2.length(), s1, s2) << endl;

    return 0;
}

/*
                    lcs("AXY", "AZX")
                        /            \
        lcs("AX", "AZX")             lcs("AXY, "AZ)
                /\                               /  \
lcs("A", "AZX")  lcs("AX", "AZ")    lcs("AX", "AZ")   lcs("AXY", "A")
                   /\                           /  \
    lcs("A", "AZ")  LCS("AX", "A")   lcs("A", "AZ") lcs("AX", "A")

memoeize recurrent patterns to DP
 */
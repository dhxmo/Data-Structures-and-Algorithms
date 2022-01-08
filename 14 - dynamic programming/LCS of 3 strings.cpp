/*
Given 3 strings A, B and C, the task is to
find the longest common sub-sequence in all three given sequences.

Expected Time Complexity: O(n1*n2*n3).
Expected Auxiliary Space: O(n1*n2*n3).

*/

#include <iostream>
using namespace std;

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    // instantiate a DP
    int dp[n1 + 1][n2 + 1][n3 + 1];

    // loop through the strings
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            for (int k = 0; k <= n3; k++)
            {
                // base case
                if (i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;

                // if equal length strings
                else if (A[i - 1] == B[j - 1] and A[i - 1] == C[k - 1])
                    // use previous sub-problem solution and add one
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    // recurse on each string with one less character and get max
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
            }
        }
    }
    return dp[n1][n2][n3];
}

int main()
{
    string A = "leetco", B = "leecoodet", C = "deleetco";
    cout << "The longest common subsequence of " << A << ", " << B << " & " << C << " is of length "
         << LCSof3(A, B, C, A.length(), B.length(), C.length()) << endl;
    return 0;
}
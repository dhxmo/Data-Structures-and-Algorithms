/* Given two integers n and r, find nCr.
Since the answer may be very large, calculate the answer modulo 10^9+7.*/
#include <iostream>
using namespace std;

/*
nCr = (n!) / (r! * (n-r)!)
 */

int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

/*
Time Complexity: O(2^N)
Space complexity: k
 */
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

/*
formula:
C(n,k) =    1  (if k = 0 or n = k)
            C(n-1, k-1) + C(n-1, k) for n>k>0

Time Complexity: O(n*k)
Auxiliary Space: O(n*k)
 */
int binomialCoefficientDP(int n, int r)
{
    int nCr[n + 1][r + 1];

    for (int i = 0; i <= n; i++)
    {
        /* min(i, r) - ThIs is because for the base condition we have to
        take min of i and k.Otherwise in some case u find the value of k
        become negative */
        for (int j = 0; j <= min(i, r); j++)
        {
            // base case
            if (j == 0 || j == i)
                nCr[i][j] = 1;
            else
                nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
        }
    }

    return nCr[n][r];
}

/*
Algorithm
Step 1 : Get the two inputs, the positive value of n and the non-positive value of k
which denotes the k-th binomial coefficient in the Binomial Expansion.
Step 2 : Allocate the array of size k + 1 with the value of 1 at 0-th index and rest with value 0.
Step 3 : Next, generating the sequence of pascal's triangle, with the first row containing single
element valued 1 which was already created in step 2.
Step 4 : Further next consecutive rows of pascal's triangle are computed from the previous row by
adding the two consecutive elements, but step 4 is to be carried out upto k-times, for enclosing n-value times.
Step 5 : Stop.

Time Complexity: O(n*k)
Auxiliary Space: O(k)
 */
int binomialCoefficientOp(int n, int k)
{
    // combinatios of n, k at a time, if k > n then no answer
    if (n < k)
        return 0;
    
    // C(3,0) givesthe same answer as C(3,3)
    // pascal tree structure
    if ((n - k) < k)
        k = n - k;

    long int mod = 10000000007;

    // initialize and populate dp table
    int nCr[k + 1];
    for (int i = 0; i < k + 1; i++)
        nCr[i] = 0;

    // C(n, 0) = 1
    nCr[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        // min(i,k) to prevent solutions 
        // for the mirrored side of the pascal triangle
        for (int j = min(i, k); j > 0; j--)
            nCr[j] = (nCr[j] + nCr[j - 1]) % mod;
    }
    
    // return final subproblem
    return nCr[k];
}

int main()
{
    int valueOfN = 3, valueOfR = 2;

    cout << "nCr: C(" << valueOfN << ", " << valueOfR << ")"
         << " = " << nCr(valueOfN, valueOfR) << endl;

    cout << "nCr: C(" << valueOfN << ", " << valueOfR << ")"
         << " = " << binomialCoefficientDP(valueOfN, valueOfR) << endl;

    cout << "nCr: C(" << valueOfN << ", " << valueOfR << ")"
         << " = " << binomialCoefficientOp(valueOfN, valueOfR) << endl;
    return 0;
}
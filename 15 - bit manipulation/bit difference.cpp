/* You are given two numbers A and B. The task is to count the
number of bits needed to be flipped to convert A to B. */

#include <iostream>
using namespace std;

/*
1  Initialize count: = 0
2  If integer n is not zero
    (a) Do bitwise & with (n-1) and assign the value back to n
        n: = n&(n-1)
    (b) Increment count by 1
    (c) go to step 2
3  Else return count

Time Complexity: O(set bits) [Brian Kerninghan's Algorithm]
Space Complexity: O(1)
 */
int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int bitDiff(int a, int b)
{
    // XOR returns 1 when input is 1 and 0. for 0,0 or 1,1 XOR returns 0
    return countSetBits(a ^ b);
}

int main()
{
    int a = 10;
    int b = 20;

    cout << bitDiff(a, b) << endl;
    return 0;
}
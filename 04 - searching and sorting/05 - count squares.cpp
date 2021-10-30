/* Consider a sample space S consisting of all perfect squares starting 
from 1, 4, 9 and so on. You are given a number N, you have to output 
the number of integers less than N in the sample space S. */

#include <iostream>
#include <math.h>
using namespace std;

int countSquares(int n)
{
    int count = 0, i = 1;

    while ((i * i) < n)
    {
        count++;
        i++;
    }
    return count;
}

int main()
{
    int n = 9;
    cout << "Number of perfect squares below " << n << " = "
         << countSquares(9) << endl;

    return 0;
}
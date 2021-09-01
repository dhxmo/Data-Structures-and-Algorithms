/* Compute the factorial of big numbers */

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int multiply(int x, int res[], int res_size);

/* Time Complexity: O(N^2) */
void factorial(int n)
{
    int res[MAX];

    // Initialize result
    res[0] = 1;
    int res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);

    cout << "Factorial of given number is \n";
    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
}

// This function multiplies x with the number represented by res[].
// res_size is size of res[] or number of digits in the number represented
// by res[].
int multiply(int x, int res[], int res_size)
{
    int carry = 0; // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i = 0; i < res_size; i++)
    {
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry = prod / 10;
    }

    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

// Optimized solution
// Time Complexity: O(N)

// Function to find the factorial of large number and return them in string format
string factorialOp(long long n)
{
    if (n > MAX)
    {
        cout << " Integer Overflow"
             << endl;
        return "";
    }

    long long counter;
    long double sum = 0;

    // Base case
    if (n == 0)
        return "1";

    // Calculate the sum of logarithmic values
    for (counter = 1; counter <= n;
         counter++)
    {
        sum = sum + log(counter);
    }

    // Number becomes too big to hold in unsigned long integers.
    // Answer is sometimes under estimated due to floating point
    // operations so round() is used
    string result = to_string(round(exp(sum)));

    return result;
}

// Driver code
int main()
{
    clock_t tStart = clock();
    string str;
    str = factorialOp(100);
    cout << "The factorial is: "
         << str << endl;

    // Calculates the time taken by the algorithm to execute
    cout << "Time taken: " << setprecision(10)
         << ((double)(clock() - tStart) / CLOCKS_PER_SEC)
         << " s" << endl;

    factorial(100);
}

/* 
Code from geekForgeeks

https://www.geeksforgeeks.org/factorial-large-number/

https://www.geeksforgeeks.org/factorial-of-large-numbers-using-logarithmic-identity/

 */
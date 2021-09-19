#include <iostream>

int int_to_bits(int k)
{
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * (int_to_bits(k / 2))));
}

int sum(int bits)
{
    int sum = 0;

    while (bits > 0)
    {

        int digit = bits % 10;
        sum += digit;

        bits /= 10;
    }

    return sum;
}

// Time Complexity - O(1)
int sum_of_bits(int N)
{
    return __builtin_popcount(N);
}

int main()
{
    int x = 8;

    int bits = int_to_bits(x);
    std::cout << "Sum of 1 bits in " << x << " = " << sum(bits) << std::endl;

    // std::cout << "Sum of 1 bits in " << x << " = " << sum_of_bits(x) << std::endl;

    return 0;
}
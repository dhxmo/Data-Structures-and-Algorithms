/* Given an array Arr of N positive integers. Your task find the elements 
whose value is equal to that of its index value. */

#include <iostream>

int main()
{
    int arr[] = {15, 2, 45, 12, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int res;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
            res = arr[i];
    }

    if (res)
        std::cout << res << std::endl;
    else
        std::cout << "No elements exist" << std::endl;

    return 0;
}
// rearrange negative values (order not necessary)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void rearrange(int arr[], int n)
{
    // keep one pointer on any number less than 0
    int j = 0;

    // other pointer iterates through the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
                swap(arr[i], arr[j]);
            // pointer goes up only if number satisfies the condition we want to track
            j++;
        }
    }
}

int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, n);

    for (int elem : arr)
    {
        cout << elem << " ";
    }
}
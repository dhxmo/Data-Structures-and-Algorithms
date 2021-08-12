#include <iostream>
using namespace std;

int minimum(int arr[], int size)
{
    int min;
    min = arr[0];

    for (int i = 0; i < size; i++)
    {
        min < arr[i] ? min : min = arr[i];
    }

    return min;
}

int maximum(int arr[], int size)
{
    int max;
    max = arr[0];

    for (int i = 0; i < size; i++)
    {
        max > arr[i] ? max : max = arr[i];
    }

    return max;
}

int main()
{
    int arr[] = {102, 24522, 223, 42423453, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number in the array = " << minimum(arr, size) << "\n";
    cout << "Maximum number in the array = " << maximum(arr, size) << "\n";
}
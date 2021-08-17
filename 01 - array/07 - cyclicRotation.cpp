#include <iostream>
using namespace std;

void cyclic(int arr[], int n);

int main()
{
    int arr[] = {9, 8, 7, 6, 4, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cyclic(arr, n);

    for (int elem : arr)
    {
        cout << elem << " ";
    }
}

void cyclic(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[i - 1]);
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* time complexity: O(n^2)
auxiliary soace: O(1)
Insertion sort is used when number of elements is small. 
It can also be useful when input array is almost sorted, 
only few elements are misplaced in complete big array. */
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {12, 9, 56, 8794, 564};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    for (auto letter : arr)
        cout << letter << " ";
    return 0;
}
/*  Given an array of N elements. The task is to build a Binary Heap from the given array.
The heap can be either Max Heap or Min Heap.
*/

#include <iostream>
#include <algorithm>
using namespace std;

/* 
Time Complexity: Heapify a single node takes O(log N) time complexity where N is the total number of Nodes. 
Therefore, building the entire Heap will take N heapify operations and the total time complexity will be O(N*logN).
*/
void heapify(int arr[], int n, int i)
{
    // define largest number as the root
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // left child larger than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // right child larger than root
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // if largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    // index of last leaf's parent node
    int start = (n / 2) - 1;

    // reverse level order traversal and heapify each node
    for (int i = start; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void printHeap(int arr[], int n)
{
    cout << "Heapified array: \n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMaxHeap(arr, n);
    printHeap(arr, n);

    return 0;
}
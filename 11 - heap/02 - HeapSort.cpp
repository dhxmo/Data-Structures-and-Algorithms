#include <iostream>
#include <algorithm>
using namespace std;

/* Heap Sort Algorithm for sorting in increasing order: 
1. Build a max heap from the input data. 
2. At this point, the largest item is stored at the root of the heap. 
Replace it with the last item of the heap followed by reducing the 
size of heap by 1. Finally, heapify the root of the tree. 
3. Repeat step 2 while the size of the heap is greater than 1. 

Time Complexity: Time complexity of heapify is O(Logn). 
Time complexity of createAndBuildHeap() is O(n).
Overall time complexity of Heap Sort is O(nLogn).
*/
void heapify(int arr[], int size, int root)
{
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != root)
    {
        swap(arr[root], arr[smallest]);
        // recursively heapify affected sub-tree
        heapify(arr, size, smallest);
    }
}

void heapSort(int arr[], int size)
{
    // build heap - rearrange array
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {23, 53, 3, 4, 643, 11121};
    int size = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, size);

    cout << "Sorted array is: ";
    printArray(arr, size);
}

/* 
Input data: 4, 10, 3, 5, 1
         4(0)
        /   \
     10(1)   3(2)
    /   \
 5(3)    1(4)

The numbers in bracket represent the indices in the array 
representation of data.

Applying heapify procedure to index 1:
         4(0)
        /   \
    10(1)    3(2)
    /   \
5(3)    1(4)

Applying heapify procedure to index 0:
        10(0)
        /  \
     5(1)  3(2)
    /   \
 4(3)    1(4)

The heapify procedure calls itself recursively to build heap
 in top down manner.

 */
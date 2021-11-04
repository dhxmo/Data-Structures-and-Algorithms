/* 
Given an array Arr of N positive integers, find K largest elements from the array.  
The output elements should be printed in decreasing order.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// Time complexity: O(n*log(n))
void kLargestSubOp(int arr[], int n, int k)
{
    // sort in decreasing order
    sort(arr, arr + n, greater<int>());

    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}

// using min heap
//  Time complexity - O(k*log(k) + (n-k)*log(k))

// Min Heap Class
// arr holds reference to an integer
// array size indicate the number of
// elements in Min Heap
class MinHeap
{

    int size;
    int *arr;

public:
    // Constructor to initialize the size and arr
    MinHeap(int size, int input[]);

    // Min Heapify function, that assumes that
    // 2*i+1 and 2*i+2 are min heap and fix the
    // heap property for i.
    void heapify(int i);

    // Build the min heap, by calling heapify
    // for all non-leaf nodes.
    void buildHeap();
};

// Constructor to initialize data
// members and creating mean heap
MinHeap::MinHeap(int size, int input[])
{
    // Initializing arr and size

    this->size = size;
    this->arr = input;

    // Building the Min Heap
    buildHeap();
}

// Min Heapify function, that assumes
// 2*i+1 and 2*i+2 are min heap and
// fix min heap property for i

void MinHeap::heapify(int i)
{
    // If Leaf Node, Simply return
    if (i >= size / 2)
        return;

    // variable to store the smallest element
    // index out of i, 2*i+1 and 2*i+2
    int smallest;

    // Index of left node
    int left = 2 * i + 1;

    // Index of right node
    int right = 2 * i + 2;

    // Select minimum from left node and
    // current node i, and store the minimum
    // index in smallest variable
    smallest = arr[left] < arr[i] ? left : i;

    // If right child exist, compare and
    // update the smallest variable
    if (right < size)
        smallest = arr[right] < arr[smallest]
                       ? right
                       : smallest;

    // If Node i violates the min heap
    // property, swap  current node i with
    // smallest to fix the min-heap property
    // and recursively call heapify for node smallest.
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(smallest);
    }
}

// Build Min Heap
void MinHeap::buildHeap()
{
    // Calling Heapify for all non leaf nodes
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(i);
    }
}

void firstKElementsMinHeap(int arr[], int size, int k)
{
    // Creating Min Heap for given
    // array with only k elements
    MinHeap *m = new MinHeap(k, arr);

    // Loop For each element in array
    // after the kth element
    for (int i = k; i < size; i++)
    {

        // if current element is smaller
        // than minimum element, do nothing
        // and continue to next element
        if (arr[0] > arr[i])
            continue;

        // Otherwise Change minimum element to
        // current element, and call heapify to
        // restore the heap property
        else
        {
            arr[0] = arr[i];
            m->heapify(0);
        }
    }
    // Now min heap contains k maximum
    // elements, Iterate and print
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n1 = 5, k1 = 2;
    int arr1[] = {12, 5, 787, 1, 23};

    cout << k1 << " largest elements in the array are: ";
    kLargestSubOp(arr1, n1, k1);
    cout << endl;

    int arr2[] = {11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45};
    int n2 = sizeof(arr2) / sizeof(arr2[0]), k2 = 4;

    cout << k2 << " largest elements in the array are: ";
    firstKElementsMinHeap(arr2, n2, k2);
    cout << endl;

    return 0;
}

/* Attributed to  https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/*/
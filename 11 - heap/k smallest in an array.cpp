/* 
Given an array and a number k where k is smaller than the size of the 
array, we need to find the k’th smallest element in the given array. 
It is given that all array elements are distinct. 
*/

#include <iostream>
#include <algorithm>
using namespace std;

/* 
Time Complexity: O(NlogN)
 */
int kSmallestSubOp(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return arr[k - 1];
}

/* 
Time complexity: O(k + (n-k)*Logk) 

TODO: Implementation not ideal for duplicates in the array. fix that.
*/
class MaxHeap
{
    int *hArr, capacity, heap_size;

public:
    MaxHeap(int arr[], int size); // constructor
    void maxHeapify(int index);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i) + 1; }
    int right(int i) { return (2 * i) + 2; }
    int getIndex(int i) { return hArr[i]; }
};

MaxHeap::MaxHeap(int arr[], int size)
{
    hArr = arr;
    heap_size = size;
    int i = (heap_size - 1) / 2;
    while (i >= 0)
    {
        maxHeapify(i);
        i--;
    }
}

void MaxHeap::maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l <= heap_size && hArr[l] > hArr[largest])
        largest = l;
    if (r <= heap_size && hArr[r] > hArr[largest])
        largest = r;
    if (largest != i)
    {
        swap(hArr[i], hArr[largest]);
        maxHeapify(largest);
    }
}

int kSmallestOp(int arr[], int n, int k)
{
    MaxHeap mh(arr, k);
    return mh.getIndex(k - 1);
}

int main()
{
    int arr[] = {7, 0, 25, 6, 16, 17, 0};
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is " << kSmallestSubOp(arr, n, k) << endl;

    cout << "K'th smallest element is " << kSmallestOp(arr, n, k) << endl;

    return 0;
}
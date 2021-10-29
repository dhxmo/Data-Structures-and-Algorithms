/* Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is 
sorted in non-decreasing order. Merge the two arrays into one sorted array in 
non-decreasing order without using any extra space. 

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9

*/

#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr1[], int size1, int arr2[], int size2);

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {0, 2, 6, 8, 9};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    merge(arr1, size1, arr2, size2);

    cout << "Merged array : ";
    for (int elem : arr1)
    {
        cout << elem << " ";
    }
    for (int elem : arr2)
    {
        cout << elem << " ";
    }
    cout << endl;
}

// time complexity - O((n+m)*log(n+m))  |  Space complexity - O(1)
void merge(int arr1[], int size1, int arr2[], int size2)
{
    int i = 0, j = 0, k = size1 - 1;

    while (i <= k && j < size2)
    {
        if (arr1[i] < arr2[j])
            i++;
        else
        {
            swap(arr2[j++], arr1[k--]);
        }
    }

    sort(arr1, arr1 + size1);
    sort(arr2, arr2 + size2);
}
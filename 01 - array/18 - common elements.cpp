/* Given three arrays sorted in increasing order. 
Find the elements that are common in all three arrays. */

#include <iostream>
#include <unordered_map>
#include <iterator>
using namespace std;

class commonElem
{
public:
    // Time Complexity : O(N1 + N2 + N3)
    // Space Complexity : O(1)
    int optimal(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3)
    {
        int i = 0, j = 0, k = 0;

        while (i < size1 && j < size2 && k < size3)
        {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
            {
                cout << arr1[i] << " ";
                i++;
                j++;
                k++;
            }
            else if (arr1[i] < arr2[j])
            {
                i++;
            }
            else if (arr2[j] < arr3[k])
            {
                j++;
            }
            else
            {
                k++;
            }
        }

        return 0;
    }
};

int main()
{
    int arr1[] = {1, 5, 10, 20, 40, 80};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {6, 7, 20, 80, 100};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    commonElem ce;

    cout << "Array 1: ";
    for (int elem : arr1)
    {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Array 2: ";
    for (int elem : arr2)
    {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Array 3: ";
    for (int elem : arr3)
    {
        cout << elem << " ";
    }
    cout << endl;

    cout << "The common elements between the arrays: ";
    int subOpSol = ce.optimal(arr1, size1, arr2, size2, arr3, size3);

    cout << endl;
}
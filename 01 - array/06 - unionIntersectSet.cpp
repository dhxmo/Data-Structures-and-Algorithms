#include <bits/stdc++.h>
using namespace std;

int unionArr(int arr1[], int m, int arr2[], int n, unordered_set<int> finalUnion);

int intersectArr(int arr1[], int m, int arr2[], int n);

int main()
{
    int arr1[] = {1, 2, 4, 5, 6};
    int m = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 3, 5, 7};
    int n = sizeof(arr2) / sizeof(arr2[0]);

    // define unordered set
    unordered_set<int> finalUnion;

    // union of arrays
    cout << "Size of union set = " << unionArr(arr1, m, arr2, n, finalUnion) << endl;

    cout << "Size of intersect set = " << intersectArr(arr1, m, arr2, n) << endl;
}

int unionArr(int arr1[], int m, int arr2[], int n, unordered_set<int> finalUnion)
{
    int i = 0;
    int j = 0;

    // iterate over array
    while (i < m)
    {
        //insert number into a set
        finalUnion.insert(arr1[i++]);
    }

    while (j < n)
    {
        finalUnion.insert(arr2[j++]);
    }

    // list of all available elements in set - get size
    return finalUnion.size();
}

int intersectArr(int arr1[], int m, int arr2[], int n)
{
    int i = 0, j = 0;
    vector<int> intersect;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            intersect.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return intersect.size();
}
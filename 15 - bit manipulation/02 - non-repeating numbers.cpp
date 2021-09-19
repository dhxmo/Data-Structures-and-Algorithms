#include <iostream>
#include <unordered_map>
using namespace std;

void nonRepeats(int arr[], int size, int n)
{
    unordered_map<int, int> map;
    // insert to hash table
    for (int i = 0; i < size; i++)
    {
        map[arr[i]]++;
    }

    // traverse and find element with count 1
    for (auto i : map)
    {
        if (i.second == 1)
            cout << i.first << " ";
    }
}

int main()
{

    int n = 2;
    int arr[] = {1, 2, 3, 2, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Non repeating number in the array: ";
    nonRepeats(arr, size, n);
    cout << endl;

    return 0;
}
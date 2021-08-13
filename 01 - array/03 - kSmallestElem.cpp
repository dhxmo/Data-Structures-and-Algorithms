#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right], pIndex = left;

    for (int i = left; i < right; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[pIndex], arr[right]);
    return pIndex;
}

int kSmallest(vector<int> arr, int left, int right, int k)
{
    int p = partition(arr, left, right);

    // kth on partition
    if (p == k)
    {
        return arr[p];
    }
    // partition lower than k
    else if (p < k)
    {
        return kSmallest(arr, p + 1, right, k);
    }
    // partition greater than k
    else
    {
        return kSmallest(arr, left, p - 1, k);
    }
}

int main()
{
    int k = 2;

    vector<int> arr = {7, 3, 76, 3, 31, 64, 1, 8, 53, 70};
    sort(arr.begin(), arr.end());
    cout << "Kth smallest: " << kSmallest(arr, 0, arr.size() - 1, k - 1) << "\n";
}
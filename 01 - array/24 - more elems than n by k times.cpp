#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* 
    Time Complexity: O(n)
    Auxiliary Space: O(n)
*/
void countElems(vector<int> arr, int n, int k)
{
    // declare unordered_map and resulting vector
    unordered_map<int, int> umap;
    vector<int> res;
    int times = n / k;

    // iterate over array and update map
    for (auto elem : arr)
    {
        umap[elem]++;
    }

    // iterate over map and find elemets that were updated more than the n/k times
    for (auto it : umap)
    {
        if (it.second > times)
        {
            res.push_back(it.first);
        }
    }

    // print result
    cout << "The elements that appear more than " << n / k << " times in the given array: ";
    for (auto elem : res)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {3, 1, 2, 2, 1, 2, 3, 3};
    int k = 4;
    int n = arr.size();

    countElems(arr, n, k);

    return 0;
}
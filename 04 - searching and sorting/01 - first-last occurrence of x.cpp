#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = arr.size();
    int x = 5;

    int i = 0;
    while (i < n && arr[i] != x)
    {
        i++;
    }

    int j = n - 1;
    while (j > 0 && arr[j] != x)
    {
        j--;
    }

    cout << "First occurrence of " << x << " : " << i << endl;
    cout << "Last occurrence of " << x << " : " << j << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class FirstLast
{
public:
    int firstLast(vector<int> &arr, int size, int x)
    {
        int i = 0;
        while (i < size && arr[i] != x)
        {
            i++;
        }

        int j = size - 1;
        while (j > 0 && arr[j] != x)
        {
            j--;
        }

        cout << "First occurrence of " << x << " : " << i << endl;
        cout << "Last occurrence of " << x << " : " << j << endl;

        return 0;
    }
};

int main()
{
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = arr.size();
    int x = 5;

    FirstLast fl;
    fl.firstLast(arr, n, x);

    return 0;
}